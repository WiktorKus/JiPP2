cmake_minimum_required(VERSION 3.20)
project (lab9_player)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab9_player source/main.cpp source/Player.cpp include/Player.h)
