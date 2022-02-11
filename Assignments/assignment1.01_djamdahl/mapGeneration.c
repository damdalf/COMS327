//
// Created by Devin Amdahl on 2/1/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

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

// CONSTANTS
#define WIDTH 80
#define HEIGHT 21
#define BORDER '%'
#define PATH '#'
#define TREE '^'
#define CLEARING '.'
#define GRASS ':'
#define ROCK '@'
#define FLOWER '*'

// Function stub for printColor().
void printColor(char ch);
// Function stub for generateSeed().
int generateSeed();
// Function stub for printMap()..
void printMap(char map[HEIGHT][WIDTH]);
// Function stub for initializeMap().
void initializeMap(char map[HEIGHT][WIDTH]);
// Function stub for generateRegions().
void generateRegions(char map[HEIGHT][WIDTH]);
// Function stub for placeRegionsRight().
void placeRegionsRight(char map[HEIGHT][WIDTH], char ch, int x, int y);
// Function stub for placeRegionsLeft().
void placeRegionsLeft(char map[HEIGHT][WIDTH], char ch, int x, int y);
// Function stub for placeExits().
void placeExits(char map[HEIGHT][WIDTH]);
// Function stub for manuallyPlaceExits().
void manuallyPlaceExits(char map[HEIGHT][WIDTH]);
// Function stub for buildPaths().
void buildPaths(char map[HEIGHT][WIDTH]);
// Function stub for placePokeMart().
void placePokeMart(char map[HEIGHT][WIDTH]);
// Function stub for placePokeCenter().
void placePokeCenter(char map[HEIGHT][WIDTH]);
// Function stub for addRandom().
void addRandom(char map[HEIGHT][WIDTH]);
// Function stub for seededGeneration().
void seededGeneration(char map[HEIGHT][WIDTH]);
// Function stub for randomGeneration().
void randomGeneration(char map[HEIGHT][WIDTH]);
// Function stub for manualGeneration().
void manualGeneration(char map[HEIGHT][WIDTH]); //TODO

// The following variables store the coordinates of map's exits.
int northExit[2];
int eastExit[2];
int southExit[2];
int westExit[2];

// The following variables store the 'source' coordinates of the tall grass regions.
int tallGrassOne[2];
int tallGrassTwo[2];

// The following variables store the 'source' coordinates of the clearing regions.
int forestOne[2];
int forestTwo[2];

// The following variables store the coordinates for the PokeMart and PokeCenter.
int pokeMartX[4];
int pokeMartY[4];
int pokeCenterX[4];
int pokeCenterY[4];

// This 2D array is how the map will actually be stored and represented in the terminal.
char mapArray[HEIGHT][WIDTH];

int main()
{
    int input;
    printf("CHOOSE YOUR GENERATION TYPE (Enter 1 for RANDOM, 2 for SEED-BASED, 3 for MANUAL): ");
    scanf("%d", &input);
    fflush(stdin);

    if (input == 1 || input == 3)
    {
        srand(time(NULL));
        rand();
    }
    else seededGeneration(mapArray);

    randomGeneration(mapArray);
    randomGeneration(mapArray);
    randomGeneration(mapArray);
    randomGeneration(mapArray);
    randomGeneration(mapArray);

    return 0;
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

// Function to print the contents of the map.
void printMap(char map[HEIGHT][WIDTH])
{
    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printColor(map[i][j]);
            printf(RESET);
        }

        printf("\n");
    }

    printf("\n");
}

// Function to initialize the map with rock borders and filled with clearings.
void initializeMap(char map[HEIGHT][WIDTH])
{
    int i, j;

    // Create left border.
    for (i = 0; i < HEIGHT; i++)
    {
        map[i][0] = BORDER;
    }

    // Create right border.
    for (i = 0; i < HEIGHT; i++)
    {
        map[i][WIDTH - 1] = BORDER;
    }

    // Create bottom border.
    for (j = 0; j < WIDTH; j++)
    {
        map[HEIGHT - 1][j] = BORDER;
    }

    // Create top border.
    for (j = 0; j < WIDTH; j++)
    {
        map[0][j] = BORDER;
    }

    for (i = 1; i < HEIGHT - 1; i++)
    {
        for (j = 1; j < WIDTH - 1; j++)
        {
            map[i][j] = CLEARING;
        }
    }
}

// Function to generate the tall grass and tree regions.
void generateRegions(char map[HEIGHT][WIDTH])
{
    int i, j, quadrant, Q1, Q2, Q3, Q4, G1Q, G2Q, F1Q, F2Q;
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
            tallGrassOne[0] = (rand() % 10) + 1;
            tallGrassOne[1] = (rand() % 39) + 1;
            break;
        case 1:
            Q2 = 1;
            G1Q = 2;
            tallGrassOne[0] = (rand() % 10) + 1;
            tallGrassOne[1] = (rand() % 39) + 40;
            break;
        case 2:
            Q3 = 1;
            G1Q = 3;
            tallGrassOne[0] = (rand() % 10) + 10;
            tallGrassOne[1] = (rand() % 39) + 1;
            break;
        case 3:
            Q4 = 1;
            G1Q = 4;
            tallGrassOne[0] = (rand() % 10) + 10;
            tallGrassOne[1] = (rand() % 39) + 40;
            break;
    }

    // TALL GRASS TWO
    switch (G1Q)
    {
        case 4:
            Q1 = 1;
            G2Q = 1;
            tallGrassTwo[0] = (rand() % 10) + 1;
            tallGrassTwo[1] = (rand() % 39) + 1;
            break;
        case 3:
            Q2 = 1;
            G2Q = 2;
            tallGrassTwo[0] = (rand() % 10) + 1;
            tallGrassTwo[1] = (rand() % 39) + 40;
            break;
        case 2:
            Q3 = 1;
            G2Q = 3;
            tallGrassTwo[0] = (rand() % 10) + 10;
            tallGrassOne[1] = (rand() % 39) + 1;
            break;
        case 1:
            Q4 = 1;
            G2Q = 4;
            tallGrassTwo[0] = (rand() % 10) + 10;
            tallGrassTwo[1] = (rand() % 39) + 40;
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
                forestOne[0] = (rand() % 10) + 1;
                forestOne[1] = (rand() % 39) + 1;
                break;
            }
        case 1:
            if (Q2 == 0)
            {
                Q2 = 1;
                F1Q = 2;
                forestOne[0] = (rand() % 10) + 1;
                forestOne[1] = (rand() % 39) + 40;
                break;
            }
        case 2:
            if (Q3 == 0)
            {
                Q3 = 1;
                F1Q = 3;
                forestOne[0] = (rand() % 10) + 10;
                forestOne[1] = (rand() % 39) + 1;
                break;
            }
        case 3:
            if (Q4 == 0)
            {
                Q4 = 1;
                F1Q = 4;
                forestOne[0] = (rand() % 10) + 10;
                forestOne[1] = (rand() % 39) + 40;
                break;
            }
    }

    // FOREST TWO
    switch (F1Q)
    {
        case 4:
            Q1 = 1;
            F2Q = 1;
            forestTwo[0] = (rand() % 10) + 1;
            forestTwo[1] = (rand() % 39) + 1;
            break;
        case 3:
            Q2 = 1;
            F2Q = 2;
            forestTwo[0] = (rand() % 10) + 1;
            forestTwo[1] = (rand() % 39) + 40;
            break;
        case 2:
            Q3 = 1;
            F2Q = 3;
            forestTwo[0] = (rand() % 10) + 10;
            forestTwo[1] = (rand() % 39) + 1;
            break;
        case 1:
            Q4 = 1;
            F2Q = 4;
            forestTwo[0] = (rand() % 10) + 10;
            forestTwo[1] = (rand() % 39) + 40;
            break;
    }

    int width, height;
    height = rand() % 4;

    for (i = 1; i < 7 + height; i++)
    {
        width = (rand() % 30) + 10;
        for (j = 1; j < width + 1; j++) // TALL GRASS ONE
        {
            if (G1Q == 1) placeRegionsRight(map, GRASS, tallGrassOne[0] + i, tallGrassOne[1] + (j * 2));
            if (G1Q == 2) placeRegionsLeft(map, GRASS, tallGrassOne[0] + i, tallGrassOne[1] - (j * 2));
            if (G1Q == 3) placeRegionsRight(map, GRASS, tallGrassOne[0] - i, tallGrassOne[1] + (j * 2));
            if (G1Q == 4) placeRegionsLeft(map, GRASS, tallGrassOne[0] - i, tallGrassOne[1] - (j * 2));
        }

        width = (rand() % 30) + 10;
        for (j = 0; j < width; j++) // TALL GRASS TWO
        {
            if (G2Q == 1) placeRegionsRight(map, GRASS, tallGrassTwo[0] + i, tallGrassTwo[1] + (j * 2));
            if (G2Q == 2) placeRegionsLeft(map, GRASS, tallGrassTwo[0] + i, tallGrassTwo[1] - (j * 2));
            if (G2Q == 3) placeRegionsRight(map, GRASS, tallGrassTwo[0] - i, tallGrassTwo[1] + (j * 2));
            if (G2Q == 4) placeRegionsLeft(map, GRASS, tallGrassTwo[0] - i, tallGrassTwo[1] - (j * 2));
        }

        width = (rand() % 10) + 10;
        for (j = 0; j < width; j++) // FOREST TWO
        {
            if (F2Q == 1) placeRegionsRight(map, TREE, forestTwo[0] + i, forestTwo[1] + (j * 2));
            if (F2Q == 2) placeRegionsLeft(map, TREE, forestTwo[0] + i, forestTwo[1] - (j * 2));
            if (F2Q == 3) placeRegionsRight(map, TREE, forestTwo[0] - i, forestTwo[1] + (j * 2));
            if (F2Q == 4) placeRegionsLeft(map, TREE, forestTwo[0] - i, forestTwo[1] - (j * 2));
        }

        width = (rand() % 10) + 10;
        for (j = 0; j < width; j++) // FOREST ONE
        {
            if (F1Q == 1) placeRegionsRight(map, TREE, forestOne[0] + i, forestOne[1] + (j * 2));
            if (F1Q == 2) placeRegionsLeft(map, TREE, forestOne[0] + i, forestOne[1] - (j * 2));
            if (F1Q == 3) placeRegionsRight(map, TREE, forestOne[0] - i, forestOne[1] + (j * 2));
            if (F1Q == 4) placeRegionsLeft(map, TREE, forestOne[0] - i, forestOne[1] - (j * 2));
        }
    }
}

// Function to place the regions to the right on the map.
void placeRegionsRight(char map[HEIGHT][WIDTH], char ch, int x, int y)
{
    if (x > 0 && x + 1 > 0 && x < 20 && x + 1 < 20 && y > 0 && y + 1 > 0 && y < 78 && y + 1 < 78)
    {
        map[x][y] = ch;
        map[x + 1][y] = ch;
        map[x][y + 1] = ch;
        map[x + 1][y + 1] = ch;
    }
}

// Function to place the regions to the left on the map.
void placeRegionsLeft(char map[HEIGHT][WIDTH], char ch, int x, int y)
{
    if (x > 0 && x - 1 > 0 && x < 20 && x - 1 < 20 && y > 0 && y - 1 > 0 && y < 78 && y - 1 < 78)
    {
        map[x][y] = ch;
        map[x - 1][y] = ch;
        map[x][y - 1] = ch;
        map[x - 1][y - 1] = ch;
    }
}

// Function to randomly generate and place the exits for the map.
void placeExits(char map[HEIGHT][WIDTH])
{
    northExit[0] = 0;
    northExit[1] = ((rand() % 61) + 10);
    southExit[0] = 20;
    southExit[1] = ((rand() % 61) + 10);

    eastExit[1] = 79;
    eastExit[0] = ((rand() % 16) + 3);
    westExit[1] = 0;
    westExit[0] = ((rand() % 16) + 3);

    map[northExit[0]][northExit[1]] = PATH;
    map[southExit[0]][southExit[1]] = PATH;
    map[eastExit[0]][eastExit[1]] = PATH;
    map[westExit[0]][westExit[1]] = PATH;
}

// Function stub for manuallyPlaceExits().
void manuallyPlaceExits(char map[HEIGHT][WIDTH]) // TODO
{

}

// Function to generate the N-S and E-W paths.
void buildPaths(char map[HEIGHT][WIDTH])
{
    int i, differenceNS, differenceEW, x, y;

    // BUILD PATH FROM N-S
    x = northExit[0];
    y = northExit[1];
    if (northExit[1] > southExit[1])
    {
        differenceNS = northExit[1] - southExit[1]; // MUST MOVE LEFT
        for (i = 0; i < 10; i++) // MOVE DOWN HALF OF THE DISTANCE
        {
            x++;
            map[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT LEFT BEFORE MOVING LEFT
        {
            map[x - 1][y - i] = PATH;
        }

        for(i = 0; i < differenceNS; i++) // MOVE LEFT UNTIL AT SAME Y AS SOUTH EXIT
        {
            y--;
            map[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING DOWN
        {
            map[x + 1][y + i] = PATH;
        }

        for (i = 0; i < 10; i++) // MOVE DOWN REST OF THE DISTANCE
        {
            x++;
            map[x][y] = PATH;
        }

    }
    else
    {
        differenceNS = southExit[1] - northExit[1]; // MUST MOVE RIGHT
        for (i = 0; i < 10; i++) // MOVE DOWN HALF OF THE DISTANCE
        {
            x++;
            map[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING RIGHT
        {
            map[x - 1][y + i] = PATH;
        }

        for(i = 0; i < differenceNS; i++) // MOVE RIGHT UNTIL AT SAME Y AS SOUTH EXIT
        {
            y++;
            map[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 3) + 1; i++) // FILL A BIT LEFT BEFORE MOVING DOWN
        {
            map[x + 1][y - i] = PATH;
        }

        for (i = 0; i < 10; i++) // MOVE DOWN REST OF THE DISTANCE
        {
            x++;
            map[x][y] = PATH;
        }
    }

// BUILD PATH FROM E-W
    x = eastExit[0];
    y = eastExit[1];
    if (eastExit[0] > westExit[0])
    {
        differenceEW = eastExit[0] - westExit[0]; // MUST MOVE UP
        for (i = 0; i < 39; i++) // MOVE LEFT HALF OF THE DISTANCE
        {
            y--;
            map[x][y] = PATH;
        }

        for (i = 1; i < (differenceEW / 2) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING UP
        {
            map[x - 1][y + i] = PATH;
        }

        for(i = 0; i < differenceEW; i++) // MOVE UP UNTIL AT SAME Y AS SOUTH EXIT
        {
            x--;
            map[x][y] = PATH;
        }

        for (i = 1; i < (differenceNS / 2) + 1; i++) // FILL A BIT LEFT BEFORE MOVING LEFT
        {
            map[x + 1][y - i] = PATH;
        }

        for (i = 0; i < 40; i++) // MOVE LEFT REST OF THE DISTANCE
        {
            y--;
            map[x][y] = PATH;
        }
    }
    else
    {
        differenceEW = westExit[0] - eastExit[0]; // MUST MOVE DOWN
        for (i = 0; i < 39; i++) // MOVE LEFT HALF OF THE DISTANCE
        {
            y--;
            map[x][y] = PATH;
        }

        for (i = 1; i < (differenceEW / 2) + 1; i++) // FILL A BIT RIGHT BEFORE MOVING DOWN
        {
            map[x + 1][y + i] = PATH;
        }

        for(i = 0; i < differenceEW; i++) // MOVE RIGHT UNTIL AT SAME Y AS SOUTH EXIT
        {
            x++;
            map[x][y] = PATH;
        }

        for (i = 1; i < (differenceEW / 2) + 1; i++) // FILL A BIT LEFT BEFORE MOVING LEFT
        {
            map[x - 1][y - i] = PATH;
        }

        for (i = 0; i < 40; i++) // MOVE LEFT REST OF THE DISTANCE
        {
            y--;
            map[x][y] = PATH;
        }
    }

}

// Function to place the PokeMart along the corresponding path.
void placePokeMart(char map[HEIGHT][WIDTH])
{
    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (map[i][j] == PATH)
            {
                if (map[i + 1][j] != PATH && map[i + 1][j] != GRASS && map[i + 1][j] != BORDER && map[i + 1][j] != 'M' && map[i + 1][j] != 'C' && map[i + 1][j + 1] != PATH && map[i + 1][j + 1] != GRASS && map[i + 1][j + 1] != BORDER && map[i + 1][j + 1] != 'M' && map[i + 1][j + 1] != 'C' && map[i + 2][j] != PATH && map[i + 2][j] != GRASS && map[i + 2][j] != BORDER && map[i + 2][j] != 'M' && map[i + 2][j] != 'C' && map[i + 2][j + 1] != PATH && map[i + 2][j + 1] != GRASS && map[i + 2][j + 1] != BORDER && map[i + 2][j + 1] != 'M' && map[i + 2][j + 1] != 'C')
                {
                    map[i + 1][j] = 'M';
                    map[i + 2][j] = 'M';
                    map[i + 1][j + 1] = 'M';
                    map[i + 2][j + 1] = 'M';

                    // STORE X COORDINATES FOR CHEATS
                    pokeCenterX[0] = i + 1;
                    pokeCenterX[1] = i + 2;
                    pokeCenterX[2] = i + 1;
                    pokeCenterX[3] = i + 2;
                    // STORE Y COORDINATES FOR CHEATS
                    pokeCenterY[0] = j;
                    pokeCenterY[1] = j;
                    pokeCenterY[2] = j + 1;
                    pokeCenterY[3] = j + 1;
                    return;
                }
            }
        }
    }
}

// Function to place the PokeCenter along the corresponding path.
void placePokeCenter(char map[HEIGHT][WIDTH])
{
    int i, j;

    for (i = HEIGHT - 1; i > 0; i--)
    {
        for (j = WIDTH -1; j > 0; j--)
        {
            if (map[i][j] == PATH)
            {
                if (map[i - 1][j] != PATH && map[i - 1][j] != GRASS && map[i - 1][j] != BORDER && map[i - 1][j] != 'M' && map[i - 1][j] != 'C' && map[i - 1][j - 1] != PATH && map[i - 1][j - 1] != GRASS && map[i - 1][j - 1] != BORDER && map[i - 1][j - 1] != 'M' && map[i - 1][j - 1] != 'C' && map[i - 2][j] != PATH && map[i - 2][j] != GRASS && map[i - 2][j] != BORDER && map[i - 2][j] != 'M' && map[i - 2][j] != 'C' && map[i - 2][j - 1] != PATH && map[i - 2][j - 1] != GRASS && map[i - 2][j - 1] != BORDER && map[i - 2][j - 1] != 'M' && map[i - 2][j - 1] != 'C')
                {
                    map[i - 1][j] = 'C';
                    map[i - 2][j] = 'C';
                    map[i - 1][j - 1] = 'C';
                    map[i - 2][j - 1] = 'C';

                    // STORE X COORDINATES FOR CHEATS
                    pokeCenterX[0] = i - 1;
                    pokeCenterX[1] = i - 2;
                    pokeCenterX[2] = i - 1;
                    pokeCenterX[3] = i - 2;

                    // STORE Y COORDINATES FOR CHEATS
                    pokeCenterY[0] = j;
                    pokeCenterY[1] = j;
                    pokeCenterY[2] = j - 1;
                    pokeCenterY[3] = j - 1;
                    return;
                }
            }
        }
    }
}

// Function stub for addRandom().
void addRandom(char map[HEIGHT][WIDTH])
{
    int i, j, odds;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (map[i][j] != '#' && map[i][j] != 'M' && map[i][j] != 'C' && map[i][j] != '%' )
            {
                odds = rand() % 90;

                if (odds == 1) map[i][j] = FLOWER;
                else if (odds == 2) map[i][j] = TREE;
                else if (odds == 3) map[i][j] = ROCK;
            }
        }
    }
}

// Function to randomly generate the map using a seed.
void seededGeneration(char map[HEIGHT][WIDTH])
{
    int seed;

    seed = generateSeed();
    srand(seed);
    rand();

    initializeMap(map);
    generateRegions(map);
    placeExits(map);
    buildPaths(map);
    placePokeMart(map);
    placePokeCenter(map);
    addRandom(map);
    printMap(map);
}

// Function to randomly generate the map.
void randomGeneration(char map[HEIGHT][WIDTH])
{
    initializeMap(map);
    generateRegions(map);
    placeExits(map);
    buildPaths(map);
    placePokeMart(map);
    placePokeCenter(map);
    addRandom(map);
    printMap(map);
}

// Function to manually (in terms of the coordinates of the exits) generate the map.
void manualGeneration(char map[HEIGHT][WIDTH]) //TODO
{
    initializeMap(map);
    generateRegions(map);
    manuallyPlaceExits(map); //TODO
    buildPaths(map);
    placePokeMart(map);
    placePokeCenter(map);
    addRandom(map);
    printMap(map);
}