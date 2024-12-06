cmake_minimum_required(VERSION 3.24.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(testproj VERSION 1.0.0)

file (GLOB_RECURSE files
    "src/*.h"
    "src/*.hpp"
    "src/*.c"
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${files})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${files})
