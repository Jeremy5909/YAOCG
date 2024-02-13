cmake_minimum_required(VERSION 3.27)
project(Zombielife3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Zombielife3 main.cpp
        Object.cpp
        Object.h
        Toggleable.cpp
        Toggleable.h
        Room.cpp
        Room.h
        Chest.cpp
        Chest.h
        Item.cpp
        Item.h)
