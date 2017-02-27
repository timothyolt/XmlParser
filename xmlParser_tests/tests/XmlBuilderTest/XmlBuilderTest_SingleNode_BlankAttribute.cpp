// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <fstream>
#include <XmlBuilder.hpp>
#include "XmlBuilderTest.hpp"

class XmlBuilderTest_SingleNode_BlankAttribute : public XmlBuilderTest {
 public:
  const XmlNode expected;
 protected:
  XmlBuilderTest_SingleNode_BlankAttribute() :
      XmlBuilderTest(),
      expected("root", std::vector<XmlAttribute> {
          XmlAttribute("attribute", "")
      }) {}
};

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, String_NoWhitespace) {
  std::stringstream string("<root attribute=\"\"/>");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, String_AssignmentWhitespacePre) {
  std::stringstream string("<root attribute =\"\"/>");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, String_AssignmentWhitespacePost) {
  std::stringstream string("<root attribute= \"\"/>");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, String_AssignmentWhitespacePrePost) {
  std::stringstream string("<root attribute = \"\"/>");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, String_CloseWhitespace) {
  std::stringstream string("<root attribute=\"\" />");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, String_CloseWhitespace_AssignmentWhitespacePre) {
  std::stringstream string("<root attribute =\"\" />");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, String_CloseWhitespace_AssignmentWhitespacePost) {
  std::stringstream string("<root attribute= \"\" />");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, String_CloseWhitespace_AssignmentWhitespacePrePost) {
  std::stringstream string("<root attribute = \"\" />");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, File_NoWhitespace) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/BlankAttribute/NoWhitespace.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, File_AssignmentWhitespacePre) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePre.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, File_AssignmentWhitespacePost) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePost.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, File_AssignmentWhitespacePrePost) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePrePost.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, File_CloseWhitespace) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, File_CloseWhitespace_AssignmentWhitespacePre) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePre.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, File_CloseWhitespace_AssignmentWhitespacePost) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePost.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_BlankAttribute, File_CloseWhitespace_AssignmentWhitespacePrePost) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePrePost.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}
