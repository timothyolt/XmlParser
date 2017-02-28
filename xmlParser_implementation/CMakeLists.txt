cmake_minimum_required(VERSION 3.6)
project(xmlParser_implementation)

add_executable(run_xmlParser main.cpp)

configure_file(behaviorTree.xml behaviorTree.xml COPYONLY)

target_link_libraries(run_xmlParser xmlParser)
