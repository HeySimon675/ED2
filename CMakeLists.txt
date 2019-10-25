cmake_minimum_required(VERSION 3.15)
project(ed2 C)

set(CMAKE_C_STANDARD 99)

add_executable(ed2 main.c heap-max.h heap-max2.h min_heap.h)