// Copyright 2017 Timothy Oltjenbruns.

#include "XmlNode.hpp"

XmlNode::XmlNode(const std::string &name) { }

XmlNode::XmlNode(const std::string &name, const std::vector<XmlAttribute> &attributes)
    : name(name), attributes(attributes) { }

XmlNode::XmlNode(const std::string &name,
                 const std::vector<XmlAttribute> &attributes,
                 const std::vector<XmlNode> &children) { }

const std::string &XmlNode::getName() const {
  return name;
}

void XmlNode::setName(const std::string &name) {
  XmlNode::name = name;
}

const std::vector<XmlAttribute> &XmlNode::getAttributes() const {
  return attributes;
}

const std::vector<XmlNode> &XmlNode::getChildren() const {
  return children;
}
