cmake_minimum_required(VERSION 3.24.2 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "D:/boost-build")
set(BOOST_INCLUDEDIR "D:/boost-build/include/boost-1_86/")
set(Boost_USE_STATIC_RUNTIME ON)

project(testproj VERSION 1.0.0)

file(GLOB_RECURSE files
    "src/*.h"
    "src/*.hpp"
    "src/*.c"
    "src/*.cpp"
)

set(BOOST_LIBRARIES Boost::unit_test_framework Boost::system Boost::filesystem)

add_executable(${PROJECT_NAME} ${files})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${files})

if(Boost_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
    message(STATUS "Found BOOST ${Boost_VERSION_STRING}")
else()
    message(STATUS "WEBSOCKET BOOST Not Found")
endif()