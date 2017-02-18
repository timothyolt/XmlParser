// Copyright 2017 Timothy Oltjenbruns

#include <iostream>
#include <XmlNode.hpp>

int main(int argCount, char* args[]) {
  std::cout << "Hello XmlParser World!" << std::endl;
  XmlNode node("name");
  node.getChildren().reserve(1);
  node.getChildren()[0] = XmlNode(NULL);
  std::cout << node.getChildren()[0].getName() << std::endl;
  return 0;
}
