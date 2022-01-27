#include <stdio.h>
#include <stdbool.h>

#define SIZE 5
#define POSSIBLE_MOVES 8
#define PATH_LENGTH SIZE * SIZE

// Function stub for initializeChessTable().
void initializeChessTable(int chessTable[SIZE][SIZE]);

// Function stub for printChessTable().
void printChessTable(int chessTable[SIZE][SIZE]);

// Function stub for initializeVisitedTable().
void initializeVisitedTable(int visitedTable[SIZE][SIZE]);

// Function stub for printPath().
void printPath(int visitedPath[PATH_LENGTH]);

// Function stub for newPath().
void newPath(int chessTable[SIZE][SIZE], int visitedTable[SIZE][SIZE], int visitedPath[PATH_LENGTH], int moveCount);

// Function stub for solveKnightsTourRecursive().
bool solveKnightsTourRecursive(int chessTable[SIZE][SIZE], int visitedTable[SIZE][SIZE], int visitedPath[PATH_LENGTH], int moveCount, int x, int y);

// Function stub for solveKnightsTour().
void solveKnightsTour(int chessTable[SIZE][SIZE], int visitedTable[SIZE][SIZE], int visitedPath[PATH_LENGTH], int moveCount);

/*
The Knight's Tour:

  0  1  2  3  4
-----------------
| 1  2  3  4  5  | 0
| 6  7  8  9  10 | 1
| 11 12 13 14 15 | 2
| 16 17 18 19 20 | 3
| 21 22 23 24 25 | 4
------------------

- The Three Keys to a Backtracking Algorithm:
    - Choice:
    * We have to find the Knight's next possible move.
        * Well, what moves can a Knight make in chess?
        *   - A Knight can make 8 possible moves from its current position (i, j):
        *       1. (i - 2, j - 1)
        *       2. (i + 2), j -1)
        *       3. (i - 1, j - 2)
        *       4. (i - 1, j + 2)
        *       5. (i + 1, j - 2)
        *       6. (i + 1, j + 2)
        *       7. (i + 2, j - 1)
        *       8. (i + 2, j + 1)
    - Constraints:
    * Now that we know the moves that we can make, what are our constraints?
        * We must ensure that the moves are within the bounds of the Chess Table.
        *   - The next square's position (in terms of i and j) must satisfy the following:
        *       - i > 0 && j > 0
        *       - i < SIZE && j < SIZE
        * Okay, what is our decision space (available options)?
        *   - We can only move to a square if it has NOT already been visited. How will we represent a square that has already been visited?
        *       - Already visited squares can have their visited-state set to 1 in the visitedTable.
        * Cool, but where do we pull our values from?
        *   - We must pull our values from the Chess Board (pictured above).
        *
        * So, we know that our possible starting points range anywhere from (0, 0) - (4, 4), that we can
        * only make one of the eight possible moves a Knight can make, that the move must be within the
        * bounds of the chess table, and that we cannot visit a square that has already been visited.
        *
        * Once we can identify a move as a valid one, we want to RECURSE on it.
        *   - This is where we want to make our recursive call in our function.
        *
        * Example:
        *
        * if ((nextX > 0 && nextY > 0 && nextX < SIZE && nextY < SIZE) && visitedTable[nextX][nextY] == 0)
        * {
        *
        *   visitedTable[nextX][nextY] = 1;
        *   visitedPath[moveCount] = chessTable[nextX][nextY];
        *   solveKnightsTour(chessTable, visitedTable, visitedPath);
        *
        * }
    - Goal:
    * Our goal is for our moveCount to be equal to SIZE * SIZE, as that signifies that the Knight has traversed a full path (each square in the Chess Table has
    been visited once).
        * This is our base case. Additionally, we need to make sure that we backtrack if we exhausted our possible moves that we can make we must backtrack.
        *
        * Example:
        *
        * if (moveCount == (SIZE * SIZE))
        * {
        *   printPath();
        *   newPath();
        *   initializeChessTable();
        * }
        * int i;
        *
        * for (i = 0; i < POSSIBLE_MOVES; i++)
        * {
        *   nextX = x + xMoves[i];
        *   nextY = y + yMoves[i];
        *
        *   if (nextX > 0 && nextY > 0 && nextX < SIZE && nextY < SIZE && visitedTable[nextX][nextY] == 0
        *   {
        *       visitedTable[nextX][nextY] = 1;
        *       visitedPath[moveCount] = chessTable[nextX][nextY];
        *       notDeadEnd = solveKnightsTourRecursive(chessTable, visitedTable, visitedPath, moveCount + 1, nextX, nextY);
        *
        *       visitedTable[nextX][nextY] = 0;
        *   }
        * }
*/

// Stores the eight possible horizontal moves of the Knight.
int xMoves[POSSIBLE_MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
// Stores the eight possible vertical moves of the Knight.
int yMoves[POSSIBLE_MOVES] = {1, 2, 2, 1, -1, -2, -2, -1};
// Stores the amount of unique paths that are possible in a 5 x 5 chess board.
int lineCount = 0;

int main()
{

    // Array to hold the integer value of all squares that the Knight visited in the current path (in order of the Knight's visits).
    int visitedPath[PATH_LENGTH];
    // Stores the number of valid moves that the Knight has made.
    int moveCount = 1;
    // 2D array of integers to represent the chess table and store the corresponding values of the square.
    int chessTable[SIZE][SIZE];
    // 2D array to represent the states of the squares from the chess table (visited or not).
    int visitedTable[SIZE][SIZE];

    initializeChessTable(chessTable);
    printChessTable(chessTable);
    initializeVisitedTable(visitedTable);
    solveKnightsTour(chessTable, visitedTable, visitedPath, moveCount);

    printf("\nLine Count: %d", lineCount);
    return 0;
}

// Function to initialize the chess table.
void initializeChessTable(int chessTable[SIZE][SIZE])
{
    int count = 0;
    int i, j;

    // Fill in the chess table
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            count += 1;
            chessTable[i][j] = count;
        }
    }
}

// Function to print the chess table.
void printChessTable(int chessTable[SIZE][SIZE])
{
    int i, j;

    printf("CHESS TABLE:\n");
    for (j = 0; j < SIZE; j++)
    {
        for (i = 0; i < SIZE; i++)
        {
            printf("%3d ", chessTable[j][i]);
        }

        printf("\n");
    }

    printf("\n");
}

// Function to set the squares of the solution table as 'yet to be visited'.
//  * 0 = unvisited
//  * 1 = visited
void initializeVisitedTable(int visitedTable[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            visitedTable[i][j] = 0;
        }
    }
}

// Function to print the list of the Knight's moves for a valid path.
void printPath(int visitedPath[PATH_LENGTH])
{
    lineCount++;
    int i;

    for (i = 0; i < PATH_LENGTH; i++)
    {
        if (i == 24)
        {
            printf("%d", visitedPath[i]);
        }
        else
        {
            printf("%d, ", visitedPath[i]);
        }
    }

    printf("\n");
}

// Function to initialize the visited path.
//      * -1 = unvisited.
void newPath(int chessTable[SIZE][SIZE], int visitedTable[SIZE][SIZE], int visitedPath[PATH_LENGTH], int moveCount)
{
    int i;

    initializeVisitedTable(visitedTable);
    moveCount = 1;

    for (i = 0; i < PATH_LENGTH; i++)
    {
        visitedPath[i] = 0;
    }

}

// Function to handle the process of searching for and finding valid positions for the Knight to move to.
bool solveKnightsTourRecursive(int chessTable[SIZE][SIZE], int visitedTable[SIZE][SIZE], int visitedPath[PATH_LENGTH], int moveCount, int x, int y)
{
    int i;
    int nextX;
    int nextY;
    bool notDeadEnd;

    // Base case: if the Knight has traversed a valid path, print the path and return true
    if (moveCount == PATH_LENGTH)
    {
        printPath(visitedPath);
        return true;
    }
    // Iterate through all the possible moves that the Knight can make
    for (i = 0; i < POSSIBLE_MOVES; i++)
    {
        nextX = x + xMoves[i];
        nextY = y + yMoves[i];

        // Check if the next position is within bounds, and that the Knight has not already visited it
        if (nextX >= 0 && nextY >= 0 && nextX < SIZE && nextY < SIZE && visitedTable[nextX][nextY] == 0)
        {
            // Mark this square as visited in the visitedTable
            visitedTable[nextX][nextY] = 1;
            // Add this square's value to the Knight's visited path
            visitedPath[moveCount] = chessTable[nextX][nextY];
            // Continue the search
            notDeadEnd = solveKnightsTourRecursive(chessTable, visitedTable, visitedPath, moveCount + 1, nextX, nextY);

            // Backtrack
            visitedTable[nextX][nextY] = 0;

        }
    }

    return notDeadEnd;
}

void solveKnightsTour(int chessTable[SIZE][SIZE], int visitedTable[SIZE][SIZE], int visitedPath[PATH_LENGTH], int moveCount)
{
    int i, j;

    // Iterate through all the possible starting positions for the Knight
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j ++)
        {
            // Assign the first square in the Knight's path as the initial square
            visitedPath[0] = chessTable[i][j];
            // Mark this square as visited
            visitedTable[i][j] = 1;
            // Recursively search for possible paths from this starting position, and re-initialize all variables used in the process of searching if a valid path is found
            if(solveKnightsTourRecursive(chessTable, visitedTable, visitedPath, moveCount, i, j))
            {
                newPath(chessTable, visitedTable, visitedPath, moveCount);
            }
        }
    }
}
