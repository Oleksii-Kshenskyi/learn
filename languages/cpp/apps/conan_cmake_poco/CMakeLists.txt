cmake_minimum_required(VERSION 3.17.3)
project(conan_cmake_poco)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/../conanbuildinfo.cmake)
conan_basic_setup()

add_executable(cocmpo md5.cpp)
target_link_libraries(cocmpo ${CONAN_LIBS})