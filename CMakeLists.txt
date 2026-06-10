cmake_minimum_required(VERSION 3.16)
project(math_parser CXX)
add_executable(math_parser src/main.cpp)
target_include_directories(math_parser PRIVATE include)
