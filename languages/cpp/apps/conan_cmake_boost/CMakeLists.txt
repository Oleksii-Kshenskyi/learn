cmake_minimum_required(VERSION 3.17.3)
project(conan_cmake_boost)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/../conanbuildinfo.cmake)
conan_basic_setup()

add_executable(cocmbo boost_serialization.cpp)
target_link_libraries(cocmbo ${CONAN_LIBS})
