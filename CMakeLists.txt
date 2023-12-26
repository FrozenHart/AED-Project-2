cmake_minimum_required(VERSION 3.26)
project(AED_Project_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(AED_Project_2 main.cpp
        Classes/UI.cpp
        Classes/UI.h
        Classes/FileReader.cpp
        Classes/FileReader.h
        Classes/Operations.cpp
        Classes/Operations.h
        Classes/Statistics.cpp
        Classes/Statistics.h
        Classes/Airline.cpp
        Classes/Airline.h
        Classes/Airport.cpp
        Classes/Airport.h
        Classes/FileReader.cpp)
