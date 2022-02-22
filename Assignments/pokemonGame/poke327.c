//
// Created by Devin Amdahl on 2/11/22.
//

#include <stdio.h>

#include "map.h"
#include "world.h"

int main(int argc, char *argv[])
{
    // Variable to represent our game's world.
    map_t *world[WORLD_SIZE][WORLD_SIZE];
    // Variable to represent the player's character.
    pc_t *p;
    // Variables to represent the coordinates of the current map.
    int i, j;
    // Variables to store the user's inputs.
    char userInput = 'g';

    // Initialize the world array pointer to NULL at every position.
    initializeWorld(world);

    // Initialize the current position to the center of the world.
    i = 199;
    j = 199;

    world[i][j] = malloc(sizeof(*world[HEIGHT][WIDTH]));
    randomGeneration(world[i][j], p);
    printf("COORDINATES: (%d, %d).\n\n", j, i);
    printCommands();
    moveToMap(userInput, world, i, j);

    return 0;
}

