cmake_minimum_required(VERSION 3.23)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/dist/${CMAKE_SYSTEM_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

install(FILES "eBid_Monthly_Sales_Dec_2016.csv" "eBid_Monthly_Sales.csv" DESTINATION ${CMAKE_SOURCE_DIR}/dist/${CMAKE_SYSTEM_NAME}
        PERMISSIONS OWNER_WRITE OWNER_READ)

add_executable(${PROJECT_NAME} LinkedList.cpp CSVparser.cpp CSVparser.hpp)
