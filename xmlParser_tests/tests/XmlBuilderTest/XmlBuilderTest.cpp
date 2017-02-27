// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <fstream>
#include <XmlBuilder.hpp>
#include "XmlBuilderTest.hpp"

XmlBuilderTest::XmlBuilderTest() : xmlBuilder() {}

void XmlBuilderTest::testString(std::string string, const XmlNode& expected) {
  std::stringstream stringstream(string);
  xmlBuilder.build(stringstream);
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

void XmlBuilderTest::testFile(std::string filename, const XmlNode& expected) {
  std::ifstream file;
  file.open(filename);
  ASSERT_TRUE(file.is_open());
  xmlBuilder.build(file);
  file.close();
  ASSERT_TRUE(xmlBuilder.valid());
  auto actual(xmlBuilder.get());
  EXPECT_TRUE(expected == actual);
}

TEST_F(XmlBuilderTest, Stream_Input) {
  std::stringstream streama("<root/>");
  // while (streama >> xmlBuilder) continue;
  std::stringstream streamb("<root />");
  // while (streamb >> xmlBuilder) continue;
  std::stringstream streamc("<root attribute=\"Weapon 1\" />");
  // while (streamc >> xmlBuilder) continue;
  std::stringstream streamd("<root>\n"
                            "    <node behavior=\"Idle\" response=\"\">\n"
                            "        <node behavior=\"\" response=\"Use Computer\"/>\n"
                            "        <node behavior=\"\" response=\"Patrol\"/>\n"
                            "    </node>\n"
                            "    <node behavior=\"Incoming Projectile\">\n"
                            "        <node behavior=\"\" response=\"Evade\"/>\n"
                            "    </node>\n"
                            "    <node behavior=\"Combat\" response=\"\">\n"
                            "        <node behavior=\"Melee\" response=\"\">\n"
                            "            <node behavior=\"\" response=\"Flee\"/>\n"
                            "            <node behavior=\"\" response=\"Attack\"/>\n"
                            "        </node>\n"
                            "        <node behavior=\"Ranged\" response=\"\">\n"
                            "            <node behavior=\"\" response=\"Weapon 1\"/>\n"
                            "            <node behavior=\"\" response=\"Weapon 2\"/>\n"
                            "            <node behavior=\"\" response=\"Weapon 3\"/>\n"
                            "        </node>\n"
                            "    </node>\n"
                            "</root>");
  std::ifstream streame;
  streame.open("data/example.xml");
  ASSERT_TRUE(streame.is_open());
  xmlBuilder.build(streame);
  streame.close();
  EXPECT_TRUE(true);
}
