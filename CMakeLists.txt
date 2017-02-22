cmake_minimum_required(VERSION 3.6)
project(XmlParser)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules-sonar")

if(CMAKE_BUILD_TYPE STREQUAL "Analysis")
    include(SonarAnalysis)
    ADD_TARGET_SONAR("Analysis" "xmlParser" "xmlParser_tests" "xmlParser_tests/tests/run_tests")
endif()

include_directories(xmlParser)

add_subdirectory(xmlParser)
add_subdirectory(xmlParser_implementation)
add_subdirectory(xmlParser_tests)
