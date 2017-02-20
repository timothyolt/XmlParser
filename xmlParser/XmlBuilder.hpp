// Copyright 2017 Timothy Oltjenbruns.

#ifndef XMLPARSER_XMLBUILDER_HPP_
#define XMLPARSER_XMLBUILDER_HPP_

#include <string>
#include "XmlNode.hpp"

class XmlBuilder {
 private:
  class XmlParseException : std::exception {};
  /// \brief  root node of the xml tree in the building process
  XmlNode root;
  /// \brief  Current node to add \p attributes or \p children to
  XmlNode* cursor;
  /// \brief  Whether the cursor is "open" or not.
  ///         \p attributes are valid for an open cursor while \p children are valid for a closed one
  bool cursorOpen;

 public:
  /// \brief  Creates an \p XmlBuilder with a root \p XmlNode named "xml"
  XmlBuilder();
  /// \brief  Resets the children of the root \p XmlNode
  void reset();
  /// \brief          Atomic stream input
  ///                 Atomic stream input. Uses a single >> operator internally, unless quotes are encountered,
  ///                 in that case, the >> operator is called until the quotes are closed. \p readQuotedValue
  ///                 This should be looped and called multiple times until the stream is known to be completed.
  /// \param stream   Input stream reference
  /// \param builder  Destination \p XmlBuilder
  /// \return         Identical stream reference for chaining
  /// \see            XmlBuilder::startAttribute
  /// \see            XmlBuilder::flagAttribute
  /// \see            XmlBuilder::readAttributeValue
  friend std::istream& operator>> (std::istream& stream, XmlBuilder& builder);

 private:
  void startNode(std::string name);
  void finishNodeHeader();
  void finishNode(std::string name);
  /// \brief      Starts constructing an attribute on the cursor
  /// \param key  key to give the new attribute
  void startAttribute(std::string key);
  /// \brief Flags the current attribute as ready for value assignment
  void flagAttribute();
  /// \brief        Reads a stream until it's end quote.
  ///               Strips out newlines and tabs and processes those escape sequences
  /// \param stream Input stream to read
  /// \param buffer Use this buffer to store value in. Useful for setting an initial value.
  void readAttributeValue(std::istream &stream, std::string &buffer);
  void finishAttribute();
};

#endif  // XMLPARSER_XMLBUILDER_HPP_
