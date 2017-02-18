// Copyright 2017 Timothy Oltjenbruns.

#include <assert.h>
#include "XmlNode.hpp"

XmlNode::XmlNode()
    : name("")
    , attributes(std::vector<XmlAttribute>())
    , children(std::vector<XmlNode>())  { }

XmlNode::XmlNode(const std::string &name)
    : name(name)
    , attributes(std::vector<XmlAttribute>())
    , children(std::vector<XmlNode>()) {
  assert(!name.empty());
}

XmlNode::XmlNode(const std::string &name,
                 const std::vector<XmlAttribute> &attributes)
    : name(name)
    , attributes(attributes)
    , children(std::vector<XmlNode>()) {
  assert(!name.empty());
}

XmlNode::XmlNode(const std::string &name,
                 const std::vector<XmlAttribute> &attributes,
                 const std::vector<XmlNode> &children)
    : name(name)
    , attributes(attributes)
    , children(children) {
  assert(!name.empty());
}

const std::string &XmlNode::getName() const {
  return name;
}

void XmlNode::setName(const std::string &name) {
  assert(!name.empty());
  XmlNode::name = name;
}

std::vector<XmlAttribute> &XmlNode::getAttributes() {
  return attributes;
}

void XmlNode::setAttributes(const std::vector<XmlAttribute> &attributes) {
  XmlNode::attributes = attributes;
}

std::vector<XmlNode> &XmlNode::getChildren() {
  return children;
}

void XmlNode::setChildren(const std::vector<XmlNode> &children) {
  XmlNode::children = children;
}
