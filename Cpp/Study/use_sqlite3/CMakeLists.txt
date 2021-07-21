cmake_minimum_required(VERSION 3.5)

project(use_sqlite3 LANGUAGES CXX)

find_package (SQLite3 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${SQLite3_INCLUDE_DIRS})

add_executable(use_sqlite3 main.cpp)

target_link_libraries (use_sqlite3 ${SQLite3_LIBRARIES})
