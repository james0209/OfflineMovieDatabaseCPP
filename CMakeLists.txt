cmake_minimum_required(VERSION 3.15)
project(cw2)

set(CMAKE_CXX_STANDARD 20)

add_executable(cw2 main.cpp Movie.cpp Movie.h MovieDatabase.cpp MovieDatabase.h)