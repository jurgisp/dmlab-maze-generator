cmake_minimum_required(VERSION 3.0.0)
project(dmlab-maze-generator VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

add_executable(dmlab-maze-generator 
                tests/main.cpp
                src/algorithm.cc
                src/text_maze.cc
                src/flood_fill.cc
                src/maze_generator.cc
                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
