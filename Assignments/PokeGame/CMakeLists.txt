cmake_minimum_required(VERSION 3.21)
project(PokeGame C)

set(CMAKE_C_STANDARD 99)

add_executable(PokeGame poke327.c map.h world.h map.c world.c dijkstrasAlgorithm.h dijkstrasAlgorithm.c priorityQueue.c priorityQueue.h)
