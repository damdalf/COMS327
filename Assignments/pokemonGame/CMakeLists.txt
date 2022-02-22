cmake_minimum_required(VERSION 3.21)
project(pokemonGame C)

set(CMAKE_C_STANDARD 99)

add_executable(pokemonGame map.h map.c world.h world.c poke327.c priorityQueue.h)
