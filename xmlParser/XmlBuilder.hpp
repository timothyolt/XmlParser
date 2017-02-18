// Copyright 2017 Timothy Oltjenbruns.

#ifndef XMLPARSER_XMLBUILDER_HPP_
#define XMLPARSER_XMLBUILDER_HPP_

#include <string>
#include "XmlNode.hpp"

class XmlBuilder {
 private:
  std::string buffer;
  XmlNode xml;
  XmlNode cursor;

 public:
  XmlBuilder();
  friend std::istream& operator>> (std::istream& stream, XmlBuilder& builder);
};

#endif  // XMLPARSER_XMLBUILDER_HPP_
