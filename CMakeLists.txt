cmake_minimum_required(VERSION 3.13)
project(Numbers C)

set(CMAKE_C_STANDARD 99)

add_executable(Numbers main.c conversion.c conversion.h)