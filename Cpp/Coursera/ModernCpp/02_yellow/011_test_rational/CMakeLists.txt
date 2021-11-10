cmake_minimum_required(VERSION 3.5)

project(111_test_rational LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DONLY_HOME=1)

add_executable(answer main.cpp)

add_executable(solution solution.cpp)
