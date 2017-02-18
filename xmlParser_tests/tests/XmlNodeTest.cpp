// Copyright 2017 Timothy Oltjenbruns.

#include <XmlNode.hpp>
#include "gtest/gtest.h"

class XmlNodeTest : public ::testing::Test {
 public:
  XmlNode xmlNode;
 protected:
  XmlNodeTest() : xmlNode("abcd",
                          std::vector<XmlAttribute> { XmlAttribute("efgh", "ijkl") },
                          std::vector<XmlNode> { XmlNode("mnop") }) {}
};

TEST_F(XmlNodeTest, Constructor_Blank_Name) {
  // Test that a blank name crashes the process
  EXPECT_DEATH(XmlNode(""), "");
  EXPECT_DEATH(XmlNode("", std::vector<XmlAttribute>()), "");
  EXPECT_DEATH(XmlNode("", std::vector<XmlAttribute>(), std::vector<XmlNode>()), "");
}

TEST_F(XmlNodeTest, Constructor_Sanity) {
  // Test constructor input sanity
  EXPECT_STREQ("abcd", xmlNode.getName().c_str());
  EXPECT_STREQ("efgh", xmlNode.getAttributes()[0].getKey().c_str());
  EXPECT_STREQ("mnop", xmlNode.getChildren()[0].getName().c_str());
}

TEST_F(XmlNodeTest, Property_Name) {
  EXPECT_DEATH(xmlNode.setName(""), "");
  xmlNode.setName("qrst");
  EXPECT_STREQ("qrst", xmlNode.getName().c_str());
}

TEST_F(XmlNodeTest, Property_Attributes) {
  xmlNode.setAttributes(std::vector<XmlAttribute> { XmlAttribute("uvwx", "yz") });
  EXPECT_STREQ("uvwx", xmlNode.getAttributes()[0].getKey().c_str());
}

TEST_F(XmlNodeTest, Property_Attributes_Mutability) {
  xmlNode.getAttributes()[0].setKey("5678");
  // Test vector member mutability
  EXPECT_STREQ("5678", xmlNode.getAttributes()[0].getKey().c_str());
  xmlNode.getAttributes().resize(2);
  xmlNode.getAttributes()[1] = XmlAttribute("90AB", "CDEF");
  // Test vector mutability
  EXPECT_STREQ("90AB", xmlNode.getAttributes()[1].getKey().c_str());
}

TEST_F(XmlNodeTest, Property_Children) {
  xmlNode.setChildren(std::vector<XmlNode> { XmlNode("1234") });
  EXPECT_STREQ("1234", xmlNode.getChildren()[0].getName().c_str());
}

TEST_F(XmlNodeTest, Property_Children_Mutability) {
  xmlNode.getChildren()[0].setName("GHIJ");
  // Test vector member mutability
  EXPECT_STREQ("GHIJ", xmlNode.getChildren()[0].getName().c_str());
  xmlNode.getChildren().resize(2);
  xmlNode.getChildren()[1] = XmlNode("KLMN");
  // Test vector mutability
  EXPECT_STREQ("KLMN", xmlNode.getChildren()[1].getName().c_str());
}
