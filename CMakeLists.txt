cmake_minimum_required(VERSION 3.24)
project(HealthDemo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HealthDemo
        main.cpp
        People.cpp
        People.h)
