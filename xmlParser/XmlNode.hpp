// Copyright 2017 Timothy Oltjenbruns.

#include <string>
#include <vector>
#include <stack>
#include <ostream>
#include "XmlAttribute.hpp"

#ifndef XMLPARSER_XMLNODE_HPP_
#define XMLPARSER_XMLNODE_HPP_

/// \brief A named Xml tag with various attributes and children
class XmlNode {
 private:
  /// \brief pointer to the parent node, if known
  XmlNode* parent;
  /// \brief Xml tag name
  std::string name;
  /// \brief vector of tag attributes
  std::vector<XmlAttribute> attributes;
  /// \brief vector of child nodes
  std::vector<XmlNode> children;
 public:
  /// \brief Creates a blank Xml node
  XmlNode();
  /// \brief              Creates a named Xml node
  /// \pre                \p name must not be empty
  /// \param name         Tag name
  explicit XmlNode(const std::string &name);
  /// \brief              Creates a named Xml node with a pointer to it's parent
  /// \pre                \p name must not be empty
  /// \param name         Tag name
  /// \param parent       Parent pointer
  XmlNode(const std::string &name,
          XmlNode* parent);
  /// \brief              Creates a named Xml node with attributes
  /// \pre                \p name must not be empty
  /// \param name         Tag name
  /// \param attributes   Vector of attributes
  XmlNode(const std::string &name,
          const std::vector<XmlAttribute> &attributes);
  /// \brief              Creates a named Xml node with attributes and a pointer to it's parent
  /// \pre                \p name must not be empty
  /// \param name         Tag name
  /// \param parent       Parent pointer
  /// \param attributes   Vector of attributes
  XmlNode(const std::string &name,
          XmlNode* parent,
          const std::vector<XmlAttribute> &attributes);
  /// \brief              Creates a named Xml node with attributes and children
  /// \pre                \p name must not be empty
  /// \param name         Tag name
  /// \param attributes   Vector of attributes
  /// \param children     Vector of child nodes
  XmlNode(const std::string &name,
          const std::vector<XmlAttribute> &attributes,
          const std::vector<XmlNode> &children);
  /// \brief              Creates a named Xml node with attributes and children and a pointer to it's parent
  /// \pre                \p name must not be empty
  /// \param name         Tag name
  /// \param parent       Parent pointer
  /// \param attributes   Vector of attributes
  /// \param children     Vector of child nodes
  XmlNode(const std::string &name,
          XmlNode* parent,
          const std::vector<XmlAttribute> &attributes,
          const std::vector<XmlNode> &children);
  /// \brief        Copies an xml node
  /// \param copy   Xml reference to copy
  XmlNode(const XmlNode &copy);
  /// \brief  Gets the pointer to the parent node
  /// \return parent node pointer
  XmlNode *getParent() const;
  /// \brief        Sets a pointer to the parent node
  /// \param parent parent pointer
  void setParent(XmlNode *parent);
  /// \brief  Gets the tag name
  /// \return /p name
  const std::string &getName() const;
  /// \brief      Sets the tag name
  /// \pre        \p name must not be empty
  /// \param name name as a string
  void setName(const std::string &name);
  /// \brief  Gets the vector of attributes
  /// \return /p attributes
  std::vector<XmlAttribute> &getAttributes();
  const std::vector<XmlAttribute> &getConstAttributes() const;
  /// \brief              Replaces the current attributes vector with the given one
  /// \param attributes
  void setAttributes(const std::vector<XmlAttribute> &attributes);
  /// \brief  Gets the vector of children nodes
  /// \return /p children nodes
  std::vector<XmlNode> &getChildren();
  const std::vector<XmlNode> &getConstChildren() const;
  /// \brief            Replaces the current children vector with the given one
  /// \param children
  void setChildren(const std::vector<XmlNode> &children);
  /// \brief      Nodes are equal if the name, every child element, and every attribute element are equal
  /// \param rhs  Other node to compare
  /// \return     Whether the nodes are considered equal
  bool operator==(const XmlNode &rhs) const;
  /// \brief      Nodes are equal if the name, every child, and every attribute are equal.
  ///             Not equal takes the direct inverse of this check.
  /// \param rhs  Other node to compare
  /// \return     Whether the nodes are considered not equal
  bool operator!=(const XmlNode &rhs) const;

  std::string toString() const;

  friend std::ostream &operator<<(std::ostream &os, const XmlNode &node);
};

#endif  // XMLPARSER_XMLNODE_HPP_
