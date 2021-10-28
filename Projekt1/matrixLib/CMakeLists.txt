cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)

include_directories(matrixLib)

add_library(matrixLib STATIC src/matrixLib.cpp)