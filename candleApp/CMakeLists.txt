cmake_minimum_required(VERSION 3.24.2)

project(main)

add_executable(main main.cpp)

target_link_libraries(main
    PRIVATE candleLib)
