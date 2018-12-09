cmake_minimum_required(VERSION 3.5)


find_program(ICC_PATH icc)
find_program(ICPC_PATH icpc)

set(CMAKE_CXX_COMPILER ${ICPC_PATH})
set(CMAKE_C_COMPILER ${ICC_PATH})

project(Optimization-course CXX)
set(CMAKE_MODULE_PATH ${CMAKE_HOME_DIRECTORY}/cmake)
find_package(AVX REQUIRED)

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    message(STATUS "CMAKE_BUILD_TYPE not defined, 'Release' will be used")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic -Wextra -mavx")
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

message(STATUS "BUILD_CONFIGURATION: ${CMAKE_BUILD_TYPE}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/${CMAKE_BUILD_TYPE}/)

add_subdirectory(common)
add_subdirectory(src)
include_directories(${INCLUDE_DIR})

add_subdirectory(perf_test)
