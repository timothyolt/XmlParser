// Copyright 2017 Timothy Oltjenbruns.

#ifndef XMLPARSER_XMLATTRIBUTE_HPP_
#define XMLPARSER_XMLATTRIBUTE_HPP_

#include <string>
/// \brief An Xml tag attribute as a key-value pair
class XmlAttribute {
 private:
  /// \brief Xml attribute key
  std::string key;
  /// \brief Xml attribute value
  std::string value;
 public:
  /// \brief Creates a blank XmlAttribute with
  XmlAttribute();
  /// \brief        Creates an \p XmlAttribute with a /p name and /p value
  /// \pre          \p key must not be empty, \p value can be empty
  /// \param key    Attribute key name
  /// \param value  Attribute value, with quotes removed
  XmlAttribute(const std::string &key, const std::string &value);
  /// \brief  Gets the XmlAttribute key as a /p string
  /// \return /p key
  const std::string &getKey() const;
  /// \brief      Sets the XmlAttribute key as a /p string
  /// \pre        \p key must not be empty
  /// \param key  Key name
  void setKey(const std::string &key);
  /// \brief  Gets the XmlAttribute value as a /p string without quotes
  /// \return /p value
  const std::string &getValue() const;
  /// \brief        Sets the XmlAttribute value as a /p string without quotes
  /// \param value  Value without quotes
  void setValue(const std::string &value);
  /// \brief      Attributes are equal if the key and value strings are equal
  /// \param rhs  Other attribute to compare
  /// \return     Whether the attributes are considered equal
  bool operator==(const XmlAttribute &rhs) const;
  /// \brief      Attributes are equal if either the key and value strings are equal,
  ///             and not equal takes the direct inverse of this check
  /// \param rhs  Other attribute to compare
  /// \return     Whether the attributes are considered not equal
  bool operator!=(const XmlAttribute &rhs) const;
};

#endif  // XMLPARSER_XMLATTRIBUTE_HPP_
