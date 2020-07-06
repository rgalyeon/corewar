cmake_minimum_required(VERSION 3.13)

project(virtual_machine C)
set(CMAKE_C_STANDARD 99)

include_directories(includes)
include_directories(../libft/includes)

aux_source_directory(srcs/ src)

add_executable(virtual_machine ${src})
target_link_libraries(virtual_machine $ENV{HOME}/CLionProjects/corewar/libft/libft.a)