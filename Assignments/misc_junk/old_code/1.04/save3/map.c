//
// Created by Devin Amdahl on 2/11/22.
//

#include "map.h"
#include "dijkstrasAlgorithm.h"

// Function to initialize the map with rock borders and filled with clearings.
void initializeMap(map_t *m)
{
    int i, j;

    // Create left border.
    for (i = 0; i < HEIGHT; i++)
    {
        m->mapArray[i][0] = BORDER;
    }
    // Create right border.
    for (i = 0; i < HEIGHT; i++)
    {
        m->mapArray[i][WIDTH - 1] = BORDER;
    }
    // Create bottom border.
    for (j = 0; j < WIDTH; j++)
    {
        m->mapArray[HEIGHT - 1][j] = BORDER;
    }
    // Create top border.
    for (j = 0; j < WIDTH; j++)
    {
        m->mapArray[0][j] = BORDER;
    }
    // Assign inner cells as clearings.
    for (i = 1; i < HEIGHT - 1; i++)
    {
        for (j = 1; j < WIDTH - 1; j++)
        {
            m->mapArray[i][j] = CLEARING;
        }
    }
}

// Function to place the regions to the right on the map.
void placeRegionsRight(map_t *m, char ch, int x, int y)
{
    if (x > 0 && x + 1 > 0 && x < 20 && x + 1 < 20 && y > 0 && y + 1 > 0 && y < 78 && y + 1 < 78)
    {
        m->mapArray[x][y] = ch;
        m->mapArray[x + 1][y] = ch;
        m->mapArray[x][y + 1] = ch;
        m->mapArray[x + 1][y + 1] = ch;
    }
}

// Function to place the regions to the left on the map.
void placeRegionsLeft(map_t *m, char ch, int x, int y)
{
    if (x > 0 && x - 1 > 0 && x < 20 && x - 1 < 20 && y > 0 && y - 1 > 0 && y < 78 && y - 1 < 78)
    {
        m->mapArray[x][y] = ch;
        m->mapArray[x - 1][y] = ch;
        m->mapArray[x][y - 1] = ch;
        m->mapArray[x - 1][y - 1] = ch;
    }
}

// Function to generate the tall grass and tree regions.
void generateRegions(map_t *m)
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
            if (G1Q == 1) placeRegionsRight(m, GRASS, m->tallGrassOne[0] + i, m->tallGrassOne[1] + (j * 2));
            if (G1Q == 2) placeRegionsLeft(m, GRASS, m->tallGrassOne[0] + i, m->tallGrassOne[1] - (j * 2));
            if (G1Q == 3) placeRegionsRight(m, GRASS, m->tallGrassOne[0] - i, m->tallGrassOne[1] + (j * 2));
            if (G1Q == 4) placeRegionsLeft(m, GRASS, m->tallGrassOne[0] - i, m->tallGrassOne[1] - (j * 2));
        }

        width = (rand() % 30) + 10;
        for (j = 0; j < width; j++) // TALL GRASS TWO
        {
            if (G2Q == 1) placeRegionsRight(m, GRASS, m->tallGrassTwo[0] + i, m->tallGrassTwo[1] + (j * 2));
            if (G2Q == 2) placeRegionsLeft(m, GRASS, m->tallGrassTwo[0] + i, m->tallGrassTwo[1] - (j * 2));
            if (G2Q == 3) placeRegionsRight(m, GRASS, m->tallGrassTwo[0] - i, m->tallGrassTwo[1] + (j * 2));
            if (G2Q == 4) placeRegionsLeft(m, GRASS, m->tallGrassTwo[0] - i, m->tallGrassTwo[1] - (j * 2));
        }

        width = (rand() % 10) + 10;
        for (j = 0; j < width; j++) // FOREST TWO
        {
            if (F2Q == 1) placeRegionsRight(m, TREE, m->forestTwo[0] + i, m->forestTwo[1] + (j * 2));
            if (F2Q == 2) placeRegionsLeft(m, TREE, m->forestTwo[0] + i, m->forestTwo[1] - (j * 2));
            if (F2Q == 3) placeRegionsRight(m, TREE, m->forestTwo[0] - i, m->forestTwo[1] + (j * 2));
            if (F2Q == 4) placeRegionsLeft(m, TREE, m->forestTwo[0] - i, m->forestTwo[1] - (j * 2));
        }

        width = (rand() % 10) + 10;
        for (j = 0; j < width; j++) // FOREST ONE
        {
            if (F1Q == 1) placeRegionsRight(m, TREE, m->forestOne[0] + i, m->forestOne[1] + (j * 2));
            if (F1Q == 2) placeRegionsLeft(m, TREE, m->forestOne[0] + i, m->forestOne[1] - (j * 2));
            if (F1Q == 3) placeRegionsRight(m, TREE, m->forestOne[0] - i, m->forestOne[1] + (j * 2));
            if (F1Q == 4) placeRegionsLeft(m, TREE, m->forestOne[0] - i, m->forestOne[1] - (j * 2));
        }
    }
}

// Function to randomly generate and place the exits for the map.
void placeExits(map_t *m)
{
    m->northExit[0] = 0;
    m->northExit[1] = ((rand() % 61) + 10);
    m->southExit[0] = 20;
    m->southExit[1] = ((rand() % 61) + 10);

    m->eastExit[1] = 79;
    m->eastExit[0] = ((rand() % 16) + 3);
    m->westExit[1] = 0;
    m->westExit[0] = ((rand() % 16) + 3);

    m->mapArray[m->northExit[0]][m->northExit[1]] = PATH;
    m->mapArray[m->southExit[0]][m->southExit[1]] = PATH;
    m->mapArray[m->eastExit[0]][m->eastExit[1]] = PATH;
    m->mapArray[m->westExit[0]][m->westExit[1]] = PATH;
}

// Function to manually place the exits based on the direction of the exit, and the passed x and y coordinates.
void manuallyPlaceExits(map_t *m, int northY, int southY, int eastX, int westX)
{
    // Manually assign North exit coordinates.
    m->northExit[0] = 0;
    m->northExit[1] = northY;

    // Manually assign South exit coordinates.
    m->southExit[0] = 20;
    m->southExit[1] = southY;


    // Manually assign East exit coordinates.
    m->eastExit[0] = eastX;
    m->eastExit[1] = 79;

    // Manually assign West exit coordinates.
    m->westExit[0] = westX;
    m->westExit[1] = 0;

    // Assign exits with PATH char.
    m->mapArray[m->northExit[0]][m->northExit[1]] = PATH;
    m->mapArray[m->eastExit[0]][m->eastExit[1]] = PATH;
    m->mapArray[m->southExit[0]][m->southExit[1]] = PATH;
    m->mapArray[m->westExit[0]][m->westExit[1]] = PATH;
}

// Randomly generate the coordinates for the North exit.
void generateNorthExit(map_t *m)
{
    // Randomly assign North exit.
    m->northExit[0] = 0;
    m->northExit[1] = ((rand() % 61) + 10);
    m->mapArray[m->northExit[0]][m->northExit[1]] = PATH;
}

// Randomly generate the coordinates for the East exit.
void generateEastExit(map_t *m)
{
    // Randomly assign East exit.
    m->eastExit[1] = 79;
    m->eastExit[0] = ((rand() % 16) + 3);
    m->mapArray[m->eastExit[0]][m->eastExit[1]] = PATH;
}

// Randomly generate the coordinates for the South exit.
void generateSouthExit(map_t *m)
{
    // Randomly assign South exit.
    m->southExit[0] = 20;
    m->southExit[1] = ((rand() % 61) + 10);
    m->mapArray[m->southExit[0]][m->southExit[1]] = PATH;
}

// Randomly generate the coordinates for the West exit.
void generateWestExit(map_t *m)
{
    // Randomly assign West exit.
    m->westExit[1] = 0;
    m->westExit[0] = ((rand() % 16) + 3);
    m->mapArray[m->westExit[0]][m->westExit[1]] = PATH;
}

// Function to generate the N-S and E-W paths.
void buildPaths(map_t *m)
{
    m->pathCount = 0;
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
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT LEFT BEFORE MOVING LEFT
        {
            m->mapArray[x - 1][y - i] = PATH;
            m->pathCount++;
        }

        for(i = 0; i < differenceNS; i++) // MOVE LEFT UNTIL AT SAME Y AS SOUTH EXIT
        {
            y--;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING DOWN
        {
            m->mapArray[x + 1][y + i] = PATH;
            m->pathCount++;
        }

        for (i = 0; i < 10; i++) // MOVE DOWN REST OF THE DISTANCE
        {
            x++;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }

    }
    else
    {
        differenceNS = m->southExit[1] - m->northExit[1]; // MUST MOVE RIGHT
        for (i = 0; i < 10; i++) // MOVE DOWN HALF OF THE DISTANCE
        {
            x++;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING RIGHT
        {
            m->mapArray[x - 1][y + i] = PATH;
            m->pathCount++;
        }

        for(i = 0; i < differenceNS; i++) // MOVE RIGHT UNTIL AT SAME Y AS SOUTH EXIT
        {
            y++;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT LEFT BEFORE MOVING DOWN
        {
            m->mapArray[x + 1][y - i] = PATH;
            m->pathCount++;
        }

        for (i = 0; i < 10; i++) // MOVE DOWN REST OF THE DISTANCE
        {
            x++;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
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
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }

        for (i = 1; i < (differenceEW / 2) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING UP
        {
            m->mapArray[x - 1][y + i] = PATH;
            m->pathCount++;
        }

        for(i = 0; i < differenceEW; i++) // MOVE UP UNTIL AT SAME Y AS SOUTH EXIT
        {
            x--;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }

        for (i = 1; i < (differenceNS / 2) + 1; i++) // FILL A BIT LEFT BEFORE MOVING LEFT
        {
            m->mapArray[x + 1][y - i] = PATH;
            m->pathCount++;
        }

        for (i = 0; i < 40; i++) // MOVE LEFT REST OF THE DISTANCE
        {
            y--;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }
    }
    else
    {
        differenceEW = m->westExit[0] - m->eastExit[0]; // MUST MOVE DOWN
        for (i = 0; i < 39; i++) // MOVE LEFT HALF OF THE DISTANCE
        {
            y--;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }

        for (i = 1; i < (differenceEW / 2) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING DOWN
        {
            m->mapArray[x + 1][y + i] = PATH;
            m->pathCount++;
        }

        for(i = 0; i < differenceEW; i++) // MOVE RIGHT UNTIL AT SAME Y AS SOUTH EXIT
        {
            x++;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }

        for (i = 1; i < (differenceEW / 2) + 1; i++) // FILL A BIT LEFT BEFORE MOVING LEFT
        {
            m->mapArray[x - 1][y - i] = PATH;
            m->pathCount++;
        }

        for (i = 0; i < 40; i++) // MOVE LEFT REST OF THE DISTANCE
        {
            y--;
            m->mapArray[x][y] = PATH;
            m->pathCount++;
        }
    }
}

// Function to place the PokeMart along the corresponding path.
void placePokeMart(map_t *m)
{
    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (m->mapArray[i][j] == PATH)
            {
                if (m->mapArray[i + 1][j] != PATH && m->mapArray[i + 1][j] != GRASS && m->mapArray[i + 1][j] != BORDER && m->mapArray[i + 1][j] != 'M' && m->mapArray[i + 1][j] != 'C' && m->mapArray[i + 1][j + 1] != PATH && m->mapArray[i + 1][j + 1] != GRASS && m->mapArray[i + 1][j + 1] != BORDER && m->mapArray[i + 1][j + 1] != 'M' && m->mapArray[i + 1][j + 1] != 'C' && m->mapArray[i + 2][j] != PATH && m->mapArray[i + 2][j] != GRASS && m->mapArray[i + 2][j] != BORDER && m->mapArray[i + 2][j] != 'M' && m->mapArray[i + 2][j] != 'C' && m->mapArray[i + 2][j + 1] != PATH && m->mapArray[i + 2][j + 1] != GRASS && m->mapArray[i + 2][j + 1] != BORDER && m->mapArray[i + 2][j + 1] != 'M' && m->mapArray[i + 2][j + 1] != 'C')
                {
                    m->mapArray[i + 1][j] = 'M';
                    m->mapArray[i + 2][j] = 'M';
                    m->mapArray[i + 1][j + 1] = 'M';
                    m->mapArray[i + 2][j + 1] = 'M';

                    return;
                }
            }
        }
    }
}

// Function to place the PokeCenter along the corresponding path.
void placePokeCenter(map_t *m)
{
    int i, j;

    for (i = HEIGHT - 1; i > 0; i--)
    {
        for (j = WIDTH -1; j > 0; j--)
        {
            if (m->mapArray[i][j] == PATH)
            {
                if (m->mapArray[i - 1][j] != PATH && m->mapArray[i - 1][j] != GRASS && m->mapArray[i - 1][j] != BORDER && m->mapArray[i - 1][j] != 'M' && m->mapArray[i - 1][j] != 'C' && m->mapArray[i - 1][j - 1] != PATH && m->mapArray[i - 1][j - 1] != GRASS && m->mapArray[i - 1][j - 1] != BORDER && m->mapArray[i - 1][j - 1] != 'M' && m->mapArray[i - 1][j - 1] != 'C' && m->mapArray[i - 2][j] != PATH && m->mapArray[i - 2][j] != GRASS && m->mapArray[i - 2][j] != BORDER && m->mapArray[i - 2][j] != 'M' && m->mapArray[i - 2][j] != 'C' && m->mapArray[i - 2][j - 1] != PATH && m->mapArray[i - 2][j - 1] != GRASS && m->mapArray[i - 2][j - 1] != BORDER && m->mapArray[i - 2][j - 1] != 'M' && m->mapArray[i - 2][j - 1] != 'C')
                {
                    m->mapArray[i - 1][j] = 'C';
                    m->mapArray[i - 2][j] = 'C';
                    m->mapArray[i - 1][j - 1] = 'C';
                    m->mapArray[i - 2][j - 1] = 'C';

                    return;
                }
            }
        }
    }
}

// Function stub for addRandom().
void addRandom(map_t *m)
{
    int i, j, odds;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (m->mapArray[i][j] != '#' && m->mapArray[i][j] != 'M' && m->mapArray[i][j] != 'C' && m->mapArray[i][j] != '%' && m->mapArray[i][j] != '^')
            {
                odds = rand() % 90;

                if (odds == 1) m->mapArray[i][j] = FLOWER;
                else if (odds == 2) m->mapArray[i][j] = TREE;
                else if (odds == 3) m->mapArray[i][j] = ROCK;
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
            break;
        case CLEARING : // GREEN
            printf(GRN "%c", ch);
            break;
        case PATH : // WHITE
            printf(WHT "%c", ch);
            break;
        case GRASS : // YELLOW
            printf(YEL "%c", ch);
            break;
        case 'M' : // BLUE (BOLD)
            printf(B_BLU "%c", ch);
            break;
        case 'C' : // RED (BOLD)
            printf(B_RED "%c", ch);
            break;
        case TREE : // GREEN (BOLD)
            printf(B_GRN "%c", ch);
            break;
        case ROCK : // WHITE (BOLD)
            printf(B_WHT "%c", ch);
            break;
        case FLOWER : // CYAN (BOLD)
            printf(B_CYN "%c", ch);
            break;
        case HIKERS:                // RED (BOLD)
        case RIVALS:                // RED (BOLD)
        case PACERS:                // RED (BOLD)
        case WANDERERS:             // RED (BOLD)
        case STATIONARIES:          // RED (BOLD)
        case RANDOM_WALKER:         // RED (BOLD)
            printf(B_RED "%c", ch); // RED (BOLD)
            break;
        default:
            printf("%c", ch);
    }
}

// Function to randomly choose a location on a road (and not on the border) for the player character to be generated.
void generatePC(map_t *m)
{
    m->pc.symbol= PLAYER;
    int i, j;
    int l = 0;
    int xPathCoordinatesPC[m->pathCount];
    int yPathCoordinatesPC[m->pathCount];

    // Collect all coordinates of the path units from the map.

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (m->mapArray[i][j] == PATH && i != 0 && i != 20 && j != 0 && j != 79)
            {
                xPathCoordinatesPC[l] = i;
                yPathCoordinatesPC[l] = j;
                l++;
            }
        }
    }
    // Reuse 'i' to randomly choose a set of coordinates to be used as the location in which the PC is generated.
    i = rand() % m->pathCount;
    m->pc.xPos = xPathCoordinatesPC[i];
    m->pc.yPos = yPathCoordinatesPC[i];

    if (m->pc.yPos == 0)
    {
        generatePC(m);
    }

    m->pc.previousTerrain = m->mapArray[m->pc.xPos][m->pc.yPos];
    // Place the PC in the map.
    m->mapArray[m->pc.xPos][m->pc.yPos] = PLAYER;
}

/*
 * Function to randomly choose a location on a road (and not on the border) for the player character to be generated.
 * Additionally, randomly generates the trainers into the map based off of their corresponding constraints:
 *  - No NPC may spawn or move into a cell wherein the movement cost for that NPC type is infinity.
 *  - No NPC will spawn in a cell occupied by another character.
 *  - No NPC will spawn in or move to an exit or border.
 */
void generateNPC(map_t *m, int k)
{
    int i, j, odds;
    bool generated = false;

    while (!generated)
    {
        for (i = 0; i < HEIGHT; i++)
        {
            for (j = 0; j < WIDTH; j++)
            {
                // Check if the terrain cell has a movement cost of infinity (INT_MAX).
                if (m->trainers[k]->costMap[i][j].priority != INT_MAX)
                {
                    // If not, check if the terrain cell is already occupied by another character, or if the current terrain cell is a border or exit.
                    if ((m->mapArray[i][j] != PLAYER && m->mapArray[i][j] != HIKERS && m->mapArray[i][j] != RIVALS &&
                         m->mapArray[i][j] != PACERS && m->mapArray[i][j] != WANDERERS && m->mapArray[i][j] != STATIONARIES &&
                         m->mapArray[i][j] != RANDOM_WALKER && m->mapArray[i][j] != BORDER) && (i != m->northExit[0] && i != m->eastExit[0]
                         && i != m->westExit[0] && i != m->southExit[0]) && (j != m->northExit[1] && j != m->eastExit[1] && j != m->westExit[1] && j != m->southExit[1]))
                    {
                        // Now it's time to choose a random terrain cell from the available options for the current Trainer's position.
                        odds = rand() % 1000;
                        if (odds == 0)
                        {
                            m->trainers[k]->xPos = i;
                            m->trainers[k]->yPos = j;
                            m->trainers[k]->previousTerrain = m->mapArray[i][j];
                            // Place the Trainer into the map.
                            m->mapArray[m->trainers[k]->xPos][m->trainers[k]->yPos] = m->trainers[k]->symbol;
                            return;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }
}

// Function to generate each Trainer character using 'generateCharacter()' based on the NUM_TRAINERS.
void generateNPCs(map_t *m, const int NUM_TRAINERS)
{
    int k;
    for (k = 0; k < NUM_TRAINERS; k++)
    {
        generateNPC(m, k);
    }
}


// Function to print the contents of the map.
void printMap(map_t *m)
{
    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printColor(m->mapArray[i][j]);
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

    initializeMap(m);
    generateRegions(m);
    placeExits(m);
    buildPaths(m);
    placePokeMart(m);
    placePokeCenter(m);
    addRandom(m);
    printMap(m);
}

// Function to randomly generate the map.
void randomGeneration(map_t *m, const int NUM_TRAINERS)
{
    srand(time(NULL));
    rand();

    initializeMap(m);
    generateRegions(m);
    placeExits(m);
    buildPaths(m);
    placePokeMart(m);
    placePokeCenter(m);
    addRandom(m);
    generatePC(m);

    initializeTrainers(m, NUM_TRAINERS);
    initializeCostMaps(m, NUM_TRAINERS);
    initializePlayerCostMap(m);
    initializeTrainerCostMaps(m, NUM_TRAINERS);

    generateNPCs(m, NUM_TRAINERS);
    findShortestPathHikersAndRivals(m, NUM_TRAINERS);
    //dijkstraTrainer(m);
    dijkstraPC(m);

    printPlayerCostMap(m);
    printTrainerCostMaps(m, NUM_TRAINERS);
    printMap(m);
}

// Function to generate (in memory and in the map) the minimum number of trainers.
void initializeTrainers(map_t *m, const int NUM_TRAINERS)
{
    int i, odds;
    // Allocate the memory needed for 10 trainers.

    m->trainers = malloc(NUM_TRAINERS * sizeof(character_t*));
    for (i = 0; i < NUM_TRAINERS; i++)
    {
        m->trainers[i] = malloc(sizeof(character_t));
    }
    // Ensure that our array of trainers contains at LEAST one Hiker and one Rival.
    m->trainers[0]->symbol = HIKERS;
    m->trainers[1]->symbol = RIVALS;
    // Randomly fill this array with trainers of corresponding trainer types.
    for (i = 2; i < NUM_TRAINERS; i++)
    {
        odds = rand() % 6;
        switch(odds)
        {
            // Hikers.
            case 0:
                m->trainers[i]->symbol = HIKERS;
                break;
                // Rivals.
            case 1:
                m->trainers[i]->symbol = RIVALS;
                break;
                // Pacers.
            case 2:
                m->trainers[i]->symbol = PACERS;
                break;
                // Wanderers.
            case 3:
                m->trainers[i]->symbol = WANDERERS;
                break;
                // Stationaries.
            case 4:
                m->trainers[i]->symbol = STATIONARIES;
                break;
            case 5:
                m->trainers[i]->symbol = RANDOM_WALKER;
                break;
        }
    }
}

// Initialize the cost maps to INT_MAX at every position in the 2D array.
void initializeCostMaps(map_t *m, const int NUM_TRAINERS)
{
    int i, j, k;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            m->pc.costMap[i][j].priority = INT_MAX;
            m->pc.costMap[i][j].visited = false;

            for (k = 0; k < NUM_TRAINERS; k++)
            {
                m->trainers[k]->costMap[i][j].priority = INT_MAX;
                m->trainers[k]->costMap[i][j].visited = false;
            }
        }
    }
}

// Function to initialize the cost map for the PC.
void initializePlayerCostMap(map_t *m)
{
    int i, j;
    for (i = 0; i < 399; i++)
    {
        for (j = 0; j < 399; j++)
        {
            switch(m->mapArray[i][j])
            {
                case BORDER: // inaccessible terrain type for the PC
                    break;
                case TREE: // inaccessible terrain type for the PC
                    break;
                case PATH:
                    m->pc.costMap[i][j].priority = 10;
                    break;
                case MART:
                    m->pc.costMap[i][j].priority = 10;
                    break;
                case CENTER:
                    m->pc.costMap[i][j].priority = 10;
                    break;
                case GRASS:
                    m->pc.costMap[i][j].priority = 20;
                    break;
                case CLEARING:
                    m->pc.costMap[i][j].priority = 10;
                    break;
                case ROCK: // inaccessible terrain type for the PC
                    break;
                case FLOWER:
                    m->pc.costMap[i][j].priority = 10;
                    break;
                case PLAYER:
                    m->pc.costMap[i][j].priority = 0;
                    break;
            }
        }
    }
}

// Function to initialize the cost maps for the map's trainers.
void initializeTrainerCostMaps(map_t *m, const int NUM_TRAINERS)
{
    int i, j, k;

    // Iterate through the array of trainers.
    for (k = 0; k < NUM_TRAINERS; k++)
    {
        // For Hikers.
        if (m->trainers[k]->symbol == 'h')
        {
            for (i = 0; i < 399; i++)
            {
                for (j = 0; j < 399; j++)
                {
                    switch(m->mapArray[i][j])
                    {
                        case BORDER: // inaccessible terrain type for the Hiker.
                            break;
                        case TREE:
                            m->trainers[k]->costMap[i][j].priority = 15;
                            break;
                        case PATH:
                            m->trainers[k]->costMap[i][j].priority = 10;
                            break;
                        case MART: // inaccessible terrain type for the Hiker.
                            break;
                        case CENTER: // inaccessible terrain type for the Hiker.
                            break;
                        case GRASS:
                            m->trainers[k]->costMap[i][j].priority = 15;
                            break;
                        case CLEARING:
                            m->trainers[k]->costMap[i][j].priority = 10;
                            break;
                        case ROCK:
                            m->trainers[k]->costMap[i][j].priority = 15;
                            break;
                        case FLOWER:
                            m->trainers[k]->costMap[i][j].priority = 10;
                            break;
                        case PLAYER:
                            m->trainers[k]->costMap[i][j].priority = 0;
                            break;
                    }
                }
            }
        }
        // For Rivals.
        else if (m->trainers[k]->symbol == 'r')
        {
            for (i = 0; i < 399; i++)
            {
                for (j = 0; j < 399; j++)
                {
                    switch(m->mapArray[i][j])
                    {
                        case BORDER: // inaccessible terrain type for the Rival.
                            break;
                        case TREE: // inaccessible terrain type for the Rival.
                            break;
                        case PATH:
                            m->trainers[k]->costMap[i][j].priority = 10;
                            break;
                        case MART: // inaccessible terrain type for the Rival.
                            break;
                        case CENTER: // inaccessible terrain type for the Rival.
                            break;
                        case GRASS:
                            m->trainers[k]->costMap[i][j].priority = 20;
                            break;
                        case CLEARING:
                            m->trainers[k]->costMap[i][j].priority = 10;
                            break;
                        case ROCK: // inaccessible terrain type for the Rival.
                            break;
                        case FLOWER:
                            m->trainers[k]->costMap[i][j].priority = 10;
                            break;
                        case PLAYER:
                            m->trainers[k]->costMap[i][j].priority = 0;
                            break;
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < 399; i++)
            {
                for (j = 0; j < 399; j++)
                {
                    switch(m->mapArray[i][j])
                    {
                        case BORDER: // inaccessible terrain type for the Trainer.
                            break;
                        case TREE: // inaccessible terrain type for the Trainer.
                            break;
                        case PATH:
                            m->trainers[k]->costMap[i][j].priority = 10;
                            break;
                        case MART: // inaccessible terrain type for the Trainer.
                            break;
                        case CENTER: // inaccessible terrain type for the Trainer.
                            break;
                        case GRASS:
                            m->trainers[k]->costMap[i][j].priority = 20;
                            break;
                        case CLEARING:
                            m->trainers[k]->costMap[i][j].priority = 10;
                            break;
                        case ROCK: // inaccessible terrain type for the Trainer.
                            break;
                        case FLOWER:
                            m->trainers[k]->costMap[i][j].priority = 10;
                            break;
                        case PLAYER:
                            m->trainers[k]->costMap[i][j].priority = 0;
                            break;
                    }
                }
            }
        }
    }
}

// Function to print the Player's cost map.
void printPlayerCostMap(map_t *m)
{
    printf("PLAYER COST MAP:\n");

    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (m->pc.costMap[i][j].priority == 0)
            {
                printf(B_RED "%2d ", m->pc.costMap[i][j].priority);
                printf(RESET);
            }
            else if (m->pc.costMap[i][j].priority == INT_MAX)
            {
                printf("   ");
            }
            else printf("%2d ", m->pc.costMap[i][j].priority % 100);
        }

        printf("\n");
    }

    printf("\n");
}

// Function to print the Trainer's cost maps.
void printTrainerCostMaps(map_t *m, const int NUM_TRAINERS)
{
    int i, j, k;

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        switch (m->trainers[k]->symbol)
        {
            case HIKERS:
                printf("HIKER NO. %d's COST MAP:\n", k + 1);
                break;
            case RIVALS:
                printf("RIVAL NO. %d's COST MAP:\n", k + 1);
                break;
            case PACERS:
                printf("PACER NO. %d COST MAP:\n", k + 1);
                break;
            case WANDERERS:
                printf("WANDERER NO. %d's COST MAP:\n", k + 1);
                break;
            case STATIONARIES:
                printf("STATIONARY NO. %d's COST MAP:\n", k + 1);
                break;
            case RANDOM_WALKER:
                printf("RANDOM WALKER NO. %d's COST MAP:\n", k + 1);
                break;
        }

        for (i = 0; i < HEIGHT; i++)
        {
            for (j = 0; j < WIDTH; j++)
            {
                if (m->trainers[k]->costMap[i][j].priority == 0)
                {
                    printf(B_RED "%2d ", m->trainers[k]->costMap[i][j].priority);
                    printf(RESET);
                }
                else if (m->trainers[k]->costMap[i][j].priority == INT_MAX)
                {
                    printf("   ");
                }
                else printf("%2d ", m->trainers[k]->costMap[i][j].priority % 100);
            }

            printf("\n");
        }

        printf(B_BLU "------------------------------------------------------------------------------------------\n");
        printf(RESET);
        printf("\n");
    }
}