// Copyright 2017 Timothy Oltjenbruns

#include <iostream>
#include <XmlNode.hpp>
#include <XmlUtils.hpp>

int main(int argCount, char* args[]) {
  std::cout << "Hello XmlParser World!" << std::endl;
  XmlNode node("name");
  XmlUtils::searchDf(&node, XmlAttribute());
  return 0;
}
