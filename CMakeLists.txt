cmake_minimum_required(VERSION 3.26)
project(webnode)

set(CMAKE_CXX_STANDARD 17)

add_executable(webnode main.cpp
        Node.cpp
        Node.h
)
