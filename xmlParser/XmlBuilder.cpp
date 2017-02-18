// Copyright 2017 Timothy Oltjenbruns.

#include <vector>
#include "XmlBuilder.hpp"

class XmlParseException : std::exception {};

XmlBuilder::XmlBuilder()
    : root(XmlNode("xml"))
    , cursor(&root)
    , cursorOpen(false) { }

void XmlBuilder::reset() {
  root.setChildren(std::vector<XmlNode>());
  cursorOpen = false;
}

// TODO(timothyolt): write looper classes for console, files, stringstream, whatever else

std::istream& operator>>(std::istream& stream, XmlBuilder& builder) {
  std::string buffer;
  stream >> buffer;
  switch (buffer[0]) {
    case '<':
      // new tag
      switch (buffer[1]) {
        case '/':
          // closing tag, no attributes, move cursor
          break;
        default:
          // open tag, begin reading attributes
          break;
      }
      break;
    case '/':
      // end tag, tag has no children, move cursor
      break;
    default:
      // must be accepting attributes
      if (!builder.cursorOpen)
        throw XmlParseException();

      break;
  }
  return stream;
}
