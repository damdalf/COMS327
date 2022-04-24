//
// Created by Devin Amdahl on 2/23/22.
//

#include "dijkstrasAlgorithm.h"

// Function to run Dijkstra's algorithm on the Trainer's cost maps.
void dijkstraTrainer(map_t *m, const int NUM_TRAINERS)
{
    int i, j, k;

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        int distance[HEIGHT][WIDTH], x, y, newDist;

        // Initialize all of our starting distance's to infinity.
        for (i = 0; i < HEIGHT; i++)
        {
            for (j = 0; j < WIDTH; j++)
            {
                distance[i][j] = INT_MAX;
            }
        }

        // Initialize all elements of prev array to the sentinel value of -1.
        for (i = 0; i < (HEIGHT * WIDTH); i++)
        {
            m->trainers[k]->prev[i].x = -1;
            m->trainers[k]->prev[i].y = -1;
        }

        distance[m->pc.xPos][m->pc.yPos] = 0;
        cost_node_t* pq = newNode(m->pc.xPos, m->pc.yPos, 0);
        // Used to increment through the prev array.
        i = 0;

        while(!isEmpty(&pq))
        {
            x = peek(&pq).x;
            y = peek(&pq).y;
            pop(&pq);
            m->trainers[k]->costMap[x][y].visited = true;

            // Check above neighbor.
            if ( x > 0 && m->trainers[k]->costMap[x - 1][y].priority != INT_MAX)
            {
                if (!m->trainers[k]->costMap[x - 1][y].visited)
                {
                    newDist = distance[x][y] + m->trainers[k]->costMap[x - 1][y].priority;
                    if (newDist < distance[x - 1][y])
                    {
                        m->trainers[k]->prev[i].x = (x - 1);
                        m->trainers[k]->prev[i].y = (y);
                        i++;
                        distance[x - 1][y] = newDist;
                        if (pq == NULL) pq = newNode(x - 1, y, newDist);
                        else push(&pq, x - 1, y, newDist);
                    }
                }
            }

            // Check right-upper-diagonal neighbor.
            if (x > 0 && y < 79 && m->trainers[k]->costMap[x - 1][y + 1].priority != INT_MAX)
            {
                if (!m->trainers[k]->costMap[x - 1][y + 1].visited)
                {
                    newDist = distance[x][y] + m->trainers[k]->costMap[x -1][y + 1].priority;
                    if (newDist < distance[x - 1][y + 1])
                    {
                        m->trainers[k]->prev[i].x = (x - 1);
                        m->trainers[k]->prev[i].y = (y + 1);
                        i++;
                        distance[x - 1][y + 1] = newDist;
                        if (pq == NULL) pq = newNode(x - 1, y + 1, newDist);
                        else push(&pq, x - 1, y + 1, newDist);
                    }
                }
            }

            // Check right neighbor.
            if (y < 79 && m->trainers[k]->costMap[x][y + 1].priority != INT_MAX)
            {
                if (!m->trainers[k]->costMap[x][y + 1].visited)
                {
                    newDist = distance[x][y] + m->trainers[k]->costMap[x][y + 1].priority;
                    if (newDist < distance[x][y + 1])
                    {
                        m->trainers[k]->prev[i].x = (x);
                        m->trainers[k]->prev[i].y = (y + 1);
                        i++;
                        distance[x][y + 1] = newDist;
                        if (pq == NULL) pq = newNode(x, y + 1, newDist);
                        else push(&pq, x, y + 1, newDist);
                    }
                }
            }

            // Check right-lower-diagonal.
            if (x < 20 && y < 79 && m->trainers[k]->costMap[x + 1][y + 1].priority != INT_MAX)
            {
                if (!m->trainers[k]->costMap[x + 1][y + 1].visited)
                {
                    newDist = distance[x][y] + m->trainers[k]->costMap[x + 1][y + 1].priority;
                    if (newDist < distance[x + 1][y + 1])
                    {
                        m->trainers[k]->prev[i].x = (x + 1);
                        m->trainers[k]->prev[i].y = (y + 1);
                        i++;
                        distance[x + 1][y + 1] = newDist;
                        if (pq == NULL) pq = newNode(x + 1, y + 1, newDist);
                        else push(&pq, x + 1, y + 1, newDist);
                    }
                }
            }

            // Check below neighbor.
            if (x < 20 && m->trainers[k]->costMap[x + 1][y].priority != INT_MAX)
            {
                if (!m->trainers[k]->costMap[x + 1][y].visited)
                {
                    newDist = distance[x][y] + m->trainers[k]->costMap[x + 1][y].priority;
                    if (newDist < distance[x + 1][y])
                    {
                        m->trainers[k]->prev[i].x = (x + 1);
                        m->trainers[k]->prev[i].y = (y);
                        i++;
                        distance[x + 1][y] = newDist;
                        if (pq == NULL) pq = newNode(x + 1, y, newDist);
                        else push(&pq, x + 1, y, newDist);
                    }
                }
            }

            // Check left-lower-diagonal neighbor.
            if (x < 20 && y > 0 && m->trainers[k]->costMap[x + 1][y - 1].priority != INT_MAX)
            {
                if (!m->trainers[k]->costMap[x + 1][y - 1].visited)
                {
                    newDist = distance[x][y] + m->trainers[k]->costMap[x + 1][y - 1].priority;
                    if (newDist < distance[x + 1][y - 1])
                    {
                        m->trainers[k]->prev[i].x = (x + 1);
                        m->trainers[k]->prev[i].y = (y - 1);
                        i++;
                        distance[x + 1][y - 1] = newDist;
                        if (pq == NULL) pq = newNode(x + 1, y - 1, newDist);
                        else push(&pq, x + 1, y - 1, newDist);
                    }
                }
            }

            // Check left neighbor.
            if (y > 0 && m->trainers[k]->costMap[x][y - 1].priority != INT_MAX)
            {
                if (!m->trainers[k]->costMap[x][y - 1].visited)
                {
                    newDist = distance[x][y] + m->trainers[k]->costMap[x][y - 1].priority;
                    if (newDist < distance[x][y - 1])
                    {
                        m->trainers[k]->prev[i].x = (x);
                        m->trainers[k]->prev[i].y = (y - 1);
                        i++;
                        distance[x][y - 1] = newDist;
                        if (pq == NULL) pq = newNode(x, y - 1, newDist);
                        else push(&pq, x, y - 1, newDist);
                    }
                }
            }

            // Check left-upper-diagonal neighbor.
            if (x > 0 && y > 0 && m->trainers[k]->costMap[x - 1][y - 1].priority != INT_MAX)
            {
                if (!m->trainers[k]->costMap[x - 1][y - 1].visited)
                {
                    newDist = distance[x][y] + m->trainers[k]->costMap[x - 1][y - 1].priority;
                    if (newDist < distance[x - 1][y - 1])
                    {
                        m->trainers[k]->prev[i].x = (x - 1);
                        m->trainers[k]->prev[i].y = (y - 1);
                        i++;
                        distance[x - 1][y - 1] = newDist;
                        if (pq == NULL) pq = newNode(x - 1, y - 1, newDist);
                        else push(&pq, x - 1, y - 1, newDist);
                    }
                }
            }
        }

        // Copy contents of the distance array into the Rival cost map.
        for (i = 0; i < HEIGHT; i++)
        {
            for (j = 0; j < WIDTH; j++)
            {
                m->trainers[k]->costMap[i][j].priority = distance[i][j];
            }
        }
    }
}

// Function to run Dijkstra's algorithm on a provided PC cost map.
void dijkstraPC(map_t *m)
{
    int distance[HEIGHT][WIDTH], x, y, newDist, i, j;

    // Initialize all of our starting distance's to infinity.
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            distance[i][j] = INT_MAX;
        }
    }

    distance[m->pc.xPos][m->pc.yPos] = 0;
    cost_node_t* pq = newNode(m->pc.xPos, m->pc.yPos, 0);

    while(!isEmpty(&pq))
    {
        x = peek(&pq).x;
        y = peek(&pq).y;
        pop(&pq);
        m->pc.costMap[x][y].visited = true;

        // Check above neighbor.
        if ( x > 0 && m->pc.costMap[x - 1][y].priority != INT_MAX)
        {
            if (!m->pc.costMap[x - 1][y].visited)
            {
                newDist = distance[x][y] + m->pc.costMap[x - 1][y].priority;
                if (newDist < distance[x - 1][y])
                {
                    distance[x - 1][y] = newDist;
                    if (pq == NULL) pq = newNode(x - 1, y, newDist);
                    else push(&pq, x - 1, y, newDist);
                }
            }
        }

        // Check right-upper-diagonal neighbor.
        if (x > 0 && y < 79 && m->pc.costMap[x - 1][y + 1].priority != INT_MAX)
        {
            if (!m->pc.costMap[x - 1][y + 1].visited)
            {
                newDist = distance[x][y] + m->pc.costMap[x -1][y + 1].priority;
                if (newDist < distance[x - 1][y + 1])
                {
                    distance[x - 1][y + 1] = newDist;
                    if (pq == NULL) pq = newNode(x - 1, y + 1, newDist);
                    else push(&pq, x - 1, y + 1, newDist);
                }
            }
        }

        // Check right neighbor.
        if (y < 79 && m->pc.costMap[x][y + 1].priority != INT_MAX)
        {
            if (!m->pc.costMap[x][y + 1].visited)
            {
                newDist = distance[x][y] + m->pc.costMap[x][y + 1].priority;
                if (newDist < distance[x][y + 1])
                {
                    distance[x][y + 1] = newDist;
                    if (pq == NULL) pq = newNode(x, y + 1, newDist);
                    else push(&pq, x, y + 1, newDist);
                }
            }
        }

        // Check right-lower-diagonal.
        if (x < 20 && y < 79 && m->pc.costMap[x + 1][y + 1].priority != INT_MAX)
        {
            if (!m->pc.costMap[x + 1][y + 1].visited)
            {
                newDist = distance[x][y] + m->pc.costMap[x + 1][y + 1].priority;
                if (newDist < distance[x + 1][y + 1])
                {
                    distance[x + 1][y + 1] = newDist;
                    if (pq == NULL) pq = newNode(x + 1, y + 1, newDist);
                    else push(&pq, x + 1, y + 1, newDist);
                }
            }
        }

        // Check below neighbor.
        if (x < 20 && m->pc.costMap[x + 1][y].priority != INT_MAX)
        {
            if (!m->pc.costMap[x + 1][y].visited)
            {
                newDist = distance[x][y] + m->pc.costMap[x + 1][y].priority;
                if (newDist < distance[x + 1][y])
                {
                    distance[x + 1][y] = newDist;
                    if (pq == NULL) pq = newNode(x + 1, y, newDist);
                    else push(&pq, x + 1, y, newDist);
                }
            }
        }

        // Check left-lower-diagonal neighbor.
        if (x < 20 && y > 0 && m->pc.costMap[x + 1][y - 1].priority != INT_MAX)
        {
            if (!m->pc.costMap[x + 1][y - 1].visited)
            {
                newDist = distance[x][y] + m->pc.costMap[x + 1][y - 1].priority;
                if (newDist < distance[x + 1][y - 1])
                {
                    distance[x + 1][y - 1] = newDist;
                    if (pq == NULL) pq = newNode(x + 1, y - 1, newDist);
                    else push(&pq, x + 1, y - 1, newDist);
                }
            }
        }

        // Check left neighbor.
        if (y > 0 && m->pc.costMap[x][y - 1].priority != INT_MAX)
        {
            if (!m->pc.costMap[x][y - 1].visited)
            {
                newDist = distance[x][y] + m->pc.costMap[x][y - 1].priority;
                if (newDist < distance[x][y - 1])
                {
                    distance[x][y - 1] = newDist;
                    if (pq == NULL) pq = newNode(x, y - 1, newDist);
                    else push(&pq, x, y - 1, newDist);
                }
            }
        }

        // Check left-upper-diagonal neighbor.
        if (x > 0 && y > 0 && m->pc.costMap[x - 1][y - 1].priority != INT_MAX)
        {
            if (!m->pc.costMap[x - 1][y - 1].visited)
            {
                newDist = distance[x][y] + m->pc.costMap[x - 1][y - 1].priority;
                if (newDist < distance[x - 1][y - 1])
                {
                    distance[x - 1][y - 1] = newDist;
                    if (pq == NULL) pq = newNode(x - 1, y - 1, newDist);
                    else push(&pq, x - 1, y - 1, newDist);
                }
            }
        }
    }

    // Copy contents of the distance array into the Rival cost map.
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            m->pc.costMap[i][j].priority = distance[i][j];
        }
    }
}

// Function to find the next move for each Trainer.
void findNextMoveHikersAndRivals(map_t *m, const int NUM_TRAINERS)
{
    int i, j, k, l, min, minIndex, directions[8];
    bool occupied;
    dijkstraTrainer(m, NUM_TRAINERS);

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        if (m->trainers[k]->symbol == HIKERS || m->trainers[k]->symbol == RIVALS)
        {
            i = m->trainers[k]->xPos;
            j = m->trainers[k]->yPos;
            m->trainers[k]->previousTerrain = m->mapArray[i][j];

            // Start at Trainer, choose the lowest-cost terrain cell.
            if (i - 1 > 0 && i + 1 < 79 && j - 1 > 0 && j + 1 < 20) // TODO
            {
                // N
                directions[0] = m->trainers[k]->costMap[i - 1][j].priority;
                // NE
                directions[1] = m->trainers[k]->costMap[i - 1][j + 1].priority;
                // E
                directions[2] = m->trainers[k]->costMap[i][j + 1].priority;
                // SE
                directions[3] = m->trainers[k]->costMap[i + 1][j + 1].priority;
                // S
                directions[4] = m->trainers[k]->costMap[i + 1][j].priority;
                // SW
                directions[5] = m->trainers[k]->costMap[i + 1][j - 1].priority;
                // W
                directions[6] = m->trainers[k]->costMap[i][j - 1].priority;
                // NW
                directions[7] = m->trainers[k]->costMap[i + 1][j - 1].priority;
            }

            min = directions[0];
            minIndex = 0;
            for (l = 1; l < 8; l++)
            {
                if (min > directions[l])
                {
                    min = directions[l];
                    minIndex = l;
                }
            }

            switch(minIndex)
            {
                case 0:
                    i -= 1;
                    break;
                case 1:
                    i -= 1;
                    j += 1;
                    break;
                case 2:
                    j += 1;
                    break;
                case 3:
                    i += 1;
                    j += 1;
                    break;
                case 4:
                    i += 1;
                    break;
                case 5:
                    i += 1;
                    j -= 1;
                    break;
                case 6:
                    j -= 1;
                    break;
                case 7:
                    i += 1;
                    j -= 1;
                    break;
            }

            // Ensure that new position is not already occupied by a Trainer.
            for (l = 0; l < NUM_TRAINERS; l++)
            {
                if (m->trainers[l]->xPos != i && m->trainers[l]->yPos != j) occupied = false;
                else occupied = true;
            }
            // Now check for the PC.
            if (i != m->pc.xPos && j != m->pc.yPos && occupied != true) occupied = false;

            if (occupied == false)
            {
                m->trainers[k]->nextMove.x = i;
                m->trainers[k]->nextMove.y = j;
            }

            //Just to test, print the coordinates of the Hiker and Rivals next move.
            if (m->trainers[k]->symbol == HIKERS)
            {
                printf("HIKER NO. %d'S PREVIOUS LOCATION: X = %d, Y = %d\n", k + 1, m->trainers[k]->yPos, m->trainers[k]->xPos);
                printf("HIKER NO. %d'S NEXT MOVE: X = %d, Y = %d\n", k + 1, j, i);
            }
            else
            {
                printf("RIVAL NO. %d'S PREVIOUS LOCATION: X = %d, Y = %d\n", k + 1, m->trainers[k]->yPos, m->trainers[k]->xPos);
                printf("RIVAL NO. %d'S NEXT MOVE: X = %d, Y = %d\n", k + 1, j, i);
            }
        }
    }
    printf("\n");
    printf(B_BLU "------------------------------------------------------------------------------------------\n");
    printf(RESET);
    printf("\n");
}

// Function to find the next move for the Pacers.
void findNextMovePacers(map_t *m, const int NUM_TRAINERS)
{
    int i, j, k;
    bool occupied, changedDirection = false;

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        if (m->trainers[k]->symbol == PACERS)
        {
            // Store Pacer's current position and previous terrain.
            i = m->trainers[k]->xPos;
            j = m->trainers[k]->yPos;
            m->trainers[k]->previousTerrain = m->mapArray[i][j];

            switch(m->trainers[k]->direction)
            {
                case 0: // N
                    if (i - 1 >= 1)
                    {
                        if (m->mapArray[i - 1][j] != BORDER && m->mapArray[i - 1][j] != TREE && m->mapArray[i - 1][j] != ROCK && m->mapArray[i - 1][j] != MART
                        && m->mapArray[i - 1][j] != CENTER && m->characterArray[i - 1][j] == 'Z')
                        {
                            i -= 1;
                        }
                        else
                        {
                            m->trainers[k]->direction = 4;
                            changedDirection = true;
                        }
                    }
                    break;
                case 1: // NE
                    if (i - 1 >= 1 && j + 1 <= 78)
                    {
                        if (m->mapArray[i - 1][j + 1] != BORDER && m->mapArray[i - 1][j + 1] != TREE && m->mapArray[i - 1][j + 1] != ROCK && m->mapArray[i - 1][j + 1] != MART
                            && m->mapArray[i - 1][j + 1] != CENTER && m->characterArray[i - 1][j + 1] == 'Z')
                        {
                            i -= 1;
                            j += 1;
                        }
                        else
                        {
                            m->trainers[k]->direction = 5;
                            changedDirection = true;
                        }
                    }
                    break;
                case 2: // E
                    if (j + 1 <= 78)
                    {
                        if (m->mapArray[i][j + 1] != BORDER && m->mapArray[i][j + 1] != TREE && m->mapArray[i][j + 1] != ROCK && m->mapArray[i][j + 1] != MART
                            && m->mapArray[i][j + 1] != CENTER && m->characterArray[i][j + 1] == 'Z')
                        {
                            j += 1;
                        }
                        else
                        {
                            m->trainers[k]->direction = 6;
                            changedDirection = true;
                        }
                    }
                    break;
                case 3: // SE
                    if (i + 1 <= 19 && j + 1 <= 78)
                    {
                        if (m->mapArray[i + 1][j + 1] != BORDER && m->mapArray[i + 1][j + 1] != TREE && m->mapArray[i + 1][j + 1] != ROCK && m->mapArray[i + 1][j + 1] != MART
                            && m->mapArray[i + 1][j + 1] != CENTER && m->characterArray[i + 1][j + 1] == 'Z')
                        {
                            i += 1;
                            j += 1;
                        }
                        else
                        {
                            m->trainers[k]->direction = 7;
                            changedDirection = true;
                        }
                    }
                    break;
                case 4: // S
                    if (i + 1 <= 19)
                    {
                        if (m->mapArray[i + 1][j] != BORDER && m->mapArray[i + 1][j] != TREE && m->mapArray[i + 1][j] != ROCK && m->mapArray[i + 1][j] != MART
                            && m->mapArray[i + 1][j] != CENTER && m->characterArray[i + 1][j] == 'Z')
                        {
                            i += 1;
                        }
                        else
                        {
                            m->trainers[k]->direction = 0;
                            changedDirection = true;
                        }
                    }
                    break;
                case 5: // SW
                    if (i + 1 <= 19 && j - 1 >= 1)
                    {
                        if (m->mapArray[i + 1][j - 1] != BORDER && m->mapArray[i + 1][j - 1] != TREE && m->mapArray[i + 1][j - 1] != ROCK && m->mapArray[i + 1][j - 1] != MART
                            && m->mapArray[i + 1][j - 1] != CENTER && m->characterArray[i + 1][j - 1] == 'Z')
                        {
                            i += 1;
                            j -= 1;
                        }
                        else
                        {
                            m->trainers[k]->direction = 1;
                            changedDirection = true;
                        }
                    }
                    break;
                case 6: // W
                    if (j - 1 >= 1)
                    {
                        if (m->mapArray[i][j - 1] != BORDER && m->mapArray[i][j - 1] != TREE && m->mapArray[i][j - 1] != ROCK && m->mapArray[i][j - 1] != MART
                            && m->mapArray[i][j - 1] != CENTER && m->characterArray[i][j - 1] == 'Z')
                        {
                            j -= 1;
                        }
                        else
                        {
                            m->trainers[k]->direction = 2;
                            changedDirection = true;
                        }
                    }
                    break;
                case 7: // NW
                    if (i - 1 >= 1 && j - 1 >= 1)
                    {
                        if (m->mapArray[i - 1][j - 1] != BORDER && m->mapArray[i - 1][j - 1] != TREE && m->mapArray[i - 1][j - 1] != ROCK && m->mapArray[i - 1][j - 1] != MART
                            && m->mapArray[i - 1][j - 1] != CENTER && m->characterArray[i - 1][j - 1] == 'Z')
                        {
                            i -= 1;
                            j -= 1;
                        }
                        else
                        {
                            m->trainers[k]->direction = 3;
                            changedDirection = true;
                        }
                    }
                    break;
            }

            // Print Pacer's current information.
            printf("PACER (TRAINER NO. %d's) CURRENT DIRECTION: %d\n", k + 1, m->trainers[k]->direction);
            printf("PACER (TRAINER NO. %d's) CURRENT LOCATION: X = %d, Y = %d\n", k + 1, m->trainers[k]->yPos, m->trainers[k]->xPos);

            // Ensure that new position is not already occupied by a Trainer or the PC, and that the Trainer has not changed direction.
            if (changedDirection != true)
            {
                if (m->mapArray[i][j] == PLAYER || m->characterArray[i][j] != 'Z') //TODO after more testing, might be able to only check via characterArray.
                {
                    occupied = true;
                }
                else
                {
                    m->trainers[k]->nextMove.x = i;
                    m->trainers[k]->nextMove.y = j;
                }

                //Just to test, print the coordinates of the Pacer's next move.
                printf("PACER (TRAINER NO. %d's) NEXT MOVE: X = %d, Y = %d\n\n", k + 1, j, i);
            }
            else
            {
                printf("PACER (TRAINER NO. %d) CHANGED DIRECTION.\n\n", k + 1);
            }
        }
    }
    printf("\n");
    printf(B_BLU "------------------------------------------------------------------------------------------\n");
    printf(RESET);
    printf("\n");
}

// Function to find the next move for the Wanderers.
void findNextMoveWanderers(map_t *m, const int NUM_TRAINERS)
{
    int i, j, k;
    bool occupied, changedDirection;

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        if (m->trainers[k]->symbol == WANDERERS)
        {
            // Store Wanderer's current position and previous terrain.
            i = m->trainers[k]->xPos;
            j = m->trainers[k]->yPos;

            switch (m->trainers[k]->direction) {
                case 0: // N
                    if (i - 1 >= 1) {
                        if (m->mapArray[i - 1][j] != m->trainers[k]->previousTerrain) {
                            generateDirections(m, k);
                            changedDirection = true;
                        } else {
                            i -= 1;
                        }
                    }
                    break;
                case 1: // NE
                    if (i - 1 >= 1 && j + 1 <= 78) {
                        if (m->mapArray[i - 1][j + 1] != m->trainers[k]->previousTerrain) {
                            generateDirections(m, k);
                            changedDirection = true;
                        } else {
                            i -= 1;
                            j += 1;
                        }
                    }
                    break;
                case 2: // E
                    if (j + 1 <= 78) {
                        if (m->mapArray[i][j + 1] != m->trainers[k]->previousTerrain) {
                            generateDirections(m, k);
                            changedDirection = true;
                        } else {
                            j += 1;
                        }
                    }
                    break;
                case 3: // SE
                    if (i + 1 <= 19 && j + 1 <= 78) {
                        if (m->mapArray[i + 1][j + 1] != m->trainers[k]->previousTerrain) {
                            generateDirections(m, k);
                            changedDirection = true;
                        } else {
                            i += 1;
                            j += 1;
                        }
                    }
                    break;
                case 4: // S
                    if (i + 1 <= 19) {
                        if (m->mapArray[i + 1][j] != m->trainers[k]->previousTerrain) {
                            generateDirections(m, k);
                            changedDirection = true;
                        } else {
                            i += 1;
                        }
                    }
                    break;
                case 5: // SW
                    if (i + 1 <= 19 && j - 1 >= 1) {

                    }
                    if (m->mapArray[i + 1][j - 1] != m->trainers[k]->previousTerrain) {
                        generateDirections(m, k);
                        changedDirection = true;
                    } else {
                        i += 1;
                        j -= 1;
                    }
                    break;
                case 6: // W
                    if (j - 1 >= 1) {
                        if (m->mapArray[i][j - 1] != m->trainers[k]->previousTerrain) {
                            generateDirections(m, k);
                            changedDirection = true;
                        } else {
                            j -= 1;
                        }
                    }
                    break;
                case 7: // NW
                    if (i - 1 >= 1 && j - 1 >= 1) {
                        if (m->mapArray[i - 1][j - 1] != m->trainers[k]->previousTerrain) {
                            generateDirections(m, k);
                            changedDirection = true;
                        } else {
                            i -= 1;
                            j -= 1;
                        }
                    }
                    break;
            }

            // Print Wanderer's current information.
            printf("WANDERER (TRAINER NO. %d's) CURRENT DIRECTION: %d\n", k + 1, m->trainers[k]->direction);
            printf("WANDERER (TRAINER NO. %d's) CURRENT LOCATION: X = %d, Y = %d\n", k + 1, m->trainers[k]->yPos, m->trainers[k]->xPos);

            // Ensure that new position is not already occupied by a Trainer or the PC, and that the Trainer has not changed direction.
            if (changedDirection != true)
            {
                if (m->mapArray[i][j] == PLAYER || m->characterArray[i][j] != 'Z') //TODO after more testing, might be able to only check via characterArray.
                {
                    occupied = true;
                }
                else
                {
                    m->trainers[k]->nextMove.x = i;
                    m->trainers[k]->nextMove.y = j;
                }

                //Just to test, print the coordinates of the Pacer's next move.
                printf("WANDERER (TRAINER NO. %d's) NEXT MOVE: X = %d, Y = %d\n\n", k + 1, j, i);
            }
            else
            {
                printf("WANDERER (TRAINER NO. %d) CHANGED DIRECTIONS.\n\n", k + 1);
            }
        }
    }
    printf("\n");
    printf(B_BLU "------------------------------------------------------------------------------------------\n");
    printf(RESET);
    printf("\n");
}

// Function to find the next move for the Random Walkers.
void findNextMoveRandomWalkers(map_t *m, const int NUM_TRAINERS)
{
    int i, j, k;
    bool occupied, changedDirection;

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        if (m->trainers[k]->symbol == RANDOM_WALKERS) {
            // Store Random Walker's current position and previous terrain.
            i = m->trainers[k]->xPos;
            j = m->trainers[k]->yPos;

            switch (m->trainers[k]->direction) {
                case 0: // N
                    if (i - 1 >= 1)
                    {
                        if (m->mapArray[i - 1][j] != BORDER && m->mapArray[i - 1][j] != TREE && m->mapArray[i - 1][j] != ROCK && m->mapArray[i - 1][j] != MART
                            && m->mapArray[i - 1][j] != CENTER && m->characterArray[i - 1][j] == 'Z')
                        {
                            i -= 1;
                        }
                        else
                        {
                            generateDirections(m, k);
                            changedDirection = true;
                        }
                    }
                    break;
                case 1: // NE
                    if (i - 1 >= 1 && j + 1 <= 78)
                    {
                        if (m->mapArray[i - 1][j + 1] != BORDER && m->mapArray[i - 1][j + 1] != TREE && m->mapArray[i - 1][j + 1] != ROCK && m->mapArray[i - 1][j + 1] != MART
                            && m->mapArray[i - 1][j + 1] != CENTER && m->characterArray[i - 1][j + 1] == 'Z')
                        {
                            i -= 1;
                            j += 1;
                        }
                        else
                        {
                            generateDirections(m, k);
                            changedDirection = true;
                        }
                    }
                    break;
                case 2: // E
                    if (j + 1 <= 78)
                    {
                        if (m->mapArray[i][j + 1] != BORDER && m->mapArray[i][j + 1] != TREE && m->mapArray[i][j + 1] != ROCK && m->mapArray[i][j + 1] != MART
                            && m->mapArray[i][j + 1] != CENTER && m->characterArray[i][j + 1] == 'Z')
                        {
                            j += 1;
                        }
                        else
                        {
                            generateDirections(m, k);
                            changedDirection = true;
                        }
                    }
                    break;
                case 3: // SE
                    if (i + 1 <= 19 && j + 1 <= 78)
                    {
                        if (m->mapArray[i + 1][j + 1] != BORDER && m->mapArray[i + 1][j + 1] != TREE && m->mapArray[i + 1][j + 1] != ROCK && m->mapArray[i + 1][j + 1] != MART
                            && m->mapArray[i + 1][j + 1] != CENTER && m->characterArray[i + 1][j + 1] == 'Z')
                        {
                            i += 1;
                            j += 1;
                        }
                        else
                        {
                            generateDirections(m, k);
                            changedDirection = true;
                        }
                    }
                    break;
                case 4: // S
                    if (i + 1 <= 19)
                    {
                        if (m->mapArray[i + 1][j] != BORDER && m->mapArray[i + 1][j] != TREE && m->mapArray[i + 1][j] != ROCK && m->mapArray[i + 1][j] != MART
                            && m->mapArray[i + 1][j] != CENTER && m->characterArray[i + 1][j] == 'Z')
                        {
                            i += 1;
                        }
                        else
                        {
                            generateDirections(m, k);
                            changedDirection = true;
                        }
                    }
                    break;
                case 5: // SW
                    if (i + 1 <= 19 && j - 1 >= 1)
                    {
                        if (m->mapArray[i + 1][j - 1] != BORDER && m->mapArray[i + 1][j - 1] != TREE && m->mapArray[i + 1][j - 1] != ROCK && m->mapArray[i + 1][j - 1] != MART
                            && m->mapArray[i + 1][j - 1] != CENTER && m->characterArray[i + 1][j - 1] == 'Z')
                        {
                            i += 1;
                            j -= 1;
                        }
                        else
                        {
                            generateDirections(m, k);
                            changedDirection = true;
                        }
                    }
                    break;
                case 6: // W
                    if (j - 1 >= 1)
                    {
                        if (m->mapArray[i][j - 1] != BORDER && m->mapArray[i][j - 1] != TREE && m->mapArray[i][j - 1] != ROCK && m->mapArray[i][j - 1] != MART
                            && m->mapArray[i][j - 1] != CENTER && m->characterArray[i][j - 1] == 'Z')
                        {
                            j -= 1;
                        }
                        else
                        {
                            generateDirections(m, k);
                            changedDirection = true;
                        }
                    }
                    break;
                case 7: // NW
                    if (i - 1 >= 1 && j - 1 >= 1)
                    {
                        if (m->mapArray[i - 1][j - 1] != BORDER && m->mapArray[i - 1][j - 1] != TREE && m->mapArray[i - 1][j - 1] != ROCK && m->mapArray[i - 1][j - 1] != MART
                            && m->mapArray[i - 1][j - 1] != CENTER && m->characterArray[i - 1][j - 1] == 'Z')
                        {
                            i -= 1;
                            j -= 1;
                        }
                        else
                        {
                            generateDirections(m, k);
                            changedDirection = true;
                        }
                    }
                    break;
            }

            // Print Walker's current information.
            printf("RANDOM WALKER (TRAINER NO. %d's) CURRENT DIRECTION: %d\n", k + 1, m->trainers[k]->direction);
            printf("RANDOM WALKER (TRAINER NO. %d's) CURRENT LOCATION: X = %d, Y = %d\n", k + 1, m->trainers[k]->yPos, m->trainers[k]->xPos);

            // Ensure that new position is not already occupied by a Trainer or the PC, and that the Trainer has not changed direction.
            if (changedDirection != true)
            {
                if (m->mapArray[i][j] == PLAYER || m->characterArray[i][j] != 'Z') //TODO after more testing, might be able to only check via characterArray.
                {
                    occupied = true;
                }
                else
                {
                    m->trainers[k]->nextMove.x = i;
                    m->trainers[k]->nextMove.y = j;
                }

                //Just to test, print the coordinates of the Pacer's next move.
                printf("RANDOM WALKER (TRAINER NO. %d's) NEXT MOVE: X = %d, Y = %d\n\n", k + 1, j, i);
            }
            else
            {
                printf("RANDOM WALKER (TRAINER NO. %d) CHANGED DIRECTIONS.\n\n", k + 1);
            }
        }
    }
    printf("\n");
    printf(B_BLU "------------------------------------------------------------------------------------------\n");
    printf(RESET);
    printf("\n");
}

// Function to call the above next move methods for each Trainer present in the game.
void findNextMoves(map_t *m, const int NUM_TRAINERS)
{
    findNextMoveHikersAndRivals(m, NUM_TRAINERS);
    findNextMovePacers(m, NUM_TRAINERS);
    findNextMoveWanderers(m, NUM_TRAINERS);
    findNextMoveRandomWalkers(m, NUM_TRAINERS);
}

// Function to update the locations of the Trainers present in the game after a call of 'findNextMoves()'.
void updateTrainerLocations(map_t*m, const int NUM_TRAINERS)
{
    int k;

    // Initialize cost maps.
    initializeCostMaps(m, NUM_TRAINERS);
    initializePlayerCostMap(m);
    initializeHikersAndRivalsCostMaps(m, NUM_TRAINERS);

    // Create cost maps for the PC and each Trainer. Then, print them to the terminal.
    dijkstraPC(m);
    dijkstraTrainer(m, NUM_TRAINERS);

    // Print cost maps.
    printPlayerCostMap(m);
    printHikersAndRivalsCostMaps(m, NUM_TRAINERS);

    // Find next moves for all Trainers.
    findNextMoves(m, NUM_TRAINERS);

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        // Update the Trainer's current position to their next move coordinates.
        m->trainers[k]->xPos = m->trainers[k]->nextMove.x;
        m->trainers[k]->yPos = m->trainers[k]->nextMove.y;
        // Update the Trainer's next move to be NULL.
        m->trainers[k]->nextMove.x = -1;
        m->trainers[k]->nextMove.y = -1;
    }
}

/*
// Function to find the shortest path between two nodes (terrain cells).
void findShortestPath(map_t *m)
{
    int i, j, k, size;
    dijkstraTrainer(m);

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        if (m->trainers[k]->symbol == HIKERS || m->trainers[k]->symbol == RIVALS)
        {
            // Find actual size of the list of nodes that were traveled.
            size = 0;
            for (i = 0; i < (HEIGHT * WIDTH); i++)
            {
                if (m->trainers[k]->prev[i].x != -1 && m->trainers[k]->prev[i].y != -1)
                {
                    size++;
                }
            }

            // Allocate memory based of what is found for the size of the path.
            m->trainers[k]->path = malloc(sizeof(coordinates_t*) * size);

            // Check to see if our end node (the PC) is reachable for the given Trainer.
            if (m->trainers[k]->costMap[m->pc.xPos][m->pc.yPos].priority == INT_MAX) return;
            // Then, start at this end node (the PC) and loop backwards through the prev array until you make it back to the destination node, which occurs when the x and y is equal to that of the Trainer's position.
            j = 0;
            for (i = size - 1; m->trainers[k]->prev[i].x != m->trainers[k]->xPos && m->trainers[k]->prev[i].y != m->trainers[k]->yPos && i >= 0; i--)
            {
                if (m->trainers[k]->prev[i].x != 0 && m->trainers[k]->prev[i].y != 0)
                {
                    m->trainers[k]->path[j] = malloc(sizeof(coordinates_t));
                    m->trainers[k]->path[j]->x = m->trainers[k]->prev[i].x;
                    m->trainers[k]->path[j]->y = m->trainers[k]->prev[i].y;
                    j++;
                }
            }

            // Since CLion is not allowing me to debug at the moment, lets print out the contents of each Trainer's path and see what kind of data we're getting.
            if (m->trainers[k]->symbol == HIKERS) printf("HIKER NO. %d SHORTEST PATH\n", k + 1);
            else printf("RIVAL NO. %d SHORTEST PATH\n", k + 1);
            for (i = 0; i < j; i++)
            {
                printf("X: %d, Y: %d\n", m->trainers[k]->path[i]->y, m->trainers[k]->path[i]->x);
            }
            printf("\n");
        }
    }
}
*/