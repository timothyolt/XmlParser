// Copyright 2017 Timothy Oltjenbruns.

#ifndef XMLPARSER_XMLBUILDER_HPP_
#define XMLPARSER_XMLBUILDER_HPP_

#include <string>
#include "XmlNode.hpp"

class XmlBuilder {
 private:
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
  ///                 Atomic stream input. Uses a single >> operator internally.
  ///                 This should be looped and called multiple times until the stream is known to be completed.
  /// \param stream   Input stream reference
  /// \param builder  Destination \p XmlBuilder
  /// \return         Identical stream reference for chaining
  friend std::istream& operator>> (std::istream& stream, XmlBuilder& builder);
};

#endif  // XMLPARSER_XMLBUILDER_HPP_
