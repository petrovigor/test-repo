cmake_minimum_required(VERSION 3.24.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
    testproj
    VERSION 1.0.0
    DESCRIPTION "Test project")

add_subdirectory(candleLib)
add_subdirectory(candleApp)
