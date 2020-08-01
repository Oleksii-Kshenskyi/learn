cmake_minimum_required(VERSION 3.17.3)
project(effective_modern_cpp_tinkering)

add_definitions("-std=c++17 -fconcepts-ts")

set(CMAKE_BUILD_TYPE Debug)
set(SRC_DIR src)

add_executable(five ${SRC_DIR}/five.cpp)