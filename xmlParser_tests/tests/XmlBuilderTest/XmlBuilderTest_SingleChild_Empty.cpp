// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <fstream>
#include <XmlBuilder.hpp>
#include "XmlBuilderTest.hpp"

class XmlBuilderTest_SingleChild_Empty : public XmlBuilderTest {
 public:
  const XmlNode expected;
 protected:
  XmlBuilderTest_SingleChild_Empty() :
      XmlBuilderTest(),
      expected("root", std::vector<XmlAttribute>(), std::vector<XmlNode> {
          XmlNode("child")
      }) {}
};

TEST_F(XmlBuilderTest_SingleChild_Empty, String_NoWhitespace) {
  testString("<root><child/></root>", expected);
}

TEST_F(XmlBuilderTest_SingleChild_Empty, String_CloseWhitespace) {
  testString("<root ><child /></root >", expected);
}

TEST_F(XmlBuilderTest_SingleChild_Empty, String_ChildCloseWhitespace) {
  testString("<root><child /></root>", expected);
}

TEST_F(XmlBuilderTest_SingleChild_Empty, String_RootCloseWhitespace) {
  testString("<root ><child/></root >", expected);
}

TEST_F(XmlBuilderTest_SingleChild_Empty, String_CloseNodeWhitespace) {
  testString("<root> <child/> </root>", expected);
}

TEST_F(XmlBuilderTest_SingleChild_Empty, File_NoWhitespace) {
  testFile("data/XmlBuilderTest/SingleChild/Empty/NoWhitespace.xml", expected);
}

TEST_F(XmlBuilderTest_SingleChild_Empty, File_CloseWhitespace) {
  testFile("data/XmlBuilderTest/SingleChild/Empty/CloseWhitespace.xml", expected);
}

TEST_F(XmlBuilderTest_SingleChild_Empty, File_ChildCloseWhitespace) {
  testFile("data/XmlBuilderTest/SingleChild/Empty/ChildCloseWhitespace.xml", expected);
}

TEST_F(XmlBuilderTest_SingleChild_Empty, File_RootCloseWhitespace) {
  testFile("data/XmlBuilderTest/SingleChild/Empty/RootCloseWhitespace.xml", expected);
}

TEST_F(XmlBuilderTest_SingleChild_Empty, File_CloseNodeWhitespace) {
  testFile("data/XmlBuilderTest/SingleChild/Empty/CloseNodeWhitespace.xml", expected);
}
