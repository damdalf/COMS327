cmake_minimum_required(VERSION 3.21)
project(assignment1_01_djamdahl C)

set(CMAKE_C_STANDARD 99)

add_executable(assignment1_01_djamdahl mapGeneration.c map.h mapGenerationNonStruct.c)
