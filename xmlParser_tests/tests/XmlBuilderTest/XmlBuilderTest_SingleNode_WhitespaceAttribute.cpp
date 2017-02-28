// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <fstream>
#include <XmlBuilder.hpp>
#include "XmlBuilderTest.hpp"

class XmlBuilderTest_SingleNode_WhitespaceAttribute : public XmlBuilderTest {
 public:
  const XmlNode expected;
 protected:
  XmlBuilderTest_SingleNode_WhitespaceAttribute() :
      XmlBuilderTest(),
      expected("root", std::vector<XmlAttribute> {
          XmlAttribute("attribute", " ")
      }) {}
};

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, String_NoWhitespace) {
  testString("<root attribute=\" \"/>", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, String_AssignmentWhitespacePre) {
  testString("<root attribute =\" \"/>", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, String_AssignmentWhitespacePost) {
  testString("<root attribute= \" \"/>", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, String_AssignmentWhitespacePrePost) {
  testString("<root attribute = \" \"/>", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, String_CloseWhitespace) {
  testString("<root attribute=\" \" />", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, String_CloseWhitespace_AssignmentWhitespacePre) {
  testString("<root attribute =\" \" />", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, String_CloseWhitespace_AssignmentWhitespacePost) {
  testString("<root attribute= \" \" />", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, String_CloseWhitespace_AssignmentWhitespacePrePost) {
  testString("<root attribute = \" \" />", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, File_NoWhitespace) {
  testFile("data/XmlBuilderTest/SingleNode/WhitespaceAttribute/NoWhitespace.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, File_AssignmentWhitespacePre) {
  testFile("data/XmlBuilderTest/SingleNode/WhitespaceAttribute/AssignmentWhitespacePre.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, File_AssignmentWhitespacePost) {
  testFile("data/XmlBuilderTest/SingleNode/WhitespaceAttribute/AssignmentWhitespacePost.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, File_AssignmentWhitespacePrePost) {
  testFile("data/XmlBuilderTest/SingleNode/WhitespaceAttribute/AssignmentWhitespacePrePost.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, File_CloseWhitespace) {
  testFile("data/XmlBuilderTest/SingleNode/WhitespaceAttribute/CloseWhitespace.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, File_CloseWhitespace_AssignmentWhitespacePre) {
  testFile("data/XmlBuilderTest/SingleNode/WhitespaceAttribute/CloseWhitespace_AssignmentWhitespacePre.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, File_CloseWhitespace_AssignmentWhitespacePost) {
  testFile("data/XmlBuilderTest/SingleNode/WhitespaceAttribute/CloseWhitespace_AssignmentWhitespacePost.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_WhitespaceAttribute, File_CloseWhitespace_AssignmentWhitespacePrePost) {
  testFile("data/XmlBuilderTest/SingleNode/WhitespaceAttribute/CloseWhitespace_AssignmentWhitespacePrePost.xml", expected);
}