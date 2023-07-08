cmake_minimum_required(VERSION 3.25)
project(private)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(private
        apa.h
        auxFunction.cpp
        FromFile.cpp
        LVquicksort.cpp
        mainAPA.cpp)
