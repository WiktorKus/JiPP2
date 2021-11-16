cmake_minimum_required(VERSION 3.20)

project(lab6)
include_directories(include)
set(CMAKE_CXX_STANDARD 17)

add_executable(lab6 src/main.cpp src/Node.cpp include/Node.h src/Vector.cpp include/Vector.h)
