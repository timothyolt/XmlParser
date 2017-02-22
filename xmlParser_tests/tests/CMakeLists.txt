include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(run_tests XmlAttributeTest.cpp XmlNodeTest.cpp XmlBuilderTest.cpp)

configure_file(data/example.xml data/example.xml COPYONLY)
configure_file(data/exampleWhitespace.xml data/exampleWhitespace.xml COPYONLY)

target_link_libraries(run_tests gtest gtest_main)
target_link_libraries(run_tests xmlParser)
