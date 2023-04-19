cmake_minimum_required(VERSION 3.23)
project(VectorSort)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_NAME})

add_executable(VectorSort
        CSVparser.cpp
        CSVparser.hpp
        VectorSorting.cpp)