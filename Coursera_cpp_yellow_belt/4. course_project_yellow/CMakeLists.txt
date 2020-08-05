cmake_minimum_required(VERSION 3.16)
project(course_project_yellow)

set(CMAKE_CXX_STANDARD 17)

add_executable(course_project_yellow main.cpp node.cpp database.cpp condition_parser.cpp token.cpp condition_parser_test.cpp date.cpp database_test.cpp date_test.cpp node_test.cpp)