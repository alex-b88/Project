cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project
        main.cpp
        DateTime/DT.h
        DateTime/DT.cpp
        Customer.cpp
        Customer.h
        Publication/Publication.cpp
        Publication/Publication.h
        Publication/Book/Book.cpp
        Publication/Book/Book.h
        Publication/Article/Article.cpp
        Publication/Article/Article.h
        Publication/Electronic/Electronic.cpp
        Publication/Electronic/Electronic.h
        Arhive.cpp
        Arhive.h
)
