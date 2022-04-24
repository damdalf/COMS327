//
// Created by Devin Amdahl on 2/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

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
//#define NUM_TRAINERS 10

#define BORDER '%'
#define PATH '#'
#define TREE '^'
#define CLEARING '.'
#define GRASS ':'
#define ROCK 'O'
#define FLOWER '*'
#define MART 'M'
#define CENTER 'C'

#define PLAYER '@'
#define HIKERS 'h'
#define RIVALS 'r'
#define PACERS 'p'
#define WANDERERS 'w'
#define STATIONARIES 's'
#define RANDOM_WALKERS 'n'

typedef struct coordinates
{
    int x, y;
} coordinates_t;

typedef struct cost_node
{
    int priority;
    coordinates_t coords;
    bool visited;
    struct cost_node* next;
} cost_node_t;

typedef struct character
{
    // Stores the value of the character's x position (row).
    int xPos;
    // Stores the value of the character's y position (column).
    int yPos;
    // Stores the text representation of the character.
    char symbol;
    // Stores the text representation of the terrain in which the character is standing upon.
    char previousTerrain;
    // Stores the direction that the character is facing.
    int direction;
    // Stores the index of the NPC's next move.
    coordinates_t nextMove;
    // This 2D array stores the cost map for the PC.
    cost_node_t costMap[HEIGHT][WIDTH];
    // Prev array of coordinates that stores the shortest path to the PC for each NPC. Not used for the PC.
    coordinates_t prev[HEIGHT * WIDTH]; // TODO might not be needed
} character_t;

typedef struct map // TODO add a 'char characterMap[HEIGHT][WIDTH]', overlay this over the mapArray before printing.
{
    // This 2D array is how the map will actually be stored and represented in the terminal.
    char mapArray[HEIGHT][WIDTH];
    // This 2D array stores the locations of the characters.
    char characterArray[HEIGHT][WIDTH];

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

    // This variable stores the combined length of N-S and the E-W paths.
    int pathCount;

    // Represents the PC.
    character_t pc;

    // Represents the Trainers. This is an array as the number of Trainers is dynamic.
    character_t **trainers;

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

/*
 * Additionally, randomly generates a single Trainer into the map based off of their corresponding constraints:
 *  - No NPC may spawn or move into a cell wherein the movement cost for that NPC type is infinity.
 *  - No NPC will spawn in a cell occupied by another character.
 *  - No NPC will spawn in or move to an exit or border.
 */
void generateNPC(map_t *m, int k);

// Function to generate each Trainer character using 'generateCharacter()' based on the NUM_TRAINERS.
void generateNPCs(map_t *m, int NUM_TRAINERS);

// Function to initialize the characterArray to sentinel values of 'Z'.
void initializeCharacterArray(map_t *m);

// Function to randomly choose a location on a road (and not on the border) for the player character to be generated.
void generatePC(map_t *m);

// Function to print the contents of the map.
void printMap(map_t *m);

// Function to randomly generate the map using a seed.
void seededGeneration(map_t *m);

// Function to randomly generate the map.
void randomGeneration(map_t *m, const int NUM_TRAINERS);

// Function to randomly choose a direction for the directionally-oriented Trainers.
void generateDirections(map_t *m, int k);

// Function to generate (in memory and in the map) the minimum number of Trainers.
void initializeTrainers(map_t *m, const int NUM_TRAINERS);

// Initialize the cost maps to NULL at every position in the 2D array.
void initializeCostMaps(map_t *m, const int NUM_TRAINERS);

// Function to initialize the cost map for the PC.
void initializePlayerCostMap(map_t *m);

// Function to initialize the cost maps for the map's Trainers.
void initializeHikersAndRivalsCostMaps(map_t *m, const int NUM_TRAINERS);

// Function to print the Player's cost map.
void printPlayerCostMap(map_t *m);

// Function to print a Hikers or Rivals cost map.
void printHikersAndRivalsCostMap(map_t *m, int k);

// Function to print the Trainer's cost maps.
void printHikersAndRivalsCostMaps(map_t *m, const int NUM_TRAINERS);

#endif