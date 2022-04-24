//
// Created by Devin Amdahl on 2/11/22.
//

#include <stdlib.h>
#include <stdio.h>

#include "map.h"
#include "world.h"

// Initialize the world array pointer to NULL at every position.
void initializeWorld(map_t *world[WORLD_SIZE][WORLD_SIZE])
{
    int i, j;
    for (i = 0; i < 399; i++)
    {
        for (j = 0; j < 399; j++)
        {
            world[i][j] = NULL;
        }
    }
}

// Function to calculate the Manhattan distance of the current map from the starting map (COORDINATES: (199, 199)).
int calculateDistance(int i, int j)
{
    double xDist, yDist, manDist, odds;

    xDist = abs(199 - i);
    yDist = abs(199 - j);
    manDist = xDist + yDist;

    if (manDist <= 200)
    {
        odds = rand() % 2;

        if (odds == 0)
            return 1;

        else
            return 0;
    }
    else
    {
        odds = rand() % 20;

        if (odds == 0)
            return 1;

        else
            return 0;
    }
}

// Function to print the user accepted commands to navigate the world.
void printCommands()
{
    printf("LIST OF COMMANDS:\n");
    printf("n - Display the map immediately North of the current map.\n");
    printf("s - Display the map immediately South of the current map.\n");
    printf("e - Display the map immediately East of the current map.\n");
    printf("w - Display the map immediately West of the current map.\n");
    printf("f - Teleport to the specified coordinates (map) in the world array.\n");
    printf("h - Display the accepted user commands again.\n");
    printf("q - Quit the game.\n\n");
}

// Function to print the coordinates of the current map within the world array.
void printCoordinates(int i, int j)
{
    printf("COORDINATES: (%d, %d).\n\n", j, i);
}

/* Function to handle the user's input and handle the corresponding functionality.
    * n - Display the map immediately North of the current map.
    * e - Display the map immediately East of the current map.
    * s - Display the map immediately South of the current map.
    * w - Display the map immediately West of the current map.
    * f - Teleport to the specified coordinates of the map in the world array.
    * h - Display the accepted user commands again.
    * q - Quit the game.
*/
void moveToMap(char userInput, map_t *world[WORLD_SIZE][WORLD_SIZE], int i, int j)
{
    int userX = -1;
    int userY = -1;
    int healingOdds;

    while(userInput != 'q')
    {
        printf("ENTER ONE OF THE FOLLOWING: n, s, e, w, f, h, q:");
        printf("\n");
        scanf(" %c", &userInput);

        switch(userInput)
        {
            // Moving North.
            case 'n':
                // Check bounds.
                if (i - 1 < 0)
                {
                    printf("ERROR: YOU HAVE REACHED THE WORLD'S NORTH BORDER. PLEASE MOVE IN ANOTHER DIRECTION.");
                    printf("\n\n");
                }

                else if (i - 1 > 0 && world[i - 1][j] == NULL)
                {
                    i--;
                    world[i][j] = malloc(sizeof(*world[HEIGHT][WIDTH]));
                    initializeMap(world[i][j]);
                    generateRegions(world[i][j]);

                    // Match the new map's South exit with the previous map's North exit.
                    world[i][j]->southExit[1] = world[i + 1][j]->northExit[1];
                    world[i][j]->southExit[0] = 20;
                    world[i][j]->mapArray[world[i][j]->southExit[0]][world[i][j]->southExit[1]] = PATH;

                    // Check if a neighbor to the North exits.
                    if (i - 1 > 0 && world[i - 1][j] != NULL)
                    {
                        // If it does, align the new map's North exit with the neighbors South exit.
                        world[i][j]->northExit[1] = world[i - 1][j]->southExit[1];
                        world[i][j]->northExit[0] = 20;
                        world[i][j]->mapArray[world[i][j]->northExit[0]][world[i][j]->northExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's North exit.
                        generateNorthExit(world[i][j]);
                    }

                    // Check if a neighbor to the East exits.
                    if (j + 1 < WORLD_SIZE && world[i][j + 1] != NULL)
                    {
                        // If it does, align the new map's East exit with the neighbors West exit.
                        world[i][j]->eastExit[0] = world[i][j + 1]->westExit[0];
                        world[i][j]->eastExit[1] = 79;
                        world[i][j]->mapArray[world[i][j]->eastExit[0]][world[i][j]->eastExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's East exit.
                        generateEastExit(world[i][j]);
                    }

                    // Check if a neighbor to the West exits.
                    if (j - 1 > 0 && world[i][j - 1] != NULL)
                    {
                        // If it does, align the new map's West exit with the neighbors East exit.
                        world[i][j]->westExit[0] = world[i][j - 1]->eastExit[0];
                        world[i][j]->westExit[1] = 0;
                        world[i][j]->mapArray[world[i][j]->westExit[0]][world[i][j]->westExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's West exit.
                        generateWestExit(world[i][j]);
                    }

                    buildPaths(world[i][j]);
                    healingOdds = calculateDistance(i, j);

                    if (healingOdds == 1)
                    {
                        placePokeMart(world[i][j]);
                        placePokeCenter(world[i][j]);
                    }

                    addRandom(world[i][j]);

                    if (i == 0)
                    {
                        for (int l = 0; l < WIDTH; l++)
                        {
                            world[i][j]->mapArray[0][l] = BORDER;
                        }
                    }

                    printMap(world[i][j]);
                    printCoordinates(i, j);
                }
                else
                {
                    i--;
                    printMap(world[i][j]);
                    printCoordinates(i, j);
                }

                if (i == 0)
                {
                    world[i][j]->mapArray[world[i][j]->northExit[0]][world[i][j]->northExit[1]] = BORDER;
                }

                break;

                // Moving South.
            case 's':
                // Check bounds:
                if(i + 1 >= WORLD_SIZE)
                {
                    printf("ERROR: YOU HAVE REACHED THE WORLD'S SOUTH BORDER. PLEASE MOVE IN ANOTHER DIRECTION.");
                    printf("\n\n");
                }
                else if (i + 1 < WORLD_SIZE && world[i + 1][j] == NULL)
                {
                    i++;
                    world[i][j] = malloc(sizeof(*world[HEIGHT][WIDTH]));
                    initializeMap(world[i][j]);
                    generateRegions(world[i][j]);

                    // Match the new map's North exit with the previous map's South exit.
                    world[i][j]->northExit[1] = world[i - 1][j]->southExit[1];
                    world[i][j]->northExit[0] = 0;
                    world[i][j]->mapArray[world[i][j]->northExit[0]][world[i][j]->northExit[1]] = PATH;

                    // Check if a neighbor to the South exits.
                    if (i + 1 < WORLD_SIZE && world[i + 1][j] != NULL)
                    {
                        // If it does, align the new map's South exit with the neighbors North exit.
                        world[i][j]->southExit[1] = world[i + 1][j]->northExit[1];
                        world[i][j]->southExit[0] = 20;
                        world[i][j]->mapArray[world[i][j]->southExit[0]][world[i][j]->southExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's South exit.
                        generateSouthExit(world[i][j]);
                    }

                    // Check if a neighbor to the East exits.
                    if (j + 1 < WORLD_SIZE && world[i][j + 1] != NULL)
                    {
                        // If it does, align the new map's East exit with the neighbors West exit.
                        world[i][j]->eastExit[0] = world[i][j + 1]->westExit[0];
                        world[i][j]->eastExit[1] = 79;
                        world[i][j]->mapArray[world[i][j]->eastExit[0]][world[i][j]->eastExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's East exit.
                        generateEastExit(world[i][j]);
                    }

                    // Check if a neighbor to the West exits.
                    if (j - 1 > 0 && world[i][j - 1] != NULL)
                    {
                        // If it does, align the new map's West exit with the neighbors East exit.
                        world[i][j]->westExit[0] = world[i][j - 1]->eastExit[0];
                        world[i][j]->westExit[1] = 0;
                        world[i][j]->mapArray[world[i][j]->westExit[0]][world[i][j]->westExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's West exit.
                        generateWestExit(world[i][j]);
                    }

                    buildPaths(world[i][j]);
                    healingOdds = calculateDistance(i, j);

                    if (healingOdds == 1)
                    {
                        placePokeMart(world[i][j]);
                        placePokeCenter(world[i][j]);
                    }

                    addRandom(world[i][j]);

                    if (i == WORLD_SIZE - 1)
                    {
                        for (int l = 0; l < WIDTH; l++)
                        {
                            world[i][j]->mapArray[20][l] = BORDER;
                        }
                    }

                    printMap(world[i][j]);
                    printCoordinates(i, j);
                }

                else
                {
                    i++;
                    printMap(world[i][j]);
                    printf("COORDINATES: (%d, %d).\n\n", j, i);
                }

                break;

                // Moving East.
            case 'e':
                // Check bounds.
                if(j + 1 >= WORLD_SIZE)
                {
                    printf("ERROR: YOU HAVE REACHED THE WORLD'S EAST BORDER. PLEASE MOVE IN ANOTHER DIRECTION.");
                    printf("\n\n");
                }
                else if (j + 1 < WORLD_SIZE && world[i][j + 1] == NULL)
                {
                    j++;
                    world[i][j] = malloc(sizeof(*world[HEIGHT][WIDTH]));
                    initializeMap(world[i][j]);
                    generateRegions(world[i][j]);

                    // Match the new map's West exit with the previous map's East exit.
                    world[i][j]->westExit[0] = world[i][j - 1]->eastExit[0];
                    world[i][j]->westExit[1] = 0;
                    world[i][j]->mapArray[world[i][j]->westExit[0]][world[i][j]->westExit[1]] = PATH;

                    // Check if a neighbor to the South exits.
                    if (i + 1 < WORLD_SIZE && world[i + 1][j] != NULL)
                    {
                        // If it does, align the new map's South exit with the neighbors North exit.
                        world[i][j]->southExit[1] = world[i + 1][j]->northExit[1];
                        world[i][j]->southExit[0] = 20;
                        world[i][j]->mapArray[world[i][j]->southExit[0]][world[i][j]->southExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's South exit.
                        generateSouthExit(world[i][j]);
                    }

                    // Check if a neighbor to the East exits.
                    if (j + 1 < WORLD_SIZE && world[i][j + 1] != NULL)
                    {
                        // If it does, align the new map's East exit with the neighbors West exit.
                        world[i][j]->eastExit[0] = world[i][j + 1]->westExit[0];
                        world[i][j]->eastExit[1] = 79;
                        world[i][j]->mapArray[world[i][j]->eastExit[0]][world[i][j]->eastExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's East exit.
                        generateEastExit(world[i][j]);
                    }

                    // Check if a neighbor to the North exits.
                    if (i - 1 > 0 && world[i - 1][j] != NULL)
                    {
                        // If it does, align the new map's North exit with the neighbors South exit.
                        world[i][j]->northExit[1] = world[i - 1][j]->southExit[1];
                        world[i][j]->northExit[0] = 0;
                        world[i][j]->mapArray[world[i][j]->northExit[0]][world[i][j]->northExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's North exit.
                        generateNorthExit(world[i][j]);
                    }

                    buildPaths(world[i][j]);
                    healingOdds = calculateDistance(i, j);

                    if (healingOdds == 1)
                    {
                        placePokeMart(world[i][j]);
                        placePokeCenter(world[i][j]);
                    }

                    addRandom(world[i][j]);

                    if (j == WORLD_SIZE - 1)
                    {
                        for (int l = 0; l < WIDTH; l++)
                        {
                            world[i][j]->mapArray[l][79] = BORDER;
                        }
                    }

                    printMap(world[i][j]);
                    printCoordinates(i, j);
                }

                else
                {
                    j++;
                    printMap(world[i][j]);
                    printCoordinates(i, j);
                }

                if (j == WORLD_SIZE - 1)
                {
                    world[i][j]->mapArray[world[i][j]->eastExit[0]][world[i][j]->eastExit[1]] = BORDER;
                }

                break;

                // Moving West.
            case 'w':
                // Check bounds.
                if(j - 1 < 0)
                {
                    printf("ERROR: YOU HAVE REACHED THE WORLD'S WEST BORDER. PLEASE MOVE IN ANOTHER DIRECTION.");
                    printf("\n\n");
                }
                else if (j - 1 > 0 && world[i][j - 1] == NULL)
                {
                    j--;
                    world[i][j] = malloc(sizeof(*world[HEIGHT][WIDTH]));
                    initializeMap(world[i][j]);
                    generateRegions(world[i][j]);

                    // Match the new map's East exit with the previous map's West exit.
                    world[i][j]->eastExit[0] = world[i][j + 1]->westExit[0];
                    world[i][j]->eastExit[1] = 79;
                    world[i][j]->mapArray[world[i][j]->eastExit[0]][world[i][j]->eastExit[1]] = PATH;

                    // Check if a neighbor to the South exits.
                    if (i + 1 < WORLD_SIZE && world[i + 1][j] != NULL)
                    {
                        // If it does, align the new map's South exit with the neighbors North exit.
                        world[i][j]->southExit[1] = world[i + 1][j]->northExit[1];
                        world[i][j]->southExit[0] = 20;
                        world[i][j]->mapArray[world[i][j]->southExit[0]][world[i][j]->southExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's South exit.
                        generateSouthExit(world[i][j]);
                    }

                    // Check if a neighbor to the West exits.
                    if (j - 1 > 0 && world[i][j - 1] != NULL)
                    {
                        // If it does, align the new map's West exit with the neighbors East exit.
                        world[i][j]->westExit[0] = world[i][j - 1]->eastExit[0];
                        world[i][j]->westExit[1] = 0;
                        world[i][j]->mapArray[world[i][j]->westExit[0]][world[i][j]->westExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's West exit.
                        generateWestExit(world[i][j]);
                    }

                    // Check if a neighbor to the North exits.
                    if (i - 1 > 0 && world[i - 1][j] != NULL)
                    {
                        // If it does, align the new map's North exit with the neighbors South exit.
                        world[i][j]->northExit[1] = world[i - 1][j]->southExit[1];
                        world[i][j]->northExit[0] = 0;
                        world[i][j]->mapArray[world[i][j]->northExit[0]][world[i][j]->northExit[1]] = PATH;
                    }
                    else
                    {
                        // If it does not, randomly generate the new map's North exit.
                        generateNorthExit(world[i][j]);
                    }

                    buildPaths(world[i][j]);
                    healingOdds = calculateDistance(i, j);

                    if (healingOdds == 1)
                    {
                        placePokeMart(world[i][j]);
                        placePokeCenter(world[i][j]);
                    }

                    addRandom(world[i][j]);

                    if (j == 0)
                    {
                        for (int l = 0; l < WIDTH; l++)
                        {
                            world[i][j]->mapArray[l][0] = BORDER;
                        }
                    }

                    printMap(world[i][j]);
                    printCoordinates(i, j);
                }

                else
                {
                    j--;
                    printMap(world[i][j]);
                    printCoordinates(i, j);
                }

                if (j == 0)
                {
                    world[i][j]->mapArray[world[i][j]->westExit[0]][world[i][j]->westExit[1]] = BORDER;
                }

                break;

            case 'f':
                while (1)
                {
                    printf("Please enter the X coordinate of the map that you would like to travel to (MUST BE BETWEEN 0 - 398): ");
                    printf("\n");

                    scanf(" %d", &userX);

                    if (userX >= 0 && userX < WORLD_SIZE)
                    {
                        printf("Please enter the Y coordinates of the map that would like to travel to (MUST BE BETWEEN 0 - 398): ");
                        printf("\n");

                        scanf(" %d", &userY);

                        if (userY >= 0 && userY < WORLD_SIZE)
                        {
                            i = userX;
                            j = userY;

                            if (world[i][j] != NULL)
                            {
                                printMap(world[i][j]);
                            }
                            else
                            {
                                world[i][j] = malloc(sizeof(*world[199][199]));
                                initializeMap(world[i][j]);
                                generateRegions(world[i][j]);

                                // Check if a neighbor to the North exits.
                                if (i - 1 >= 0 && world[i - 1][j] != NULL)
                                {
                                    // If it does, align the new map's North exit with the neighbors South exit.
                                    world[i][j]->northExit[1] = world[i - 1][j]->southExit[1];
                                    world[i][j]->northExit[0] = 0;
                                    world[i][j]->mapArray[world[i][j]->northExit[0]][world[i][j]->northExit[1]] = PATH;
                                }
                                else
                                {
                                    // If it does not, randomly generate the new map's North exit.
                                    generateNorthExit(world[i][j]);
                                }

                                // Check if a neighbor to the East exits.
                                if (j + 1 < WORLD_SIZE && world[i][j + 1] != NULL)
                                {
                                    // If it does, align the new map's East exit with the neighbors West exit.
                                    world[i][j]->eastExit[0] = world[i][j + 1]->westExit[0];
                                    world[i][j]->eastExit[1] = 79;
                                    world[i][j]->mapArray[world[i][j]->eastExit[0]][world[i][j]->eastExit[1]] = PATH;
                                }
                                else
                                {
                                    // If it does not, randomly generate the new map's East exit.
                                    generateEastExit(world[i][j]);
                                }

                                // Check if a neighbor to the South exits.
                                if (i + 1 < WORLD_SIZE && world[i + 1][j] != NULL)
                                {
                                    // If it does, align the new map's South exit with the neighbors North exit.
                                    world[i][j]->southExit[1] = world[i + 1][j]->northExit[1];
                                    world[i][j]->southExit[0] = 20;
                                    world[i][j]->mapArray[world[i][j]->southExit[0]][world[i][j]->southExit[1]] = PATH;
                                }
                                else
                                {
                                    // If it does not, randomly generate the new map's South exit.
                                    generateSouthExit(world[i][j]);
                                }

                                // Check if a neighbor to the West exits.
                                if (j - 1 >= 0 && world[i][j - 1] != NULL)
                                {
                                    // If it does, align the new map's West exit with the neighbors East exit.
                                    world[i][j]->westExit[0] = world[i][j - 1]->eastExit[0];
                                    world[i][j]->westExit[1] = 0;
                                    world[i][j]->mapArray[world[i][j]->westExit[0]][world[i][j]->westExit[1]] = PATH;
                                }
                                else
                                {
                                    // If it does not, randomly generate the new map's West exit.
                                    generateWestExit(world[i][j]);
                                }

                                buildPaths(world[i][j]);
                                healingOdds = calculateDistance(i, j);

                                if (healingOdds == 1)
                                {
                                    placePokeMart(world[i][j]);
                                    placePokeCenter(world[i][j]);
                                }

                                addRandom(world[i][j]);

                                if (j == 0)
                                {
                                    for (int l = 0; l < WIDTH; l++)
                                    {
                                        world[i][j]->mapArray[l][0] = BORDER;
                                    }
                                }

                                if (j == WORLD_SIZE - 1)
                                {
                                    for (int l = 0; l < WIDTH; l++)
                                    {
                                        world[i][j]->mapArray[l][79] = BORDER;
                                    }
                                }

                                if (i == WORLD_SIZE - 1)
                                {
                                    for (int l = 0; l < WIDTH; l++)
                                    {
                                        world[i][j]->mapArray[20][l] = BORDER;
                                    }
                                }

                                if (i == 0)
                                {
                                    for (int l = 0; l < WIDTH; l++)
                                    {
                                        world[i][j]->mapArray[0][l] = BORDER;
                                    }
                                }
                                printMap(world[i][j]);



                            }
                            printCoordinates(i, j);

                            userX = -1;
                            userY = -1;
                            break;
                        }
                        else
                        {
                            printf("YOU HAVE ENTERED AN INVALID NUMBER FOR THE MAP'S Y COORDINATE. PLEASE TRY AGAIN.");
                            printf("\n\n");
                            continue;
                        }
                    }
                    else
                    {
                        printf("YOU HAVE ENTERED AN INVALID NUMBER FOR THE MAP'S X COORDINATE. PLEASE TRY AGAIN.");
                        printf("\n\n");
                        continue;
                    }
                }
                break;
            case 'q':
                // Traverse through the entire world array and free up any and all allocated memory.
                for (i = 0; i < 399; i++)
                {
                    for (j = 0; j < 399; j++)
                    {
                        // Check if the current position in the world array is NULL or not.
                        if (world[i][j])
                        {
                            // If it is not NULL, meaning it contains allocated memory, free it.
                            free(world[i][j]);
                            world[i][j] = NULL;
                        }
                    }
                }
                break;
            case 'h':
                printf("\n");
                printCommands();
                break;
            default:
                printf("ERROR: AN UNRECOGNIZED COMMAND WAS ENTERED. PLEASE ONLY ENTER THE SPECIFIED COMMANDS.\n\n");
                break;
        }
    }
}

