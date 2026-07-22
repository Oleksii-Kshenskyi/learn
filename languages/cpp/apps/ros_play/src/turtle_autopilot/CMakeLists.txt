cmake_minimum_required(VERSION 4.0)
project(turtle_autopilot)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)
find_package(std_srvs REQUIRED)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/autopilot_node.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON)
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})

ament_target_dependencies(${PROJECT_NAME}
    rclcpp
    geometry_msgs
    turtlesim
    std_srvs)

install(TARGETS turtle_autopilot DESTINATION lib/${PROJECT_NAME})

ament_package()