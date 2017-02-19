// Copyright 2017 Timothy Oltjenbruns.

#include <vector>
#include <sstream>
#include "XmlBuilder.hpp"

void XmlBuilder::startAttribute(std::string key) {

}

void XmlBuilder::flagAttribute() {
  // there is whitespace between the attribute key and the assignment operator
  // make sure that the previous attribute shouldS be flagged
  if (cursor->getAttributes().size() == 0
      || !cursor->getAttributes().back().getValue().empty())
    throw XmlBuilder::XmlParseException();
  cursor->getAttributes().back().setValue("=");
  return;
}

void XmlBuilder::readQuotedValue(std::istream &stream, std::string &buffer) {
  std::stringstream outStream(buffer);
  // there is whitespace between the assignment operator and the value
  // make sure that the previous attribute is ready for value assignment
  if (cursor->getAttributes().size() == 0
      || cursor->getAttributes().back().getValue().compare("=") != 0)
    throw XmlBuilder::XmlParseException();
  return;
}

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
  switch (buffer[0]) {
    case '<':  // new tag
      switch (buffer[1]) {
        case '/': break;  // closing tag, no attributes, move cursor
        default: break;  // open tag, begin reading attributes
      }
      break;
    case '/': break;  // end tag, tag has no children, move cursor
    default:  // read attribute segment
      if (!builder.cursorOpen)  // make sure the cursor should accept attributes
        throw XmlBuilder::XmlParseException();
      std::string::size_type assignmentPos(buffer.find("=", 0));
      std::string::size_type valuePos(buffer.find("\"", 0));
      switch (buffer[0]) {
        default:  // begin new attribute with given name
          builder.startAttribute(buffer.substr(0, assignmentPos));
          if (assignmentPos == std::string::npos) break;
        case '=':  // flag attribute that the assignment operator was found
          builder.flagAttribute();
          if (valuePos == std::string::npos) break;
          buffer = buffer.substr(valuePos);
        case '"':  // begin value, read until end quote
          builder.readQuotedValue(stream, buffer);
          break;
      }
      break;
  }
  return stream;
}
