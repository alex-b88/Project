cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project
        main.cpp
        Time/Time.h
        Time/Time.cpp
        Date/Date.h
        Date/Date.cpp
        Customer.cpp
        Customer.h
        )
