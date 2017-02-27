// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <fstream>
#include <XmlBuilder.hpp>
#include "XmlBuilderTest.hpp"

class XmlBuilderTest_SingleNode_Empty : public XmlBuilderTest {
 public:
  const XmlNode expected;
 protected:
  XmlBuilderTest_SingleNode_Empty() :
      XmlBuilderTest(),
      expected("root") {}
};

TEST_F(XmlBuilderTest_SingleNode_Empty, String_NoWhitespace) {
  std::stringstream string("<root/>");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_Empty, String_CloseWhitespace) {
  std::stringstream string("<root />");
  xmlBuilder.build(string);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_Empty, File_NoWhitespace) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/Empty/NoWhitespace.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest_SingleNode_Empty, File_CloseWhitespace) {
  std::ifstream file;
  file.open("data/XmlBuilderTest/SingleNode/Empty/CloseWhitespace.xml");
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}
