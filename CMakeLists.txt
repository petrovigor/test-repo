cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

set(CMAKE_CXX_STANDARD 17) 

add_executable(${PROJECT_NAME} main.cpp candle.cpp candle.h) 