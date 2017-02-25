// Copyright 2017 Timothy Oltjenbruns.

#include <assert.h>
#include "XmlNode.hpp"

XmlNode::XmlNode()
    : name("")
    , parent(nullptr)
    , attributes(std::vector<XmlAttribute>())
    , children(std::vector<XmlNode>()) { }

XmlNode::XmlNode(const std::string &name)
    : name(name)
    , parent(nullptr)
    , attributes(std::vector<XmlAttribute>())
    , children(std::vector<XmlNode>()) {
  assert(!name.empty());
}

XmlNode::XmlNode(const std::string &name,
                 XmlNode *parent)
    : name(name)
    , parent(parent)
    , attributes(std::vector<XmlAttribute>())
    , children(std::vector<XmlNode>()) {
  assert(!name.empty());
}

XmlNode::XmlNode(const std::string &name,
                 const std::vector<XmlAttribute> &attributes)
    : name(name)
    , parent(nullptr)
    , attributes(attributes)
    , children(std::vector<XmlNode>()) {
  assert(!name.empty());
}

XmlNode::XmlNode(const std::string &name,
                 XmlNode *parent,
                 const std::vector<XmlAttribute> &attributes)
    : name(name)
    , parent(parent)
    , attributes(attributes)
    , children(std::vector<XmlNode>()) {
  assert(!name.empty());
}

XmlNode::XmlNode(const std::string &name,
                 const std::vector<XmlAttribute> &attributes,
                 const std::vector<XmlNode> &children)
    : name(name)
    , parent(nullptr)
    , attributes(attributes)
    , children(children) {
  assert(!name.empty());
}

XmlNode::XmlNode(const std::string &name,
                 XmlNode *parent,
                 const std::vector<XmlAttribute> &attributes,
                 const std::vector<XmlNode> &children)
    : name(name)
    , parent(parent)
    , attributes(attributes)
    , children(children) {
  assert(!name.empty());
}

XmlNode *XmlNode::getParent() const {
  return parent;
}

void XmlNode::setParent(XmlNode *parent) {
  XmlNode::parent = parent;
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

bool XmlNode::operator==(const XmlNode &rhs) const {
  return parent == rhs.parent &&
      name == rhs.name &&
      attributes == rhs.attributes &&
      children == rhs.children;
}

bool XmlNode::operator!=(const XmlNode &rhs) const {
  return !(rhs == *this);
}
