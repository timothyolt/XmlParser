// Copyright 2017 Timothy Oltjenbruns.

#include "XmlNode.hpp"

XmlNode::XmlNode(const std::string &name)
    : name(name) { }

XmlNode::XmlNode(const std::string &name,
                 const std::vector<XmlAttribute> &attributes)
    : name(name)
    , attributes(attributes) { }

XmlNode::XmlNode(const std::string &name,
                 const std::vector<XmlAttribute> &attributes,
                 const std::vector<XmlNode> &children)
    : name(name)
    , attributes(attributes)
    , children(children) { }

const std::string &XmlNode::getName() const {
  return name;
}

void XmlNode::setName(const std::string &name) {
  XmlNode::name = name;
}

std::vector<XmlAttribute> &XmlNode::getAttributes() {
  return attributes;
}

void XmlNode::setAttributes(std::vector<XmlAttribute> &attributes) {
  XmlNode::attributes = attributes;
}

std::vector<XmlNode> &XmlNode::getChildren() {
  return children;
}

void XmlNode::setChildren(std::vector<XmlNode> &children) {
  XmlNode::children = children;
}
