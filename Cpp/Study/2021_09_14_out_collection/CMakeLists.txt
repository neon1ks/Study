cmake_minimum_required(VERSION 3.5)

project(out_collection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(out_collection main.cpp)

add_executable(original original.cpp)
