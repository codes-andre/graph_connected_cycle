cmake_minimum_required(VERSION 3.8)
project(graph_connected_cycle)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.h Node.h Edge.h)
add_executable(graph_connected_cycle ${SOURCE_FILES} main.cpp Graph.h Node.h Edge.h)