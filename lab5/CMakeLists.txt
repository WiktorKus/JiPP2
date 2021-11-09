cmake_minimum_required(VERSION 3.20)
project(lab5)

include_directories(include)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab5 src/main.cpp src/Car.cpp)
