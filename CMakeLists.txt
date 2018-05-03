cmake_minimum_required(VERSION 3.7)
project(kostov_oop)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp container.h Base.h Shapes.h)
add_executable(kostov_oop ${SOURCE_FILES})