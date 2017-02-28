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
  testString("<root/>", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Empty, String_CloseWhitespace) {
  testString("<root />", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Empty, File_NoWhitespace) {
  testFile("data/XmlBuilderTest/SingleNode/Empty/NoWhitespace.xml", expected);
}

TEST_F(XmlBuilderTest_SingleNode_Empty, File_CloseWhitespace) {
  testFile("data/XmlBuilderTest/SingleNode/Empty/CloseWhitespace.xml", expected);
}
