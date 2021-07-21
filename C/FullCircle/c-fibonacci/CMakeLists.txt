cmake_minimum_required(VERSION 3.5)

project(c-fibonacci LANGUAGES C)

find_library(gmp gmp)
if(NOT gmp)
  message(FATAL_ERROR "gmp not found")
endif()

add_executable(c-fibonacci main.c)

target_link_libraries(c-fibonacci gmp)
