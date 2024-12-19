cmake_minimum_required(VERSION 3.29)
project(AlgoLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(AlgoLib
    include/algorithms.h
    include/dataStructures.h
    src/algorithms.cpp
    src/dataStructures.cpp)
