cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(T28_HW main.cpp
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
        DateTime/DT.h
        DateTime/DT.cpp
        Exeption.cpp
        Exeption.h
        Menus/Menu.cpp
        Menus/Menu.h
        Publication/Book/TextBook.cpp
)
