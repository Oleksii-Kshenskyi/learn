cmake_minimum_required(VERSION 3.10)

project(wls) # word letters shuffler
set(CMAKE_BUILD_TYPE Release)
set(LIB_DIR src/lib)
set(SHUFFLER_DIR src/shuffler) 

set(SHUFFLER_SRC ${SHUFFLER_DIR}/main.cpp)
include_directories(src/lib)

add_executable(${PROJECT_NAME} ${SHUFFLER_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17
                                      CMAKE_CXX_STANDARD_REQUIRED ON)
# set_target_property(${PROJECT_NAME} CXX_STANDARD_REQUIRED ON)