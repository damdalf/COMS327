//
// Created by Devin Amdahl on 2/11/22.
//

#include <stdio.h>
#include <unistd.h>
#include "map.h"
#include "world.h"

int main(int argc, char *argv[])
{
    // Var to store the first command line argument, to later be stored as a constant integer.
    int clArgument;
    // Check if an invalid number of command line arguments was passed to the function.
    if (argc > 2)
    {
        clArgument = 10;
        printf(B_RED "+----------------------------------------------------------------------------------------+\n");
        printf("| ERROR: Invalid command line arguments passed for number of Trainers. Defaulting to 10. |\n");
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf(RESET);
    }
    // Check if the correct number of command line arguments was passed to the program.
    else if (argc == 2)
    {
        clArgument = atoi(argv[1]);
    }
    // Default to the minimum number of Trainers, 10.
    else
    {
        clArgument = 10;
    }

    // Ensure that the number of Trainers is constant throughout the program.
    const int NUM_TRAINERS = clArgument;

    // Variable to represent our game's world.
    map_t *world[WORLD_SIZE][WORLD_SIZE];
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
    randomGeneration(world[i][j], NUM_TRAINERS); // TODO add a while(1) that uses 'usleep(250000)' and prints NPC movements.

    printf("COORDINATES: (%d, %d).\n\n", j, i);
    printCommands();
    moveToMap(userInput, world, i, j);

    return 0;
}


