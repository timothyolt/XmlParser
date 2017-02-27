// Copyright 2017 Timothy Oltjenbruns.

#include <algorithm>
#include <vector>
#include <sstream>
#include "XmlBuilder.hpp"

XmlBuilder::XmlBuilder()
    : root(XmlNode("xml")), cursor(&root), cursorOpen(false), attributeOpen(false) {}

bool XmlBuilder::valid() {
  return !(cursorOpen || attributeOpen);
}

XmlNode &XmlBuilder::get() {
  if (cursorOpen || attributeOpen)
    throw XmlBuilder::XmlParseException();
  if (root.getChildren().size() > 1)
    throw XmlBuilder::XmlParseException();
  return root.getChildren().front();
}

std::istream &XmlBuilder::build(std::istream &stream) {
  while (stream >> *this) continue;
  return stream;
}

std::istream &operator>>(std::istream &stream, XmlBuilder &builder) {
  std::string buffer;
  stream >> buffer;
  if (buffer.length() == 0) return stream;
  switch (buffer[0]) {
    case '<': {
      if (buffer.length() == 1)  // node does not accept whitespace between < and name or </ and name
        throw XmlBuilder::XmlParseException();
      std::string::size_type closePos(buffer.find_first_of('/', 2));
      std::string::size_type endPos(std::min(closePos, buffer.find_first_of('>')));
      if (buffer[1] == '/')  // finish node, no more children, move cursor
        builder.finishNode(buffer.substr(2, endPos - 2));
      else {
        // start node, start reading attributes
        std::string name(buffer.substr(1, endPos - 1));
        builder.startNode(name);
        if (endPos != std::string::npos)
          builder.finishNodeHeader();
        if (closePos != std::string::npos)
          builder.finishNode(name);
      }
    } break;
    default: {
      // begin new attribute with given key
      std::string::size_type assignmentPos(buffer.find_first_of('='));
      builder.startAttribute(buffer.substr(0, assignmentPos));
      if (assignmentPos == std::string::npos) break;
    }
    case '=': {  // hit when whitespace exists between the attribute key and the assignment operator
      // flag attribute that the assignment operator was found
      std::string::size_type valuePos(buffer.find_first_of('"'));
      builder.flagAttribute();
      if (valuePos == std::string::npos) break;
      buffer = buffer.substr(valuePos);
    }
    case '"': {  // hit when whitespace exists between the assignment operator and the value
      // begin value, read until end quote
      builder.readAttributeValue(stream, buffer.substr(1));
      if (buffer.find_first_of('>') == std::string::npos) break;
    }
    case '/':
    case '>': {
      // begin reading children, no more attributes
      builder.finishNodeHeader();
      if (buffer.find_first_of('/') == std::string::npos) break;
      // finish node, it has no children, move cursor
      builder.finishNode(builder.cursor->getName());
    } break;
  }
  return stream;
}

void XmlBuilder::startNode(std::string name) {
  if (cursorOpen)  // make sure the cursor is not open
    throw XmlBuilder::XmlParseException();
  cursor->getChildren().emplace_back(name, cursor);
  cursor = &cursor->getChildren().back();
  cursorOpen = true;
  return;
}

void XmlBuilder::finishNodeHeader() {
  if (!cursorOpen || attributeOpen)  // make sure the cursor is actually open
    throw XmlBuilder::XmlParseException();
  cursorOpen = false;
  return;
}

void XmlBuilder::finishNode(std::string name) {
  // check node close tags for consistency
  if (name.compare(cursor->getName()) != 0)
    throw XmlBuilder::XmlParseException();
  // make sure the node has a parent
  if (cursor->getParent() == nullptr)
    throw XmlBuilder::XmlParseException();
  cursor = cursor->getParent();
  return;
}

void XmlBuilder::startAttribute(std::string key) {
  if (!cursorOpen || attributeOpen)  // make sure the cursor should accept attributes
    throw XmlBuilder::XmlParseException();
  cursor->getAttributes().emplace_back(key, "");
  attributeOpen = true;
  return;
}

void XmlBuilder::flagAttribute() {
  if (!cursorOpen)  // make sure the cursor should accept attributes
    throw XmlBuilder::XmlParseException();
  // make sure that the previous attribute shouldS be flagged
  if (cursor->getAttributes().size() == 0
      || !cursor->getAttributes().back().getValue().empty())
    throw XmlBuilder::XmlParseException();
  cursor->getAttributes().back().setValue("=");
  return;
}

void XmlBuilder::readAttributeValue(std::istream &stream, std::string value) {
  if (!cursorOpen)  // make sure the cursor should accept attributes
    throw XmlBuilder::XmlParseException();
  // make sure that the previous attribute is ready for value assignment
  if (cursor->getAttributes().size() == 0
      || cursor->getAttributes().back().getValue().compare("=") != 0)
    throw XmlBuilder::XmlParseException();
  // empty value
  if (value.size() < 2) {
    // TODO(timothyolt): broken
    cursor->getAttributes().back().setValue("");
    finishAttribute();
    return;
  }
  // handle values with no spaces (and empty values without tailing whitespace)
  std::string::size_type lastQuotePos(value.find_last_of('"'));
  if (lastQuotePos != std::string::npos && (lastQuotePos == 0 || value[lastQuotePos - 1] != '\\')) {
    cursor->getAttributes().back().setValue(value.substr(0, lastQuotePos));
    finishAttribute();
    return;
  }
  // copy stream into a string until
  char c(0);
  while (!stream.eof()) {
    stream.get(c);
    // abort before adding quote to value
    if (c == '"') break;
    // escape sequences
    if (c == '\\') {
      stream.get(c);
      switch (c) {
        case '\\':
        case '"':
          value += c;
          break;
        case 'n': value += '\n'; break;
        case 't': value += '\t'; break;
        default:
          throw XmlBuilder::XmlParseException();
      }
    }
    // strip out newlines and tabs
    if (c != '\n' && c != '\t')
      value += c;
  }
  cursor->getAttributes().back().setValue(value);
  finishAttribute();
  return;
}

void XmlBuilder::finishAttribute() {
  // check last attribute for completion
  if (!attributeOpen)
    throw XmlBuilder::XmlParseException();
  attributeOpen = false;
  return;
}
