// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <XmlBuilder.hpp>

class XmlBuilderTest : public ::testing::Test {
 public:
  XmlBuilder xmlBuilder;
 protected:
  XmlBuilderTest() : xmlBuilder() {}
};

TEST_F(XmlBuilderTest, Stream_Input) {
  std::stringstream streama("<root/>");
  streama >> xmlBuilder;
  std::stringstream streamb("<root />");
  streamb >> xmlBuilder;
  std::stringstream streamc("<root attribute=\"Weapon 1\" />");
  streamc >> xmlBuilder;
}