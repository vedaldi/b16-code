cmake_minimum_required(VERSION 3.20)
project(B16-Algorithms-Code VERSION 1.0)

option(BUILD_EXERCISES "Build exercises" ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall")

add_subdirectory(part-1)
add_subdirectory(part-2)
add_subdirectory(part-3)
add_subdirectory(part-4)
add_subdirectory(extras)
