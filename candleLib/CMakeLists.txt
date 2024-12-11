cmake_minimum_required(VERSION 3.24.2)

project(candleLib)

file(GLOB SOURCES
    src/candle.cpp
    src/tests.cpp)

add_library(candleLib ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)
