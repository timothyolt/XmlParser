cmake_minimum_required(VERSION 3.6)
project(xmlParser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES XmlNode.cpp XmlNode.hpp XmlAttribute.cpp XmlAttribute.hpp)

add_library(xmlParser STATIC ${SOURCE_FILES})
