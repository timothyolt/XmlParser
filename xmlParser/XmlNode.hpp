// Copyright 2017 Timothy Oltjenbruns.

#include <string>
#include <vector>
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
          const XmlNode* parent);
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
          const XmlNode* parent,
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
          const XmlNode* parent,
          const std::vector<XmlAttribute> &attributes,
          const std::vector<XmlNode> &children);
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
  /// \brief              Replaces the current attributes vector with the given one
  /// \param attributes
  void setAttributes(const std::vector<XmlAttribute> &attributes);
  /// \brief  Gets the vector of children nodes
  /// \return /p children nodes
  std::vector<XmlNode> &getChildren();
  /// \brief            Replaces the current children vector with the given one
  /// \param children
  void setChildren(const std::vector<XmlNode> &children);
};

#endif  // XMLPARSER_XMLNODE_HPP_
