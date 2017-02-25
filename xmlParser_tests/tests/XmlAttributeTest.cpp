// Copyright 2017 Timothy Oltjenbruns

#include <XmlAttribute.hpp>
#include "gtest/gtest.h"

class XmlAttributeTest : public ::testing::Test {
 public:
  XmlAttribute xmlAttribute;
 protected:
  XmlAttributeTest() : xmlAttribute("abcd", "efgh") {}
};

TEST_F(XmlAttributeTest, Constructor_Blank_Key) {
  // Test that a blank key crashes the process
  ASSERT_DEATH(XmlAttribute("", ""), "");
}

TEST_F(XmlAttributeTest, Constructor_Sanity) {
  // Test that the key matches constructor input
  EXPECT_STREQ("abcd", xmlAttribute.getKey().c_str());
  // Test that the value matches constructor input
  EXPECT_STREQ("efgh", xmlAttribute.getValue().c_str());
}

TEST_F(XmlAttributeTest, Property_Key) {
  EXPECT_DEATH(xmlAttribute.setKey(""), "");
  xmlAttribute.setKey("ijkl");
  EXPECT_STREQ("ijkl", xmlAttribute.getKey().c_str());
}

TEST_F(XmlAttributeTest, Property_Value) {
  xmlAttribute.setValue("mnop");
  EXPECT_STREQ("mnop", xmlAttribute.getValue().c_str());
}

TEST_F(XmlAttributeTest, Equality_This) {
  EXPECT_TRUE(xmlAttribute == xmlAttribute);
}

TEST_F(XmlAttributeTest, Equality_New) {
  EXPECT_FALSE(xmlAttribute == XmlAttribute());
}

TEST_F(XmlAttributeTest, Equality_Duplicate) {
  EXPECT_TRUE(xmlAttribute == XmlAttribute(xmlAttribute.getKey(), xmlAttribute.getValue()));
}
