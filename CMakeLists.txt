cmake_minimum_required(VERSION 3.20)
project(ProjektKoncowy)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjektKoncowy source/main.cpp source/Patient.cpp include/Patient.h source/Doctor.cpp include/Doctor.h include/User.h source/User.cpp source/functions.cpp include/functions.h)
