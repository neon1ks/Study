cmake_minimum_required(VERSION 3.5)

project(f_placement_of_laptops LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DONLY_HOME=1)

add_executable(answer main.cpp)
