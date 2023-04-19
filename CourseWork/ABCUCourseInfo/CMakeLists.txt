cmake_minimum_required(VERSION 3.23)
project(ABCUCourseInfo)

set(CMAKE_CXX_STANDARD 14)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/dist/${CMAKE_SYSTEM_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

add_executable(${PROJECT_NAME} BinarySearchTree.cpp)
