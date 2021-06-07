cmake_minimum_required(VERSION 3.5)

project(use_nuspell LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Nuspell CONFIG REQUIRED)

add_executable(use_nuspell main.cpp)

target_link_libraries(use_nuspell Nuspell::nuspell)
