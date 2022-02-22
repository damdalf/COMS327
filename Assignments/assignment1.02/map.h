//
// Created by Devin Amdahl on 2/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#ifndef MAP_H
#define MAP_H

// COLORS:
#define BLK   "\e[30m"
#define RED   "\e[31m"
#define GRN   "\e[32m"
#define YEL   "\e[33m"
#define BLU   "\e[34m"
#define MAG   "\e[35m"
#define CYN   "\e[36m"
#define WHT   "\e[37m"

// BOLD COLORS:
#define B_BLK   "\e[30;1m"
#define B_RED   "\e[31;1m"
#define B_GRN   "\e[32;1m"
#define B_YEL   "\e[33;1m"
#define B_BLU   "\e[34;1m"
#define B_MAG   "\e[35;1m"
#define B_CYN   "\e[36;1m"
#define B_WHT   "\e[37;1m"

// RESET COLOR:
#define RESET "\e[0m"

#define HEIGHT 21
#define WIDTH 80
#define BORDER '%'
#define PATH '#'
#define TREE '^'
#define CLEARING '.'
#define GRASS ':'
#define ROCK '@'
#define FLOWER '*'

typedef struct map
{
    // This 2D array is how the map will actually be stored and represented in the terminal.
    char mapArray[HEIGHT][WIDTH];

    // The following variables store the coordinates of map's exits.
    int northExit[2];
    int eastExit[2];
    int southExit[2];
    int westExit[2];

    // The following variables store the 'source' coordinates of the tall grass regions.
    int tallGrassOne[2];
    int tallGrassTwo[2];

    // The following variables store the 'source' coordinates of the forest regions.
    int forestOne[2];
    int forestTwo[2];
} map_t;

// Function to initialize the map with rock borders and filled with clearings.
void initializeMap(map_t *m);

// Function to place the regions to the right on the map.
void placeRegionsRight(map_t *m, char ch, int x, int y);

// Function to place the regions to the left on the map.
void placeRegionsLeft(map_t *m, char ch, int x, int y);

// Function to generate the tall grass and tree regions.
void generateRegions(map_t *m);

// Function to randomly generate and place the exits for the map.
void placeExits(map_t *m);

// Function to manually place the exits based on the direction of the exit, and the passed x and y coordinates.
void manuallyPlaceExits(map_t *m, int northY, int southY, int eastX, int westX);

// Randomly generate the coordinates for the North exit.
void generateNorthExit(map_t *m);

// Randomly generate the coordinates for the East exit.
void generateEastExit(map_t *m);

// Randomly generate the coordinates for the South exit.
void generateSouthExit(map_t *m);

// Randomly generate the coordinates for the West exit.
void generateWestExit(map_t *m);

// Function to generate the N-S and E-W paths.
void buildPaths(map_t *m);

// Function to place the PokeMart along the corresponding path.
void placePokeMart(map_t *m);

// Function to place the PokeCenter along the corresponding path.
void placePokeCenter(map_t *m);

// Function stub for addRandom().
void addRandom(map_t *m);

// Function to ask the user for a seed.
int generateSeed();

// Function to print the map with color.
void printColor(char ch);

// Function to print the contents of the map.
void printMap(map_t *m);

// Function to randomly generate the map using a seed.
void seededGeneration(map_t *m);

// Function to randomly generate the map.
void randomGeneration(map_t *m);

#endif