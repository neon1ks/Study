cmake_minimum_required(VERSION 3.5)

project(average_temperature_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(answer main.cpp)

add_executable(solution solution.cpp)
