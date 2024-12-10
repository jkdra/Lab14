cmake_minimum_required(VERSION 3.30)
project(Lab14)

set(CMAKE_CXX_STANDARD 26)

add_executable(Lab14 main.cpp
        header.h
        animalHeader.h
        sheepHeader.h
        pigHeader.h
        animalFunctions.cpp
        pigFunctions.cpp
        functions.cpp
        sheepFunctions.cpp)
