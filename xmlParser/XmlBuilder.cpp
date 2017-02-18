// Copyright 2017 Timothy Oltjenbruns.

#include "XmlBuilder.hpp"

XmlBuilder::XmlBuilder()
    : buffer("")
    , xml(XmlNode("xml"))
    , cursor(xml) { }

// TODO(timothyolt): write looper classes for console, files, stringstream, whatever else

/// \brief          Atomic stream input
///                 Atomic stream input. Uses a single >> operator internally.
///                 This should be looped and called multiple times until the stream is known to be completed.
/// \param stream   Input stream reference
/// \param builder  Destination \p XmlBuilder
/// \return         Identical stream reference for chaining
std::istream& operator>>(std::istream& stream, XmlBuilder& builder) {
  stream >> builder.buffer;
  switch (builder.buffer[0]) {
    case '<':
      // new tag
      switch (builder.buffer[1]) {
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
      // must be an attribute, develop more in-depth testing to confirm this
      break;
  }
  return stream;
}
