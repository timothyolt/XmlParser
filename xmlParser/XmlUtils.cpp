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
