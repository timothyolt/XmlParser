// Copyright 2017 Timothy Oltjenbruns.

#include <vector>
#include <sstream>
#include "XmlBuilder.hpp"

XmlBuilder::XmlBuilder()
    : root(XmlNode("xml")), cursor(&root), cursorOpen(false) {}

void XmlBuilder::reset() {
  root.setChildren(std::vector<XmlNode>());
  cursorOpen = false;
  return;
}

// TODO(timothyolt): GetXml function that ensures a valid tree

// TODO(timothyolt): write looper classes for console, files, stringstream, whatever else

std::istream &operator>>(std::istream &stream, XmlBuilder &builder) {
  std::string buffer;
  stream >> buffer;
  if (buffer.length() == 0) return stream;
  switch (buffer[0]) {
    case '<':
      if (buffer.length() == 1)  // node does not accept whitespace between < and name or </ and name
        throw XmlBuilder::XmlParseException();
      if (buffer[1] != '/')  // start node, start reading attributes
        builder.startNode(buffer.substr(1));
      else  // finish node, no more children, move cursor
        builder.finishNode(buffer.substr(2));
      break;
    case '/':  // finish node, it has no children, move cursor
      builder.finishNodeHeader();
      builder.finishNode(builder.cursor->getName());
      break;
    case '>': builder.finishNodeHeader(); break;  // begin reading children, no more attributes
    default:
      // begin new attribute with given key
      std::string::size_type assignmentPos(buffer.find("=", 0));
      builder.startAttribute(buffer.substr(0, assignmentPos));
      if (assignmentPos == std::string::npos) break;
    case '=':  // hit when whitespace exists between the attribute key and the assignment operator
      // flag attribute that the assignment operator was found
      std::string::size_type valuePos(buffer.find("\"", 0));
      builder.flagAttribute();
      if (valuePos == std::string::npos) break;
      buffer = buffer.substr(valuePos);
    case '"':  // hit when whitespace exists between the assignment operator and the value
      // begin value, read until end quote
      builder.readAttributeValue(stream, buffer);
      break;
  }
  return stream;
}

void XmlBuilder::startNode(std::string name) {
  cursor->getChildren().emplace_back(name);
  cursor = &cursor->getChildren().back();
  cursorOpen = true;
  return;
}

void XmlBuilder::finishNodeHeader() {
  if (!cursorOpen)  // make sure the cursor is actually open
    throw XmlBuilder::XmlParseException();
  cursorOpen = false;
  return;
}

void XmlBuilder::finishNode(std::string name) {
  if (name.compare(cursor->getName()) != 0)
    throw XmlBuilder::XmlParseException();

  return;
}

void XmlBuilder::startAttribute(std::string key) {
  if (!cursorOpen)  // make sure the cursor should accept attributes
    throw XmlBuilder::XmlParseException();
  // make sure that the previous attribute, if any, was properly finished
  if (cursor->getAttributes().size() > 0 && (
          !cursor->getAttributes().back().getValue().empty()
      ||  cursor->getAttributes().back().getValue().compare("=") == 0))
    throw XmlBuilder::XmlParseException();
  cursor->getAttributes().emplace_back(key);
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

void XmlBuilder::readAttributeValue(std::istream &stream, std::string &buffer) {
  if (!cursorOpen)  // make sure the cursor should accept attributes
    throw XmlBuilder::XmlParseException();
  // make sure that the previous attribute is ready for value assignment
  if (cursor->getAttributes().size() == 0
      || cursor->getAttributes().back().getValue().compare("=") != 0)
    throw XmlBuilder::XmlParseException();
  std::stringstream outStream(buffer);
  // TODO(timothyolt): read from buffer until either the stream ends (throw exception) or an end quote is found
  return;
}

void XmlBuilder::finishAttribute() {
  // check last attribute for completion
  if (cursor->getAttributes().size() > 0
      && cursor->getAttributes().back().getValue().compare("=") == 0)
    throw XmlBuilder::XmlParseException();
  return;
}
