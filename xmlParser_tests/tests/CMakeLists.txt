include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(run_tests
        XmlAttributeTest.cpp
        XmlNodeTest.cpp
        XmlBuilderTest/XmlBuilderTest.cpp
        XmlBuilderTest/XmlBuilderTest_SingleNode_Empty.cpp
        XmlBuilderTest/XmlBuilderTest.hpp
        XmlBuilderTest/XmlBuilderTest_SingleNode_BlankAttribute.cpp
        XmlBuilderTest/XmlBuilderTest_SingleNode_WhitespaceAttribute.cpp
        XmlBuilderTest/XmlBuilderTest_SingleChild_Empty.cpp XmlBuilderTest/XmlBuilderTest_Examples.cpp XmlUtilsTest.cpp)

add_subdirectory("data")

target_link_libraries(run_tests gtest gtest_main)
target_link_libraries(run_tests xmlParser)
