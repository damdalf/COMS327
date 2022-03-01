cmake_minimum_required(VERSION 3.21)
project(327PokeGame C)

set(CMAKE_C_STANDARD 99)

add_executable(327PokeGame poke327.c map.h map.c world.h world.c priorityQueue.h priorityQueue.c dijkstrasAlgorithm.h dijkstrasAlgorithm.c)
