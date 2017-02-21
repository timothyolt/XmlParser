// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <XmlBuilder.hpp>

class XmlBuilderTest : public ::testing::Test {
 public:
  XmlBuilder xmlBuilder;
 protected:
  XmlBuilderTest() : xmlBuilder() {}
};


TEST_F(XmlBuilderTest, Stream_Input_SingleNode) {
  std::stringstream stream("<root/>");
  xmlBuilder.readStream(stream);
  EXPECT_TRUE(true);
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
  while (streamd >> xmlBuilder) continue;
  EXPECT_TRUE(true);
}
