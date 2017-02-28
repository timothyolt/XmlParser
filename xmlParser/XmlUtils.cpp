// Copyright 2017 Timothy Oltjenbruns.

#include "XmlUtils.hpp"
#include <queue>

XmlUtils::Helpers::XmlNodeIndex::XmlNodeIndex(
    const XmlNode *pointer, std::vector<XmlNode>::size_type index)
    : pointer(pointer), index(index) {}

const XmlNode *XmlUtils::searchDf(const XmlNode *root, const XmlAttribute attribute) {
  std::stack<Helpers::XmlNodeIndex> stack;
  stack.emplace(root, 0);
  while (!stack.empty()) {
    auto cursor(stack.top().pointer);
    if (stack.top().index == 0 &&
        std::find(cursor->getConstAttributes().begin(), cursor->getConstAttributes().end(), attribute)
            != cursor->getConstAttributes().end())
      return cursor;
    if (stack.top().index < cursor->getConstChildren().size()) {
      stack.emplace(&cursor->getConstChildren()[stack.top().index++], 0);
    }
    else stack.pop();
  }
  return nullptr;
}

const XmlNode *XmlUtils::searchBf(const XmlNode *root, const XmlAttribute attribute) {
  std::queue<Helpers::XmlNodeIndex> queue;
  queue.emplace(root, 0);
  while (!queue.empty()) {
    auto cursor(queue.front().pointer);
    if (std::find(cursor->getConstAttributes().begin(), cursor->getConstAttributes().end(), attribute)
            != cursor->getConstAttributes().end())
      return cursor;
    for (auto i(0); i < cursor->getConstChildren().size(); ++i)
      queue.emplace(&cursor->getConstChildren()[i], 0);
    queue.pop();
  }
  return nullptr;
}
