cmake_minimum_required(VERSION 3.20)
project(simpleCalc)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(simpleCalc src/main.cpp src/calc.cpp)

target_link_libraries(simpleCalc pthread)