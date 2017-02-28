// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <fstream>
#include <XmlBuilder.hpp>
#include "XmlBuilderTest.hpp"

class XmlBuilderTest_Examples : public XmlBuilderTest {
 public:
  const XmlNode expected;

 protected:
  XmlBuilderTest_Examples() :
      XmlBuilderTest(),
      expected("root", std::vector<XmlAttribute>(), std::vector<XmlNode> {
          XmlNode("node", std::vector<XmlAttribute> {
              XmlAttribute("behavior", "Idle"), XmlAttribute("response", "")
          }, std::vector<XmlNode> {
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", ""), XmlAttribute("response", "Use Computer")
              }),
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", ""), XmlAttribute("response", "Patrol")
              })
          }),
          XmlNode("node", std::vector<XmlAttribute> {
              XmlAttribute("behavior", "Incoming Projectile")
          }, std::vector<XmlNode> {
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", ""), XmlAttribute("response", "Evade")
              })
          }),
          XmlNode("node", std::vector<XmlAttribute> {
            XmlAttribute("behavior", "Combat"), XmlAttribute("response", "")
          }, std::vector<XmlNode> {
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", "Melee"), XmlAttribute("response", "")
              }, std::vector<XmlNode> {
                  XmlNode("node", std::vector<XmlAttribute> {
                      XmlAttribute("behavior", ""), XmlAttribute("response", "Flee")
                  }),
                  XmlNode("node", std::vector<XmlAttribute> {
                      XmlAttribute("behavior", ""), XmlAttribute("response", "Attack")
                  })
              }),
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", "Ranged"), XmlAttribute("response", "")
              }, std::vector<XmlNode> {
                  XmlNode("node", std::vector<XmlAttribute> {
                      XmlAttribute("behavior", ""), XmlAttribute("response", "Weapon 1")
                  }),
                  XmlNode("node", std::vector<XmlAttribute> {
                      XmlAttribute("behavior", ""), XmlAttribute("response", "Weapon 2")
                  }),
                  XmlNode("node", std::vector<XmlAttribute> {
                      XmlAttribute("behavior", ""), XmlAttribute("response", "Weapon 3")
                  })
              })
          })
      }) {}
};

TEST_F(XmlBuilderTest_Examples, String_Example) {
  testString("<root>\n"
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
             "</root>",
             expected);
}

TEST_F(XmlBuilderTest_Examples, String_ExampleWhitespace) {
  testString("<root\n"
             ">\n"
             "    <node\n"
             "            behavior\n"
             "                    =\n"
             "                    \"Idle\"\n"
             "            response\n"
             "                    =\n"
             "                    \"\"\n"
             "    >\n"
             "        <node\n"
             "                behavior\n"
             "                        =\n"
             "                        \"\"\n"
             "                response\n"
             "                        =\n"
             "                        \"Use Computer\"\n"
             "        />\n"
             "        <node\n"
             "                behavior\n"
             "                        =\n"
             "                        \"\"\n"
             "                response\n"
             "                        =\n"
             "                        \"Patrol\"\n"
             "        />\n"
             "    </node\n"
             "    >\n"
             "    <node\n"
             "            behavior\n"
             "                    =\n"
             "                    \"Incoming Projectile\"\n"
             "    >\n"
             "        <node\n"
             "                behavior\n"
             "                        =\n"
             "                        \"\"\n"
             "                response\n"
             "                        =\n"
             "                        \"Evade\"\n"
             "        />\n"
             "    </node\n"
             "    >\n"
             "    <node\n"
             "            behavior\n"
             "                    =\n"
             "                    \"Combat\"\n"
             "            response\n"
             "                    =\n"
             "                    \"\"\n"
             "    >\n"
             "        <node\n"
             "                behavior\n"
             "                        =\n"
             "                        \"Melee\"\n"
             "                response\n"
             "                        =\n"
             "                        \"\"\n"
             "        >\n"
             "            <node\n"
             "                    behavior\n"
             "                            =\n"
             "                            \"\"\n"
             "                    response\n"
             "                            =\n"
             "                            \"Flee\"\n"
             "            />\n"
             "            <node\n"
             "                    behavior\n"
             "                            =\n"
             "                            \"\"\n"
             "                    response\n"
             "                            =\n"
             "                            \"Attack\"\n"
             "            />\n"
             "        </node\n"
             "        >\n"
             "        <node\n"
             "                behavior\n"
             "                        =\n"
             "                        \"Ranged\"\n"
             "                response\n"
             "                        =\n"
             "                        \"\"\n"
             "        >\n"
             "            <node\n"
             "                    behavior\n"
             "                            =\n"
             "                            \"\"\n"
             "                    response\n"
             "                            =\n"
             "                            \"Weapon 1\"\n"
             "            />\n"
             "            <node\n"
             "                    behavior\n"
             "                            =\n"
             "                            \"\"\n"
             "                    response\n"
             "                            =\n"
             "                            \"Weapon 2\"\n"
             "            />\n"
             "            <node\n"
             "                    behavior\n"
             "                            =\n"
             "                            \"\"\n"
             "                    response\n"
             "                            =\n"
             "                            \"Weapon 3\"\n"
             "            />\n"
             "        </node\n"
             "        >\n"
             "    </node\n"
             "    >\n"
             "</root\n"
             ">",
             expected);
}

TEST_F(XmlBuilderTest_Examples, File_Example) {
  testFile("data/example.xml", expected);
}

TEST_F(XmlBuilderTest_Examples, File_ExampleWhitespace) {
  testFile("data/exampleWhitespace.xml", expected);
}
