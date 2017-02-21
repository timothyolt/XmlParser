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
  /// \brief  Whether the current (last) attribute is "open" or not.
  ///         Open attributes can have their values set. The attribute must be closed to close the cursor.
  bool attributeOpen;

 public:
  /// \brief  Creates an \p XmlBuilder with a root \p XmlNode named "xml"
  XmlBuilder();
  /// \brief  Check sanity of the Xml tree
  /// \return Whether the root is valid to get
  bool valid();
  /// \brief  Get the current state of the Xml tree
  /// \return root XmlNode
  /// \throws XmlParseException if cursor or attribute is open
  XmlNode& get();
  /// \brief        Read stream until \p eof
  /// \param stream Input stream reference
  /// \return       Identical stream reference for chaining
  /// \throws       XmlParseException if >> throws any exceptions
  /// \see          XmlBuilder::operator>>
  std::istream &readStream(std::istream &stream);
  /// \brief          Atomic stream input
  ///                 Atomic stream input. Uses a single >> operator internally, unless quotes are encountered,
  ///                 in that case, the >> operator is called until the quotes are closed. \p readQuotedValue
  ///                 This should be looped and called multiple times until the stream is known to be completed.
  /// \param stream   Input stream reference
  /// \param builder  Destination \p XmlBuilder
  /// \return         Identical stream reference for chaining
  /// \throws         XmlParseException if there is whitespace between node brackets and node name
  /// \throws         XmlParseException see other references
  /// \see            XmlBuilder::startNode
  /// \see            XmlBuilder::finishNodeHeader
  /// \see            XmlBuilder::finishNode
  /// \see            XmlBuilder::startAttribute
  /// \see            XmlBuilder::flagAttribute
  /// \see            XmlBuilder::readAttributeValue
  friend std::istream& operator>> (std::istream& stream, XmlBuilder& builder);

 private:
  /// \brief      Moves the cursor to a newly created child on the current cursor
  /// \param name Name to give the new node
  /// \throws     XmlParseException if the cursor is open
  void startNode(std::string name);
  /// \brief  Close the cursor to attributes and begin accepting children
  /// \see    XmlBuilder::finishAttribute();
  /// \throws XmlParseException if the cursor is not open or the last attribute is still open
  void finishNodeHeader();
  /// \brief      Move the cursor to it's parent node
  /// \param name Node name, for accuracy
  /// \throws     XmlParseException if the given name does not match the cursor or if the cursor does not have a parent
  void finishNode(std::string name);
  /// \brief      Starts constructing an attribute on the cursor
  /// \param key  key to give the new attribute
  /// \throws     XmlParseException if the cursor is not open or if the previous attribute is still open
  void startAttribute(std::string key);
  /// \brief  Flags the current attribute as ready for value assignment
  /// \throws XmlParseException if the cursor is not open or if the current attribute already has a value
  void flagAttribute();
  /// \brief        Reads a stream until it's end quote.
  ///               Strips out newlines and tabs and processes those escape sequences
  /// \param stream Input stream to read
  /// \param value  Use this buffer to store value in. Useful for setting an initial value.
  /// \throws       XmlParseException if the cursor is not open or if the current attribute has not been flagged
  /// \throws       XmlParseException if the string has an invalid escape sequence
  void readAttributeValue(std::istream &stream, std::string value);
  /// \brief  Close the current attribute
  /// \throws XmlParseException if the current attribute is not open
  void finishAttribute();
};

#endif  // XMLPARSER_XMLBUILDER_HPP_
