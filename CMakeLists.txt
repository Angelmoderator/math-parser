cmake_minimum_required(VERSION 3.16)
project(math_parser CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(math_parser src/main.cpp src/tokenizer.cpp)
target_include_directories(math_parser PRIVATE include)


include(FetchContent)
FetchContent_Declare(Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.2)
FetchContent_MakeAvailable(Catch2)

add_executable(tests tests/test_tokenizer.cpp src/tokenizer.cpp)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)



