/*
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
#define HEIGHT 21
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
    char mapArray[21][80];

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

    // The following variables store the coordinates for the PokeMart and PokeCenter (to be used later for cheats).
    int pokeMartX[4];
    int pokeMartY[4];
    int pokeCenterX[4];
    int pokeCenterY[4];


}
        map_t;

// Function to initialize the map with rock borders and filled with clearings.
void initializeMap(char mapArray[HEIGHT][WIDTH])
{
    int i, j;

    // Create left border.
    for (i = 0; i < HEIGHT; i++)
    {
        mapArray[i][0] = BORDER;
    }
    // Create right border.
    for (i = 0; i < HEIGHT; i++)
    {
        mapArray[i][WIDTH - 1] = BORDER;
    }
    // Create bottom border.
    for (j = 0; j < WIDTH; j++)
    {
        mapArray[HEIGHT - 1][j] = BORDER;
    }
    // Create top border.
    for (j = 0; j < WIDTH; j++)
    {
        mapArray[0][j] = BORDER;
    }
    // Assign inner cells as clearings.
    for (i = 1; i < HEIGHT - 1; i++)
    {
        for (j = 1; j < WIDTH - 1; j++)
        {
            mapArray[i][j] = CLEARING;
        }
    }
}

// Function to place the regions to the right on the map.
void placeRegionsRight(char mapArray[HEIGHT][WIDTH], char ch, int x, int y)
{
    if (x > 0 && x + 1 > 0 && x < 20 && x + 1 < 20 && y > 0 && y + 1 > 0 && y < 78 && y + 1 < 78)
    {
        mapArray[x][y] = ch;
        mapArray[x + 1][y] = ch;
        mapArray[x][y + 1] = ch;
        mapArray[x + 1][y + 1] = ch;
    }
}

// Function to place the regions to the left on the map.
void placeRegionsLeft(char mapArray[HEIGHT][WIDTH], char ch, int x, int y)
{
    if (x > 0 && x - 1 > 0 && x < 20 && x - 1 < 20 && y > 0 && y - 1 > 0 && y < 78 && y - 1 < 78)
    {
        mapArray[x][y] = ch;
        mapArray[x - 1][y] = ch;
        mapArray[x][y - 1] = ch;
        mapArray[x - 1][y - 1] = ch;
    }
}

// Function to generate the tall grass and tree regions.
void generateRegions(char mapArray[HEIGHT][WIDTH], map_t *m)
{
    int i, j, quadrant, Q1, Q2, Q3, Q4, G1Q, G2Q, F1Q, F2Q, height, width;
    Q1 = 0;
    Q2 = 0;
    Q3 = 0;
    Q4 = 0;
    G1Q = 0;
    G2Q = 0;
    F1Q = 0;
    F2Q = 0;

    // THINK OF THE MAP IN FOUR QUADRANTS
    // GENERATE TWO RANDOM (X, Y) COORDINATES TO RESIDE IN THEIR OWN INDEPENDENT QUADRANTS FOR TALL GRASS
    // GENERATE TWO RANDOM (X, Y) COORDINATES TO RESIDE IN THEIR OWN INDEPENDENT QUADRANTS FOR CLEARINGS

    // TALL GRASS ONE
    quadrant = rand() % 4;
    switch (quadrant)
    {
        case 0:
            Q1 = 1;
            G1Q = 1;
            m->tallGrassOne[0] = (rand() % 10) + 1;
            m->tallGrassOne[1] = (rand() % 39) + 1;
            break;
        case 1:
            Q2 = 1;
            G1Q = 2;
            m->tallGrassOne[0] = (rand() % 10) + 1;
            m->tallGrassOne[1] = (rand() % 39) + 40;
            break;
        case 2:
            Q3 = 1;
            G1Q = 3;
            m->tallGrassOne[0] = (rand() % 10) + 10;
            m->tallGrassOne[1] = (rand() % 39) + 1;
            break;
        case 3:
            Q4 = 1;
            G1Q = 4;
            m->tallGrassOne[0] = (rand() % 10) + 10;
            m->tallGrassOne[1] = (rand() % 39) + 40;
            break;
    }

    // TALL GRASS TWO
    switch (G1Q)
    {
        case 4:
            Q1 = 1;
            G2Q = 1;
            m->tallGrassTwo[0] = (rand() % 10) + 1;
            m->tallGrassTwo[1] = (rand() % 39) + 1;
            break;
        case 3:
            Q2 = 1;
            G2Q = 2;
            m->tallGrassTwo[0] = (rand() % 10) + 1;
            m->tallGrassTwo[1] = (rand() % 39) + 40;
            break;
        case 2:
            Q3 = 1;
            G2Q = 3;
            m->tallGrassTwo[0] = (rand() % 10) + 10;
            m->tallGrassOne[1] = (rand() % 39) + 1;
            break;
        case 1:
            Q4 = 1;
            G2Q = 4;
            m->tallGrassTwo[0] = (rand() % 10) + 10;
            m->tallGrassTwo[1] = (rand() % 39) + 40;
            break;
    }

    // FOREST ONE
    quadrant = rand() % 4;
    switch (quadrant)
    {
        case 0:
            if (Q1 == 0)
            {
                Q1 = 1;
                F1Q = 1;
                m->forestOne[0] = (rand() % 10) + 1;
                m->forestOne[1] = (rand() % 39) + 1;
                break;
            }
        case 1:
            if (Q2 == 0)
            {
                Q2 = 1;
                F1Q = 2;
                m->forestOne[0] = (rand() % 10) + 1;
                m->forestOne[1] = (rand() % 39) + 40;
                break;
            }
        case 2:
            if (Q3 == 0)
            {
                Q3 = 1;
                F1Q = 3;
                m->forestOne[0] = (rand() % 10) + 10;
                m->forestOne[1] = (rand() % 39) + 1;
                break;
            }
        case 3:
            if (Q4 == 0)
            {
                Q4 = 1;
                F1Q = 4;
                m->forestOne[0] = (rand() % 10) + 10;
                m->forestOne[1] = (rand() % 39) + 40;
                break;
            }
    }

    // FOREST TWO
    switch (F1Q)
    {
        case 4:
            Q1 = 1;
            F2Q = 1;
            m->forestTwo[0] = (rand() % 10) + 1;
            m->forestTwo[1] = (rand() % 39) + 1;
            break;
        case 3:
            Q2 = 1;
            F2Q = 2;
            m->forestTwo[0] = (rand() % 10) + 1;
            m->forestTwo[1] = (rand() % 39) + 40;
            break;
        case 2:
            Q3 = 1;
            F2Q = 3;
            m->forestTwo[0] = (rand() % 10) + 10;
            m->forestTwo[1] = (rand() % 39) + 1;
            break;
        case 1:
            Q4 = 1;
            F2Q = 4;
            m->forestTwo[0] = (rand() % 10) + 10;
            m->forestTwo[1] = (rand() % 39) + 40;
            break;
    }

    height = rand() % 4;

    for (i = 1; i < 7 + height; i++)
    {
        width = (rand() % 30) + 10;
        for (j = 1; j < width + 1; j++) // TALL GRASS ONE
        {
            if (G1Q == 1) placeRegionsRight(mapArray, GRASS, m->tallGrassOne[0] + i, m->tallGrassOne[1] + (j * 2));
            if (G1Q == 2) placeRegionsLeft(mapArray, GRASS, m->tallGrassOne[0] + i, m->tallGrassOne[1] - (j * 2));
            if (G1Q == 3) placeRegionsRight(mapArray, GRASS, m->tallGrassOne[0] - i, m->tallGrassOne[1] + (j * 2));
            if (G1Q == 4) placeRegionsLeft(mapArray, GRASS, m->tallGrassOne[0] - i, m->tallGrassOne[1] - (j * 2));
        }

        width = (rand() % 30) + 10;
        for (j = 0; j < width; j++) // TALL GRASS TWO
        {
            if (G2Q == 1) placeRegionsRight(mapArray, GRASS, m->tallGrassTwo[0] + i, m->tallGrassTwo[1] + (j * 2));
            if (G2Q == 2) placeRegionsLeft(mapArray, GRASS, m->tallGrassTwo[0] + i, m->tallGrassTwo[1] - (j * 2));
            if (G2Q == 3) placeRegionsRight(mapArray, GRASS, m->tallGrassTwo[0] - i, m->tallGrassTwo[1] + (j * 2));
            if (G2Q == 4) placeRegionsLeft(mapArray, GRASS, m->tallGrassTwo[0] - i, m->tallGrassTwo[1] - (j * 2));
        }

        width = (rand() % 10) + 10;
        for (j = 0; j < width; j++) // FOREST TWO
        {
            if (F2Q == 1) placeRegionsRight(mapArray, TREE, m->forestTwo[0] + i, m->forestTwo[1] + (j * 2));
            if (F2Q == 2) placeRegionsLeft(mapArray, TREE, m->forestTwo[0] + i, m->forestTwo[1] - (j * 2));
            if (F2Q == 3) placeRegionsRight(mapArray, TREE, m->forestTwo[0] - i, m->forestTwo[1] + (j * 2));
            if (F2Q == 4) placeRegionsLeft(mapArray, TREE, m->forestTwo[0] - i, m->forestTwo[1] - (j * 2));
        }

        width = (rand() % 10) + 10;
        for (j = 0; j < width; j++) // FOREST ONE
        {
            if (F1Q == 1) placeRegionsRight(mapArray, TREE, m->forestOne[0] + i, m->forestOne[1] + (j * 2));
            if (F1Q == 2) placeRegionsLeft(mapArray, TREE, m->forestOne[0] + i, m->forestOne[1] - (j * 2));
            if (F1Q == 3) placeRegionsRight(mapArray, TREE, m->forestOne[0] - i, m->forestOne[1] + (j * 2));
            if (F1Q == 4) placeRegionsLeft(mapArray, TREE, m->forestOne[0] - i, m->forestOne[1] - (j * 2));
        }
    }
}

// Function to randomly generate and place the exits for the map.
void placeExits(char mapArray[HEIGHT][WIDTH], map_t *m)
{
    m->northExit[0] = 0;
    m->northExit[1] = ((rand() % 61) + 10);
    m->southExit[0] = 20;
    m->southExit[1] = ((rand() % 61) + 10);

    m->eastExit[1] = 79;
    m->eastExit[0] = ((rand() % 16) + 3);
    m->westExit[1] = 0;
    m->westExit[0] = ((rand() % 16) + 3);

    mapArray[m->northExit[0]][m->northExit[1]] = PATH;
    mapArray[m->southExit[0]][m->southExit[1]] = PATH;
    mapArray[m->eastExit[0]][m->eastExit[1]] = PATH;
    mapArray[m->westExit[0]][m->westExit[1]] = PATH;
}

// Function to manually place the exits based on the direction of the exit, and the passed x and y coordinates.
void manuallyPlaceExits(char mapArray[HEIGHT][WIDTH], map_t *m, char direction, int manualCoordinate)
{
    switch(direction)
    {
        case 'n':
            // Assign North exit using passed coordinates.
            m->northExit[0] = 0;
            m->northExit[1] = manualCoordinate;

            // Randomly assign South exit.
            m->southExit[0] = 20;
            m->southExit[1] = ((rand() % 61) + 10);
            // Randomly assign East exit.
            m->eastExit[1] = 79;
            m->eastExit[0] = ((rand() % 16) + 3);
            // Randomly assign West exit.
            m->westExit[1] = 0;
            m->westExit[0] = ((rand() % 16) + 3);
            break;
        case 'e':
            // Assign East exit using passed coordinates.
            m->eastExit[0] = manualCoordinate;
            m->eastExit[1] = 79;

            // Randomly assign North exit.
            m->northExit[0] = 0;
            m->northExit[1] = ((rand() % 61) + 10);
            // Randomly assign South exit.
            m->southExit[0] = 20;
            m->southExit[1] = ((rand() % 61) + 10);
            // Randomly assign West exit.
            m->westExit[1] = 0;
            m->westExit[0] = ((rand() % 16) + 3);
            break;
        case 's':
            // Assign South exit using passed coordinates.
            m->southExit[0] = 20;
            m->southExit[1] = manualCoordinate;
            // Randomly assign North exit.
            m->northExit[0] = 0;
            m->northExit[1] = ((rand() % 61) + 10);
            // Randomly assign East exit.
            m->eastExit[1] = 79;
            m->eastExit[0] = ((rand() % 16) + 3);
            // Randomly assign West exit.
            m->westExit[1] = 0;
            m->westExit[0] = ((rand() % 16) + 3);
            break;
        case 'w':
            // Assign West exit using passed coordinates.
            m->westExit[0] = manualCoordinate;
            m->westExit[1] = 0;
            // Randomly assign North exit.
            m->northExit[0] = 0;
            m->northExit[1] = ((rand() % 61) + 10);
            // Randomly assign East exit.
            m->eastExit[1] = 79;
            m->eastExit[0] = ((rand() % 16) + 3);
            // Randomly assign South exit.
            m->southExit[0] = 20;
            m->southExit[1] = ((rand() % 61) + 10);
            break;
    }

    // Assign exits with PATH char.
    mapArray[m->northExit[0]][m->northExit[1]] = PATH;
    mapArray[m->eastExit[0]][m->eastExit[1]] = PATH;
    mapArray[m->southExit[0]][m->southExit[1]] = PATH;
    mapArray[m->westExit[0]][m->westExit[1]] = PATH;
}

// Function to generate the N-S and E-W paths.
void buildPaths(char mapArray[HEIGHT][WIDTH], map_t *m)
{
    int i, differenceNS, differenceEW, x, y;

    // BUILD PATH FROM N-S
    x = m->northExit[0];
    y = m->northExit[1];
    if (m->northExit[1] > m->southExit[1])
    {
        differenceNS = m->northExit[1] - m->southExit[1]; // MUST MOVE LEFT
        for (i = 0; i < 10; i++) // MOVE DOWN HALF OF THE DISTANCE
        {
            x++;
            mapArray[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT LEFT BEFORE MOVING LEFT
        {
            mapArray[x - 1][y - i] = PATH;
        }

        for(i = 0; i < differenceNS; i++) // MOVE LEFT UNTIL AT SAME Y AS SOUTH EXIT
        {
            y--;
            mapArray[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING DOWN
        {
            mapArray[x + 1][y + i] = PATH;
        }

        for (i = 0; i < 10; i++) // MOVE DOWN REST OF THE DISTANCE
        {
            x++;
            mapArray[x][y] = PATH;
        }

    }
    else
    {
        differenceNS = m->southExit[1] - m->northExit[1]; // MUST MOVE RIGHT
        for (i = 0; i < 10; i++) // MOVE DOWN HALF OF THE DISTANCE
        {
            x++;
            mapArray[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING RIGHT
        {
            mapArray[x - 1][y + i] = PATH;
        }

        for(i = 0; i < differenceNS; i++) // MOVE RIGHT UNTIL AT SAME Y AS SOUTH EXIT
        {
            y++;
            mapArray[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT LEFT BEFORE MOVING DOWN
        {
            mapArray[x + 1][y - i] = PATH;
        }

        for (i = 0; i < 10; i++) // MOVE DOWN REST OF THE DISTANCE
        {
            x++;
            mapArray[x][y] = PATH;
        }
    }

    // BUILD PATH FROM E-W
    x = m->eastExit[0];
    y = m->eastExit[1];
    if (m->eastExit[0] > m->westExit[0])
    {
        differenceEW = m->eastExit[0] - m->westExit[0]; // MUST MOVE UP
        for (i = 0; i < 39; i++) // MOVE LEFT HALF OF THE DISTANCE
        {
            y--;
            mapArray[x][y] = PATH;
        }

        for (i = 1; i < (differenceEW / 2) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING UP
        {
            mapArray[x - 1][y + i] = PATH;
        }

        for(i = 0; i < differenceEW; i++) // MOVE UP UNTIL AT SAME Y AS SOUTH EXIT
        {
            x--;
            mapArray[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 2) + 1; i++) // FILL A BIT LEFT BEFORE MOVING LEFT
        {
            mapArray[x + 1][y - i] = PATH;
        }

        for (i = 0; i < 40; i++) // MOVE LEFT REST OF THE DISTANCE
        {
            y--;
            mapArray[x][y] = PATH;
        }
    }
    else
    {
        differenceEW = m->westExit[0] - m->eastExit[0]; // MUST MOVE DOWN
        for (i = 0; i < 39; i++) // MOVE LEFT HALF OF THE DISTANCE
        {
            y--;
            mapArray[x][y] = PATH;
        }

        for (i = 1; i < (differenceEW / 2) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING DOWN
        {
            mapArray[x + 1][y + i] = PATH;
        }

        for(i = 0; i < differenceEW; i++) // MOVE RIGHT UNTIL AT SAME Y AS SOUTH EXIT
        {
            x++;
            mapArray[x][y] = PATH;
        }

        for (i = 1; i < (differenceEW / 2) + 1; i++) // FILL A BIT LEFT BEFORE MOVING LEFT
        {
            mapArray[x - 1][y - i] = PATH;
        }

        for (i = 0; i < 40; i++) // MOVE LEFT REST OF THE DISTANCE
        {
            y--;
            mapArray[x][y] = PATH;
        }
    }
}

// Function to place the PokeMart along the corresponding path.
void placePokeMart(char mapArray[HEIGHT][WIDTH])
{
    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (mapArray[i][j] == PATH)
            {
                if (mapArray[i + 1][j] != PATH && mapArray[i + 1][j] != GRASS && mapArray[i + 1][j] != BORDER && mapArray[i + 1][j] != 'M' && mapArray[i + 1][j] != 'C' && mapArray[i + 1][j + 1] != PATH && mapArray[i + 1][j + 1] != GRASS && mapArray[i + 1][j + 1] != BORDER && mapArray[i + 1][j + 1] != 'M' && mapArray[i + 1][j + 1] != 'C' && mapArray[i + 2][j] != PATH && mapArray[i + 2][j] != GRASS && mapArray[i + 2][j] != BORDER && mapArray[i + 2][j] != 'M' && mapArray[i + 2][j] != 'C' && mapArray[i + 2][j + 1] != PATH && mapArray[i + 2][j + 1] != GRASS && mapArray[i + 2][j + 1] != BORDER && mapArray[i + 2][j + 1] != 'M' && mapArray[i + 2][j + 1] != 'C')
                {
                    mapArray[i + 1][j] = 'M';
                    mapArray[i + 2][j] = 'M';
                    mapArray[i + 1][j + 1] = 'M';
                    mapArray[i + 2][j + 1] = 'M';


                    // STORE X COORDINATES FOR CHEATS
                    m->pokeCenterX[0] = i + 1;
                    m->pokeCenterX[1] = i + 2;
                    m->pokeCenterX[2] = i + 1;
                    m->pokeCenterX[3] = i + 2;
                    // STORE Y COORDINATES FOR CHEATS
                    m->pokeCenterY[0] = j;
                    m->pokeCenterY[1] = j;
                    m->pokeCenterY[2] = j + 1;
                    m->pokeCenterY[3] = j + 1;

                    return;
                }
            }
        }
    }
}

// Function to place the PokeCenter along the corresponding path.
void placePokeCenter(char mapArray[HEIGHT][WIDTH])
{
    int i, j;

    for (i = HEIGHT - 1; i > 0; i--)
    {
        for (j = WIDTH -1; j > 0; j--)
        {
            if (mapArray[i][j] == PATH)
            {
                if (mapArray[i - 1][j] != PATH && mapArray[i - 1][j] != GRASS && mapArray[i - 1][j] != BORDER && mapArray[i - 1][j] != 'M' && mapArray[i - 1][j] != 'C' && mapArray[i - 1][j - 1] != PATH && mapArray[i - 1][j - 1] != GRASS && mapArray[i - 1][j - 1] != BORDER && mapArray[i - 1][j - 1] != 'M' && mapArray[i - 1][j - 1] != 'C' && mapArray[i - 2][j] != PATH && mapArray[i - 2][j] != GRASS && mapArray[i - 2][j] != BORDER && mapArray[i - 2][j] != 'M' && mapArray[i - 2][j] != 'C' && mapArray[i - 2][j - 1] != PATH && mapArray[i - 2][j - 1] != GRASS && mapArray[i - 2][j - 1] != BORDER && mapArray[i - 2][j - 1] != 'M' && mapArray[i - 2][j - 1] != 'C')
                {
                    mapArray[i - 1][j] = 'C';
                    mapArray[i - 2][j] = 'C';
                    mapArray[i - 1][j - 1] = 'C';
                    mapArray[i - 2][j - 1] = 'C';


                    // STORE X COORDINATES FOR CHEATS
                    m->pokeCenterX[0] = i - 1;
                    m->pokeCenterX[1] = i - 2;
                    m->pokeCenterX[2] = i - 1;
                    m->pokeCenterX[3] = i - 2;

                    // STORE Y COORDINATES FOR CHEATS
                    m->pokeCenterY[0] = j;
                    m->pokeCenterY[1] = j;
                    m->pokeCenterY[2] = j - 1;
                    m->pokeCenterY[3] = j - 1;

                    return;
                }
            }
        }
    }
}

// Function stub for addRandom().
void addRandom(char mapArray[HEIGHT][WIDTH])
{
    int i, j, odds;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (mapArray[i][j] != '#' && mapArray[i][j] != 'M' && mapArray[i][j] != 'C' && mapArray[i][j] != '%' )
            {
                odds = rand() % 90;

                if (odds == 1) mapArray[i][j] = FLOWER;
                else if (odds == 2) mapArray[i][j] = TREE;
                else if (odds == 3) mapArray[i][j] = ROCK;
            }
        }
    }
}

// Function to ask the user for a seed.
int generateSeed()
{
    int seed;
    char input = 'n';

    while(1)
    {
        printf("Please enter a seed: ");
        scanf("%d", &seed);
        fflush(stdin);

        printf("You have entered %d for you seed. Is this correct? (Enter 'y' for yes, and any other character for no): ", seed);
        scanf("%c", &input);
        fflush(stdin);
        if (toupper(input) == 'Y') break;
    }

    printf("\n");

    return seed;
}

// Function to print the map with color.
void printColor(char ch)
{
    switch(ch)
    {
        case BORDER : // MAGENTA (BOLD)
            printf(B_MAG "%c", ch);
            return;
        case CLEARING : // GREEN
            printf(GRN "%c", ch);
            return;
        case PATH : // WHITE
            printf(WHT "%c", ch);
            return;
        case GRASS : // YELLOW
            printf(YEL "%c", ch);
            return;
        case 'M' : // BLUE (BOLD)
            printf(B_BLU "%c", ch);
            return;
        case 'C' : // RED (BOLD)
            printf(B_RED "%c", ch);
            return;
        case TREE : // GREEN (BOLD)
            printf(B_GRN "%c", ch);
            return;
        case ROCK : // WHITE (BOLD)
            printf(B_WHT "%c", ch);
            break;
        case FLOWER : // CYAN (BOLD)
            printf(B_CYN "%c", ch);
            break;
        default:
            printf("%c", ch);
    }
}

// Function to print the contents of the map.
void printMap(char mapArray[HEIGHT][WIDTH])
{
    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printColor(mapArray[i][j]);
            printf(RESET);
        }

        printf("\n");
    }

    printf("\n");
}

// Function to randomly generate the map using a seed.
void seededGeneration(map_t *m)
{
    int seed;

    seed = generateSeed();
    srand(seed);
    rand();

    initializeMap(&m->mapArray);
    generateRegions(&m->mapArray, &m);
    placeExits(&m->mapArray, &m);
    buildPaths(&m->mapArray, &m);
    placePokeMart(&m->mapArray);
    placePokeCenter(&m->mapArray);
    addRandom(&m->mapArray);
    printMap(&m->mapArray);
}

// Function to randomly generate the map.
void randomGeneration(map_t *m)
{
    initializeMap(&m->mapArray);
    generateRegions(&m->mapArray, &m);
    placeExits(&m->mapArray, &m);
    buildPaths(&m->mapArray, &m);
    placePokeMart(&m->mapArray);
    placePokeCenter(&m->mapArray);
    addRandom(&m->mapArray);
    printMap(&m->mapArray);
}

// Function to manually (in terms of the coordinates of the specified exit) generate the map.
void manualGeneration(map_t *m, char direction, int manualCoordinate)
{
    initializeMap(&m->mapArray);
    generateRegions(&m->mapArray, &m);
    printMap(&m->mapArray);
    manuallyPlaceExits(&m->mapArray, &m, direction, manualCoordinate);
    buildPaths(&m->mapArray, &m);
    placePokeMart(&m->mapArray);
    placePokeCenter(&m->mapArray);
    addRandom(&m->mapArray);
    printMap(&m->mapArray);
}

int main()
{
    map_t m, k;
    printf("Map: M\n");
    randomGeneration(&m);
    printf("Map: K\n");
    randomGeneration(&k);
    //manualGeneration(&k, 'n', m.southExit[1]);

    return 0;
}

#endif
*/
