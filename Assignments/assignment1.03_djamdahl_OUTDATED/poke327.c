//
// Created by Devin Amdahl on 2/11/22.
//

#include <stdio.h>

#include "map.h"
#include "world.h"
#include "dijkstrasAlgorithm.h"

int main(int argc, char *argv[])
{
    // Variable to represent our game's world.
    map_t *world[WORLD_SIZE][WORLD_SIZE];
    // Variable to represent the player's character.
    pc_t *p = malloc(sizeof(pc_t));
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

    initializeCostMaps(world[i][j]);
    initializePlayerCostMap(world[i][j]);
    initializeRivalCostMap(world[i][j]);
    initializeHikerCostMap(world[i][j]);

    dijkstraRival(world[i][j], p);
    dijkstraHiker(world[i][j], p);

    printPlayerCostMap(world[i][j]);
    printRivalCostMap(world[i][j]);
    printHikerCostMap(world[i][j]);

    printf("COORDINATES: (%d, %d).\n\n", j, i);
    printCommands();
    printf("COST MAPS:\n");
    moveToMap(userInput, world, i, j);

    // Ensuring that the priority queue implementation works.
    /*
    cost_node_t *pq = newNode(0, 0, 10);
    push(&pq, 1, 1, 15);
    push(&pq, 2, 2, 20);

    while(!isEmpty(&pq))
    {
        printf("%d ", pop(&pq));
    }
     */

    return 0;
}

