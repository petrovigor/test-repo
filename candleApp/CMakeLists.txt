cmake_minimum_required(VERSION 3.24.2)

project(main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp)

target_link_libraries(main
    PRIVATE candleLib)

