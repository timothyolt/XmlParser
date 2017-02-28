// Copyright 2017 Timothy Oltjenbruns.

#include "XmlUtils.hpp"

XmlUtils::Helpers::XmlNodeIndex::XmlNodeIndex(
    const XmlNode *pointer, std::vector<XmlNode>::size_type index)
    : pointer(pointer), index(index) {}

const XmlNode *XmlUtils::searchAttributeDf(const XmlNode *root,
                                           const XmlAttribute attribute) {
  return searchDf(root, [attribute](const XmlNode *node) {
    return std::find(node->getConstAttributes().begin(),
                     node->getConstAttributes().end(),
                     attribute) != node->getConstAttributes().end();
  });
}

const XmlNode *XmlUtils::searchValueDf(const XmlNode *root, std::string value) {
  return searchDf(root, [value](const XmlNode *node) {
    return value.compare(node->getName()) == 0 ||
           std::find_if(node->getConstAttributes().begin(),
                        node->getConstAttributes().end(),
                        [value](const XmlAttribute &attribute) {
                          return value.compare(attribute.getValue()) == 0;
                        }) != node->getConstAttributes().end();
  });
}

const XmlNode *XmlUtils::searchAttributeBf(const XmlNode *root,
                                           const XmlAttribute attribute) {
  return searchBf(root, [attribute](const XmlNode *node) {
    return std::find(node->getConstAttributes().begin(),
                     node->getConstAttributes().end(),
                     attribute) != node->getConstAttributes().end();
  });
}

const XmlNode *XmlUtils::searchValueBf(const XmlNode *root, std::string value) {
  return searchBf(root, [value](const XmlNode *node) {
    return value.compare(node->getName()) == 0 ||
           std::find_if(node->getConstAttributes().begin(),
                        node->getConstAttributes().end(),
                        [value](const XmlAttribute &attribute) {
                          return value.compare(attribute.getValue()) == 0;
                        }) != node->getConstAttributes().end();
  });
}

const XmlNode* XmlUtils::stochasticResponse(const XmlNode *node) {
  std::vector<XmlNode>::size_type size(node->getConstChildren().size());
  if (size == 0)
    return node;
  // whether the parent node has a non-empty behavior attribute
  bool parentBehavior((std::find_if(node->getConstAttributes().begin(), node->getConstAttributes().end(), [](const XmlAttribute& attribute){
    return attribute.getKey().compare("response") == 0 && !attribute.getValue().empty();
  }) != node->getConstAttributes().end()));
  unsigned long selection(rand() % (node->getConstChildren().size() + (parentBehavior ? 1 : 0)));
  // data flow analysis false positive
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
  if (selection == size)
    return node;
  return stochasticResponse(&node->getConstChildren()[selection]);
#pragma clang diagnostic pop
}
