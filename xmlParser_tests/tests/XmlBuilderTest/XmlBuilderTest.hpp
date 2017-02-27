// Copyright 2017 Timothy Oltjenbruns.

#ifndef XMLPARSER_XMLBUILDERTEST_HPP
#define XMLPARSER_XMLBUILDERTEST_HPP

#include <gtest/gtest.h>
#include <XmlNode.hpp>
#include <XmlBuilder.hpp>

class XmlBuilderTest : public ::testing::Test {
 public:
  XmlBuilder xmlBuilder;
 protected:
  XmlBuilderTest();
};

#endif  // XMLPARSER_XMLBUILDERTEST_HPP
