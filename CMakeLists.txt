cmake_minimum_required(VERSION 3.9)
project(ttt C)

set(CMAKE_C_STANDARD 99)

add_executable(ttt main.c include/ttt.h src/ttt.c)