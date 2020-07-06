cmake_minimum_required(VERSION 3.13)

project(virtual_machine C)
set(CMAKE_C_STANDARD 99)

include_directories(includes)

add_executable(virtual_machine srcs/main.c)