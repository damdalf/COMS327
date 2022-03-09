//
// Created by Devin Amdahl on 2/11/22.
//

#ifndef WORLD_H
#define WORLD_H

#define WORLD_SIZE 399

// Initialize the world array pointer to NULL at every position.
void initializeWorld(map_t *world[WORLD_SIZE][WORLD_SIZE]);
// Function to calculate the Manhattan distance of the current map from the starting map (COORDINATES: (199, 199)).
int calculateDistance(int i, int j);
// Function to print the user accepted commands to navigate the world.
void printCommands();
// Function to print the coordinates of the current map within the world array.
void printCoordinates(int i, int j);
/* Function to handle the user's input and handle the corresponding functionality.
    * n - Display the map immediately North of the current map.
    * e - Display the map immediately East of the current map.
    * s - Display the map immediately South of the current map.
    * w - Display the map immediately West of the current map.
    * f - Teleport to the specified coordinates of the map in the world array.
    * h - Display the accepted user commands again.
    * q - Quit the game.
 */
void moveToMap(char userInput, map_t *world[WORLD_SIZE][WORLD_SIZE], int i, int j);

#endif