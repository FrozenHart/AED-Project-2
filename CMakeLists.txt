cmake_minimum_required(VERSION 3.26)
project(2º_ProjetoAED)

set(CMAKE_CXX_STANDARD 17)

add_executable(2º_ProjetoAED main.cpp
        Classes/UI.cpp
        Classes/UI.h
        Classes/FileReader.cpp
        Classes/FileReader.h
        Classes/Operations.cpp
        Classes/Operations.h
        Classes/Statistics.cpp
        Classes/Statistics.h)
