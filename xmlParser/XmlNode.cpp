// Copyright 2017 Timothy Oltjenbruns.

#include "XmlNode.hpp"
#include "XmlUtils.hpp"
#include <assert.h>
#include <algorithm>
#include <iostream>

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

XmlNode::XmlNode(const XmlNode &copy)
    : name(copy.name)
    , parent(copy.parent)
    , attributes(copy.attributes)
    , children(copy.children) { }

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

const std::vector<XmlAttribute> &XmlNode::getConstAttributes() const {
  return attributes;
}

void XmlNode::setAttributes(const std::vector<XmlAttribute> &attributes) {
  XmlNode::attributes = attributes;
}

std::vector<XmlNode> &XmlNode::getChildren() {
  return children;
}

const std::vector<XmlNode> &XmlNode::getConstChildren() const {
  return children;
}

void XmlNode::setChildren(const std::vector<XmlNode> &children) {
  XmlNode::children = children;
}

bool XmlNode::operator==(const XmlNode &rhs) const {
  // equal nodes can have different parents
  return  // parent == rhs.parent &&
      name == rhs.name &&
      attributes == rhs.attributes &&
      children == rhs.children;
}

bool XmlNode::operator!=(const XmlNode &rhs) const {
  return !(rhs == *this);
}

std::string XmlNode::toString() const {
  if (attributes.size() == 0)
    return name;
  std::string line;
  for (auto i(0); i < attributes.size(); ++i)
    if (attributes[i].getValue().length() > 0)
      line += attributes[i].getKey() + " = " + attributes[i].getValue() + ' ';
  return line;
}

std::ostream &operator<<(std::ostream &os, const XmlNode &node) {
  std::stack<XmlUtils::Helpers::XmlNodeIndex> stack;
  stack.emplace(&node, 0);
  while (!stack.empty()) {
    auto cursor(stack.top().pointer);
    if (stack.top().index == 0) {
      std::cout << std::endl;
      for (auto i(1); i < stack.size(); ++i)
        std::cout << '\t';
      std::cout << cursor->toString();
    }
    if (stack.top().index < cursor->getConstChildren().size()) {
      stack.emplace(&cursor->getConstChildren()[stack.top().index++], 0);
    }
    else stack.pop();
  }
  return os;
}
