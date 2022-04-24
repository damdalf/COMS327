cmake_minimum_required(VERSION 3.21)
project(327PokeGameV2 C)

set(CMAKE_C_STANDARD 99)

add_executable(327PokeGameV2 map.c map.h world.h world.c priorityQueue.h priorityQueue.c dijkstrasAlgorithm.h dijkstrasAlgorithm.c poke327.c character.h movement.h movement.c)
