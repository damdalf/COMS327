//
// Created by Devin Amdahl on 2/11/22.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "map.h"
#include "world.h"

int main(int argc, char *argv[])
{
    // Var to store the first command line argument, to later be stored as a constant integer.
    int clArgument;
    // Variable to represent our game's world.
    map_t *world[WORLD_SIZE][WORLD_SIZE];
    // Variables to represent the coordinates of the current map.
    int i, j;
    // Variables to store the user's inputs.
    // TODO: DON'T DELETE, JUST NOT NEEDED FOR THIS ASSIGNMENT.
    //char userInput = 'g';

    // Check if an invalid number of command line arguments was passed to the function.
    if (argc > 3)
    {
        clArgument = 10;
        printf(B_RED "+----------------------------------------------------------------------------------------+\n");
        printf("| ERROR: Invalid command line arguments passed for number of Trainers. Defaulting to 10. |\n");
        printf("+----------------------------------------------------------------------------------------+\n\n");
        printf(RESET);
    }
    else
    {
        clArgument = 10;
    }

    // Loop through all command like arguments searching for the specified switch.
    for (i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--numTrainers") == 0 && i + 1 < argc) clArgument = atoi(argv[i + 1]);
    }

    // Ensure that the number of Trainers is constant throughout the program.
    const int NUM_TRAINERS = clArgument;

    // Initialize the world array pointer to NULL at every position.
    initializeWorld(world);

    // Initialize the current position to the center of the world.
    i = 199;
    j = 199;

    world[i][j] = malloc(sizeof(*world[HEIGHT][WIDTH]));
    randomGeneration(world[i][j], NUM_TRAINERS); // TODO add a while(1) that uses 'usleep(250000)' and prints NPC movements.

    // TODO: DON'T DELETE, JUST NOT NEEDED FOR THE CURRENT ASSIGNMENT.

    /*
    printf("COORDINATES: (%d, %d).\n\n", j, i);
    printCommands();
    moveToMap(userInput, world, i, j);
     */


    return 0;
}


