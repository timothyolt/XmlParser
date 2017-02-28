// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <XmlNode.hpp>
#include <XmlUtils.hpp>

class XmlUtilsTest : public ::testing::Test {
 public:
  const XmlNode xml;

 protected:
  XmlUtilsTest() :
      xml("root", std::vector<XmlAttribute>(), std::vector<XmlNode> {
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

TEST_F(XmlUtilsTest, DepthFirstSearch_DoNotFind_Functional) {
  EXPECT_TRUE(XmlUtils::searchDf(&xml, [](const XmlNode *node) {
                return std::find(node->getConstAttributes().begin(),
                                 node->getConstAttributes().end(),
                                 XmlAttribute("test", "")) !=
                       node->getConstAttributes().end();
              }) == nullptr);
}

TEST_F(XmlUtilsTest, BreadthFirstSearch_DoNotFind_Functional) {
  EXPECT_TRUE(XmlUtils::searchBf(&xml, [](const XmlNode *node) {
    return std::find(node->getConstAttributes().begin(),
                     node->getConstAttributes().end(),
                     XmlAttribute("test", "")) !=
        node->getConstAttributes().end();
  }) == nullptr);
}

TEST_F(XmlUtilsTest, DepthFirstSearch_DoNotFind_Attribute) {
  EXPECT_TRUE(XmlUtils::searchAttributeDf(&xml, XmlAttribute("test", "")) == nullptr);
}

TEST_F(XmlUtilsTest, BreadthFirstSearch_DoNotFind_Attribute) {
  EXPECT_TRUE(XmlUtils::searchAttributeBf(&xml, XmlAttribute("test", "")) == nullptr);
}

TEST_F(XmlUtilsTest, DepthFirstSearch_DoNotFind_Value) {
  EXPECT_TRUE(XmlUtils::searchValueDf(&xml, "test") == nullptr);
}

TEST_F(XmlUtilsTest, BreadthFirstSearch_DoNotFind_Value) {
  EXPECT_TRUE(XmlUtils::searchValueBf(&xml, "test") == nullptr);
}

class XmlUtilsTraversalTest : public ::testing::Test {
 public:
  const XmlNode xml;

 protected:
  XmlUtilsTraversalTest() :
      xml("root", std::vector<XmlAttribute>(), std::vector<XmlNode> {
          XmlNode("node", std::vector<XmlAttribute> {
              XmlAttribute("behavior", "Idle"), XmlAttribute("response", "")
          }, std::vector<XmlNode> {
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", "Idle 2"), XmlAttribute("response", "")
              }, std::vector<XmlNode> {
                  XmlNode("node", std::vector<XmlAttribute> {
                      XmlAttribute("behavior", "Idle 3"), XmlAttribute("response", "")
                  }, std::vector<XmlNode> {
                      XmlNode("node", std::vector<XmlAttribute> {
                          XmlAttribute("behavior", ""), XmlAttribute("response", "Use Computer")
                      }),
                      XmlNode("node", std::vector<XmlAttribute> {
                          XmlAttribute("behavior", "Search"), XmlAttribute("response", "Depth")
                      })
                  })
              })
          }),
          XmlNode("node", std::vector<XmlAttribute> {
              XmlAttribute("behavior", "Incoming Projectile")
          }, std::vector<XmlNode> {
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", "Incoming Projectile 2")
              }, std::vector<XmlNode> {
                  XmlNode("node", std::vector<XmlAttribute> {
                      XmlAttribute("behavior", ""), XmlAttribute("response", "Search")
                  })
              })
          }),
          XmlNode("node", std::vector<XmlAttribute> {
              XmlAttribute("behavior", "Combat"), XmlAttribute("response", "")
          }, std::vector<XmlNode> {
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", ""), XmlAttribute("response", "Flee")
              }),
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", "Search"), XmlAttribute("response", "Breadth")
              })
          })
      }) {}
};

TEST_F(XmlUtilsTraversalTest, DepthFirstSearch_Ambiguous_Functional) {
  EXPECT_STREQ(
      XmlUtils::searchDf(&xml,
                         [](const XmlNode *node) {
                           return std::find(node->getConstAttributes().begin(),
                                            node->getConstAttributes().end(),
                                            XmlAttribute("behavior", "")) !=
                                  node->getConstAttributes().end();
                         })
          ->getConstAttributes()[1]
          .getValue()
          .c_str(),
      "Use Computer");
}

TEST_F(XmlUtilsTraversalTest, BreadthFirstSearch_Ambiguous_Functional) {
  EXPECT_STREQ(
      XmlUtils::searchBf(&xml,
                         [](const XmlNode *node) {
                           return std::find(node->getConstAttributes().begin(),
                                            node->getConstAttributes().end(),
                                            XmlAttribute("behavior", "")) !=
                               node->getConstAttributes().end();
                         })
          ->getConstAttributes()[1]
          .getValue()
          .c_str(),
      "Flee");
}

TEST_F(XmlUtilsTraversalTest, DepthFirstSearch_Ambiguous_Attribute) {
  EXPECT_STREQ(XmlUtils::searchAttributeDf(&xml, XmlAttribute("behavior", ""))
                   ->getConstAttributes()[1]
                   .getValue()
                   .c_str(),
               "Use Computer");
}

TEST_F(XmlUtilsTraversalTest, BreadthFirstSearch_Ambiguous_Attribute) {
  EXPECT_STREQ(XmlUtils::searchAttributeBf(&xml, XmlAttribute("behavior", ""))
                   ->getConstAttributes()[1]
                   .getValue()
                   .c_str(),
               "Flee");
}

TEST_F(XmlUtilsTraversalTest, DepthFirstSearch_Ambiguous_Value) {
  EXPECT_STREQ(XmlUtils::searchValueDf(&xml, "Search")
                   ->getConstAttributes()[1]
                   .getValue()
                   .c_str(),
               "Depth");
}

TEST_F(XmlUtilsTraversalTest, BreadthFirstSearch_Ambiguous_Value) {
  EXPECT_STREQ(XmlUtils::searchValueBf(&xml, "Search")
                   ->getConstAttributes()[1]
                   .getValue()
                   .c_str(),
               "Breadth");
}
