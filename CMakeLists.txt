cmake_minimum_required(VERSION 3.14)
project(perm152 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O0 -std=c99 -Werror -Wall -Wextra -Wconversion -fsanitize=address")

add_executable(hw4 main.c perm152.c hw4_perm152hash.c)