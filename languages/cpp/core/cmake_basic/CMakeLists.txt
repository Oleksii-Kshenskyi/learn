cmake_minimum_required(VERSION 3.20.0)

project(basic)

set(INC_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIB_DIR ${INC_DIR})
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(SRC_FILES ${SRC_DIR}/main.cpp)
set(LIB_SRC ${SRC_DIR}/inc.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INC_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_CXX_STANDARD 20
                                                 CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(inc SHARED ${LIB_SRC})
target_include_directories(inc PUBLIC ${LIB_DIR})
set_target_properties(inc PROPERTIES CMAKE_CXX_STANDARD 20
                                     CMAKE_CXX_STANDARD_REQUIRED ON)
target_link_libraries(${PROJECT_NAME} inc)

