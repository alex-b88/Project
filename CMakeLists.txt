cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project
        main.cpp
        Date.h
        Time.h
        Time.cpp
        Date.cpp)
