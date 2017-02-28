// Copyright 2017 Timothy Oltjenbruns.

#ifndef XMLPARSER_XMLUTILS_HPP_
#define XMLPARSER_XMLUTILS_HPP_

#include <algorithm>
#include <vector>
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

/// \brief            Depth-First Search
/// \param attribute  Attribute key/value pair to search for
/// \return           Const-pointer to first node matching the attribute, or nullptr if not found
const XmlNode *searchDf(const XmlNode *root,
                        const XmlAttribute attribute);

/// \brief            Depth-First Search
/// \param attribute  Attribute key/value pair to search for
/// \return           Const-pointer to first node matching the attribute, or nullptr if not found
const XmlNode *searchBf(const XmlNode *root,
                        const XmlAttribute attribute);
};

#endif  // XMLPARSER_XMLUTILS_HPP_
