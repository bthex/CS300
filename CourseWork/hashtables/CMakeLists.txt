cmake_minimum_required(VERSION 3.23)
project(hashtables)

set(CMAKE_CXX_STANDARD 11)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/dist/${CMAKE_SYSTEM_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

add_executable(${PROJECT_NAME} HashTable.cpp CSVparser.cpp CSVparser.hpp)
