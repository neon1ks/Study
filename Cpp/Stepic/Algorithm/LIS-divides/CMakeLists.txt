cmake_minimum_required(VERSION 3.5)

project(LIS-divides LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LIS-divides main.cpp)

add_executable(solution solution.cpp)
