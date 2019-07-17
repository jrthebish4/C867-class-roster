cmake_minimum_required(VERSION 3.14)
project(C867_JakobBishop)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(C867_JakobBishop
        degree.h
        networkStudent.cpp
        networkStudent.h
        roster.cpp
        roster.h
        securityStudent.cpp
        securityStudent.h
        softwareStudent.cpp
        softwareStudent.h
        student.cpp
        student.h)
