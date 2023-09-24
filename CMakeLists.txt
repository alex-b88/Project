cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project
        main.cpp
        Date.h
        Time.h
        Time.cpp
        Date.cpp)
