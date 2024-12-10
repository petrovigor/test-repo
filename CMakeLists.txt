cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

file(GLOB TEST_SOURCES candle.cpp candle.h "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp")

add_executable(unit_tests ${TEST_SOURCES})
target_link_libraries(unit_tests gtest gtest_main)

gtest_discover_tests(unit_tests)