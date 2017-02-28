// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <fstream>
#include <XmlBuilder.hpp>
#include "XmlBuilderTest.hpp"

class XmlBuilderTest_SingleNode_Attribute : public XmlBuilderTest {
 public:
  const XmlNode expected;
 protected:
  XmlBuilderTest_SingleNode_Attribute() :
      XmlBuilderTest(),
      expected("root", std::vector<XmlAttribute> {
          XmlAttribute("attribute", "value")
      }) {}
};

TEST_F(XmlBuilderTest_SingleNode_Attribute, String_NoWhitespace) {
  testString("<root attribute=\"\"/>", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, String_AssignmentWhitespacePre) {
  testString("<root attribute =\"\"/>", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, String_AssignmentWhitespacePost) {
  testString("<root attribute= \"\"/>", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, String_AssignmentWhitespacePrePost) {
  testString("<root attribute = \"\"/>", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, String_CloseWhitespace) {
  testString("<root attribute=\"\" />", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, String_CloseWhitespace_AssignmentWhitespacePre) {
  testString("<root attribute =\"\" />", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, String_CloseWhitespace_AssignmentWhitespacePost) {
  testString("<root attribute= \"\" />", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, String_CloseWhitespace_AssignmentWhitespacePrePost) {
  testString("<root attribute = \"\" />", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, File_NoWhitespace) {
  testFile("data/XmlBuilderTest/SingleNode/BlankAttribute/NoWhitespace.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, File_AssignmentWhitespacePre) {
  testFile("data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePre.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, File_AssignmentWhitespacePost) {
  testFile("data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePost.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, File_AssignmentWhitespacePrePost) {
  testFile("data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePrePost.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, File_CloseWhitespace) {
  testFile("data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, File_CloseWhitespace_AssignmentWhitespacePre) {
  testFile("data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePre.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, File_CloseWhitespace_AssignmentWhitespacePost) {
  testFile("data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePost.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Attribute, File_CloseWhitespace_AssignmentWhitespacePrePost) {
  testFile("data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePrePost.xml", expected);
}
