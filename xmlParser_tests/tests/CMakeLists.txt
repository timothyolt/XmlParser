include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(run_tests XmlAttributeTest.cpp XmlNodeTest.cpp XmlBuilderTest/XmlBuilderTest.cpp XmlBuilderTest/XmlBuilderTest_SingleNode_Empty.cpp XmlBuilderTest/XmlBuilderTest.hpp XmlBuilderTest/XmlBuilderTest_SingleNode_BlankAttribute.cpp)

configure_file(
        data/XmlBuilderTest/SingleNode/Empty/NoWhitespace.xml
        data/XmlBuilderTest/SingleNode/Empty/NoWhitespace.xml
    COPYONLY)
configure_file(
        data/XmlBuilderTest/SingleNode/Empty/CloseWhitespace.xml
        data/XmlBuilderTest/SingleNode/Empty/CloseWhitespace.xml
    COPYONLY)
configure_file(
        data/XmlBuilderTest/SingleNode/BlankAttribute/NoWhitespace.xml
        data/XmlBuilderTest/SingleNode/BlankAttribute/NoWhitespace.xml
        COPYONLY)
configure_file(
        data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePre.xml
        data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePre.xml
        COPYONLY)
configure_file(
        data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePost.xml
        data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePost.xml
        COPYONLY)
configure_file(
        data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePrePost.xml
        data/XmlBuilderTest/SingleNode/BlankAttribute/AssignmentWhitespacePrePost.xml
        COPYONLY)
configure_file(
        data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace.xml
        data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace.xml
        COPYONLY)
configure_file(
        data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePre.xml
        data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePre.xml
        COPYONLY)
configure_file(
        data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePost.xml
        data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePost.xml
        COPYONLY)
configure_file(
        data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePrePost.xml
        data/XmlBuilderTest/SingleNode/BlankAttribute/CloseWhitespace_AssignmentWhitespacePrePost.xml
        COPYONLY)
configure_file(data/example.xml data/example.xml COPYONLY)
configure_file(data/exampleWhitespace.xml data/exampleWhitespace.xml COPYONLY)

target_link_libraries(run_tests gtest gtest_main)
target_link_libraries(run_tests xmlParser)
