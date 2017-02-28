// Copyright 2017 Timothy Oltjenbruns.

#ifndef XMLPARSER_XMLUTILS_HPP_
#define XMLPARSER_XMLUTILS_HPP_

#include <algorithm>
#include <vector>
#include <queue>
#include "XmlNode.hpp"

namespace XmlUtils {
namespace Helpers {
class XmlNodeIndex {
public:
  const XmlNode *pointer;
  std::vector<XmlNode>::size_type index;
  XmlNodeIndex(const XmlNode *pointer, std::vector<XmlNode>::size_type index);
};
}
/// \brief            Depth-First Search using a Functional to evaluate the node
/// \param evaluate  Functional used to evaluate the node
/// \return           Const-pointer to first node matching the functional, or nullptr if not found
template <typename Functional>
const XmlNode* searchDf(const XmlNode *root, Functional evaluate) {
  std::stack<Helpers::XmlNodeIndex> stack;
  stack.emplace(root, 0);
  while (!stack.empty()) {
    auto cursor(stack.top().pointer);
    if (stack.top().index == 0 && evaluate(cursor))
      return cursor;
    if (stack.top().index < cursor->getConstChildren().size()) {
      stack.emplace(&cursor->getConstChildren()[stack.top().index++], 0);
    }
    else stack.pop();
  }
  return nullptr;
}
/// \brief            Depth-First Search for a node containing a matching attribute
/// \param attribute  Attribute key/value pair to search for
/// \return           Const-pointer to first node matching the attribute, or nullptr if not found
const XmlNode* searchAttributeDf(const XmlNode *root, const XmlAttribute attribute);
/// \brief        Depth-First Search for a node with a matching name, or attribute value
/// \param value  String to compate with node name, and attribute value
/// \return       Const-pointer to first node matching the attribute, or nullptr if not found
const XmlNode* searchValueDf(const XmlNode *root, std::string value);
/// \brief            Breadth-First Search using a Functional to evaluate the node
/// \param evaluate   Functional used to evaluate the node
/// \return           Const-pointer to first node matching the functional, or nullptr if not found
template <typename Functional>
const XmlNode* searchBf(const XmlNode *root, Functional evaluate) {
  std::queue<Helpers::XmlNodeIndex> queue;
  queue.emplace(root, 0);
  while (!queue.empty()) {
    auto cursor(queue.front().pointer);
    if (evaluate(cursor))
      return cursor;
    for (auto i(0); i < cursor->getConstChildren().size(); ++i)
      queue.emplace(&cursor->getConstChildren()[i], 0);
    queue.pop();
  }
  return nullptr;
}
/// \brief            Breadth-First Search for a node containing a matching attribute
/// \param attribute  Attribute key/value pair to search for
/// \return           Const-pointer to first node matching the attribute, or nullptr if not found
const XmlNode* searchAttributeBf(const XmlNode *root, const XmlAttribute attribute);
/// \brief        Breadth-First Search for a node with a matching name, or attribute value
/// \param value  String to compate with node name, and attribute value
/// \return       Const-pointer to first node matching the attribute, or nullptr if not found
const XmlNode* searchValueBf(const XmlNode *root, std::string value);
/// \brief      Stochastically selects a leaf node based on a parent input node
/// \param node Pointer to an behavior tree node
/// \return     Pointer to selected leaf
const XmlNode *stochasticResponse(const XmlNode *node);
};

#endif  // XMLPARSER_XMLUTILS_HPP_
