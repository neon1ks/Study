cmake_minimum_required(VERSION 3.5)

project(02_reverse_after LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(02_reverse_after main.cpp)

add_executable(other other.cpp)
