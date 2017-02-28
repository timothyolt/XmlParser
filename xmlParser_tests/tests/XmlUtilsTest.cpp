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

TEST_F(XmlUtilsTest, DepthFirstSearch_DoNotFind) {
  EXPECT_TRUE(XmlUtils::searchDf(&xml, XmlAttribute("test", "")) == nullptr);
}

TEST_F(XmlUtilsTest, BreadthFirstSearch_DoNotFind) {
  EXPECT_TRUE(XmlUtils::searchBf(&xml, XmlAttribute("test", "")) == nullptr);
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
                      XmlAttribute("behavior", ""), XmlAttribute("response", "Evade")
                  })
              })
          }),
          XmlNode("node", std::vector<XmlAttribute> {
              XmlAttribute("behavior", "Combat"), XmlAttribute("response", "")
          }, std::vector<XmlNode> {
              XmlNode("node", std::vector<XmlAttribute> {
                  XmlAttribute("behavior", ""), XmlAttribute("response", "Flee")
              })
          })
      }) {}
};

TEST_F(XmlUtilsTraversalTest, DepthFirstSearch_Ambiguous) {
  EXPECT_STREQ(XmlUtils::searchDf(&xml, XmlAttribute("behavior", ""))
                   ->getConstAttributes()[1]
                   .getValue()
                   .c_str(),
               "Use Computer");
}

TEST_F(XmlUtilsTraversalTest, BreadthFirstSearch_Ambiguous) {
  EXPECT_STREQ(XmlUtils::searchBf(&xml, XmlAttribute("behavior", ""))
                   ->getConstAttributes()[1]
                   .getValue()
                   .c_str(),
               "Flee");
}
