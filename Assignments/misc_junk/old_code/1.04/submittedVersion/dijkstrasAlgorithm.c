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
void findNextMoveHikersAndRival(map_t *m, int k, const int NUM_TRAINERS)
{
    if (m->trainers[k]->atPC == true) return;
    int i, j, l, min, minIndex, directions[8];

    i = m->trainers[k]->xPos;
    j = m->trainers[k]->yPos;

    // Start at Trainer, choose the lowest-cost terrain cell.
    if (i - 1 > 0 && i + 1 < HEIGHT && j - 1 > 0 && j + 1 < WIDTH)
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
        directions[7] = m->trainers[k]->costMap[i - 1][j - 1].priority;
    }

    min = directions[0];
    minIndex = 0;

    for (l = 0; l < 8; l++)
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
            i -= 1;
            j -= 1;
            break;
    }
    // Ensure that new position is NOT already occupied by a Trainer or the PC.
    if (i < 20 && j < 79 && i > 0 && j > 0 && m->characterArray[i][j] == VACANT)
    {
        m->trainers[k]->nextMove.x = i;
        m->trainers[k]->nextMove.y = j;
        updateLocation(m, k);
    }
    // Check if cell is inhabited by PC.
    else if (i < 20 && j < 79 && i > 0 && j > 0 && m->characterArray[i][j] == PLAYER)
    {
        m->trainers[k]->atPC = true;
        return;
    }
    // Check if cell is inhabited by another NPC.
    else if (i < 20 && j < 79 && i > 0 && j > 0 && m->characterArray[i][j] != VACANT)
    {
        // If a position is filled by an NPC, check if that NPC is stuck there.
        for (l = 0; l < 10; l++)
        {
            // Locate the NPC that is in said position.
            if (m->trainers[l]->xPos == i && m->trainers[l]->yPos == j)
            {
                // If stuck, assign the cost for that cell to be infinity.
                if (m->trainers[l]->atPC) m->trainers[k]->costMap[i][j].priority = INT_MAX;
            }
        }
    }
}

// Function to find the next move for the Pacers.
void findNextMovePacer(map_t *m, int k)
{
    int i, j;

    // Store Pacer's current position and previous terrain.
    i = m->trainers[k]->xPos;
    j = m->trainers[k]->yPos;
    m->trainers[k]->previousTerrain = m->mapArray[i][j];

    switch(m->trainers[k]->direction)
    {
        case 0: // N
            if (i - 1 > 0)
            {
                if (m->mapArray[i - 1][j] != BORDER && m->mapArray[i - 1][j] != TREE && m->mapArray[i - 1][j] != ROCK && m->mapArray[i - 1][j] != MART
                    && m->mapArray[i - 1][j] != CENTER && m->mapArray[i - 1][j] != PLAYER)
                {
                    i -= 1;
                }
                else
                {
                    m->trainers[k]->direction = 4;
                    findNextMovePacer(m, k);
                }
            }
            break;
        case 1: // NE
            if (i - 1 > 0 && j + 1 < WIDTH)
            {
                if (m->mapArray[i - 1][j + 1] != BORDER && m->mapArray[i - 1][j + 1] != TREE && m->mapArray[i - 1][j + 1] != ROCK && m->mapArray[i - 1][j + 1] != MART
                    && m->mapArray[i - 1][j + 1] != CENTER && m->mapArray[i - 1][j + 1] != PLAYER)
                {
                    i -= 1;
                    j += 1;
                }
                else
                {
                    m->trainers[k]->direction = 5;
                    findNextMovePacer(m, k);
                }
            }
            break;
        case 2: // E
            if (j + 1 < WIDTH)
            {
                if (m->mapArray[i][j + 1] != BORDER && m->mapArray[i][j + 1] != TREE && m->mapArray[i][j + 1] != ROCK && m->mapArray[i][j + 1] != MART
                    && m->mapArray[i][j + 1] != CENTER && m->mapArray[i][j + 1] != PLAYER)
                {
                    j += 1;
                }
                else
                {
                    m->trainers[k]->direction = 6;
                    findNextMovePacer(m, k);
                }
            }
            break;
        case 3: // SE
            if (i + 1 < HEIGHT && j + 1 < WIDTH)
            {
                if (m->mapArray[i + 1][j + 1] != BORDER && m->mapArray[i + 1][j + 1] != TREE && m->mapArray[i + 1][j + 1] != ROCK && m->mapArray[i + 1][j + 1] != MART
                    && m->mapArray[i + 1][j + 1] != CENTER && m->mapArray[i + 1][j + 1] != PLAYER)
                {
                    i += 1;
                    j += 1;
                }
                else
                {
                    m->trainers[k]->direction = 7;
                    findNextMovePacer(m, k);
                }
            }
            break;
        case 4: // S
            if (i + 1 <= HEIGHT)
            {
                if (m->mapArray[i + 1][j] != BORDER && m->mapArray[i + 1][j] != TREE && m->mapArray[i + 1][j] != ROCK && m->mapArray[i + 1][j] != MART
                    && m->mapArray[i + 1][j] != CENTER && m->mapArray[i + 1][j] != PLAYER)
                {
                    i += 1;
                }
                else
                {
                    m->trainers[k]->direction = 0;
                    findNextMovePacer(m, k);
                }
            }
            break;
        case 5: // SW
            if (i + 1 < HEIGHT && j - 1 > 0)
            {
                if (m->mapArray[i + 1][j - 1] != BORDER && m->mapArray[i + 1][j - 1] != TREE && m->mapArray[i + 1][j - 1] != ROCK && m->mapArray[i + 1][j - 1] != MART
                    && m->mapArray[i + 1][j - 1] != CENTER && m->mapArray[i + 1][j - 1] != PLAYER)
                {
                    i += 1;
                    j -= 1;
                }
                else
                {
                    m->trainers[k]->direction = 1;
                    findNextMovePacer(m, k);
                }
            }
            break;
        case 6: // W
            if (j - 1 > 0)
            {
                if (m->mapArray[i][j - 1] != BORDER && m->mapArray[i][j - 1] != TREE && m->mapArray[i][j - 1] != ROCK && m->mapArray[i][j - 1] != MART
                    && m->mapArray[i][j - 1] != CENTER && m->mapArray[i][j - 1] != PLAYER)
                {
                    j -= 1;
                }
                else
                {
                    m->trainers[k]->direction = 2;
                    findNextMovePacer(m, k);
                }
            }
            break;
        case 7: // NW
            if (i - 1 > 0 && j - 1 > 0)
            {
                if (m->mapArray[i - 1][j - 1] != BORDER && m->mapArray[i - 1][j - 1] != TREE && m->mapArray[i - 1][j - 1] != ROCK && m->mapArray[i - 1][j - 1] != MART
                    && m->mapArray[i - 1][j - 1] != CENTER && m->mapArray[i - 1][j - 1] != PLAYER)
                {
                    i -= 1;
                    j -= 1;
                }
                else
                {
                    m->trainers[k]->direction = 3;
                    findNextMovePacer(m, k);
                }
            }
            break;
    }

    // Print Pacer's current information.
    //printf("PACER (TRAINER NO. %d's) CURRENT DIRECTION: %d\n", k + 1, m->trainers[k]->direction);
    //printf("PACER (TRAINER NO. %d's) CURRENT LOCATION: X = %d, Y = %d\n", k + 1, m->trainers[k]->yPos, m->trainers[k]->xPos);

    // Ensure that new position is not already occupied by a Trainer or the PC, and that the Trainer has not changed direction.
    if (i < 20 && j < 79 && i > 0 && j > 0 && m->characterArray[i][j] == VACANT)
    {
        m->trainers[k]->nextMove.x = i;
        m->trainers[k]->nextMove.y = j;
        updateLocation(m, k);
    }
    else if (i < 20 && j < 79 && i > 0 && j > 0 && m->characterArray[i][j] != VACANT)
    {
        switch(m->trainers[k]->direction)
        {
            case 0:
                m->trainers[k]->direction = 1;
                break;
            case 1:
                m->trainers[k]->direction = 5;
                break;
            case 2:
                m->trainers[k]->direction = 6;
                break;
            case 3:
                m->trainers[k]->direction = 5;
                break;
            case 4:
                m->trainers[k]->direction = 0;
                break;
            case 5:
                m->trainers[k]->direction = 1;
                break;
            case 6:
                m->trainers[k]->direction = 2;
                break;
            case 7:
                m->trainers[k]->direction = 3;
                break;
        }
    }
}

// Function to find the next move for the Wanderers.
void findNextMoveWanderer(map_t *m, int k)
{
    int i, j;

    // Store Wanderer's current position and previous terrain.
    i = m->trainers[k]->xPos;
    j = m->trainers[k]->yPos;

    switch (m->trainers[k]->direction) {
        case 0: // N
            if (i - 1 > 0) {
                if (m->mapArray[i - 1][j] != m->trainers[k]->previousTerrain) {
                    generateDirections(m, k);
                    findNextMoveWanderer(m, k);
                } else {
                    i -= 1;
                }
            }
            break;
        case 1: // NE
            if (i - 1 > 0 && j + 1 < WIDTH) {
                if (m->mapArray[i - 1][j + 1] != m->trainers[k]->previousTerrain) {
                    generateDirections(m, k);
                    findNextMoveWanderer(m, k);
                } else {
                    i -= 1;
                    j += 1;
                }
            }
            break;
        case 2: // E
            if (j + 1 < WIDTH) {
                if (m->mapArray[i][j + 1] != m->trainers[k]->previousTerrain) {
                    generateDirections(m, k);
                    findNextMoveWanderer(m, k);
                } else {
                    j += 1;
                }
            }
            break;
        case 3: // SE
            if (i + 1 < HEIGHT && j + 1 < WIDTH) {
                if (m->mapArray[i + 1][j + 1] != m->trainers[k]->previousTerrain) {
                    generateDirections(m, k);
                    findNextMoveWanderer(m, k);
                } else {
                    i += 1;
                    j += 1;
                }
            }
            break;
        case 4: // S
            if (i + 1 < HEIGHT) {
                if (m->mapArray[i + 1][j] != m->trainers[k]->previousTerrain) {
                    generateDirections(m, k);
                    findNextMoveWanderer(m, k);
                } else {
                    i += 1;
                }
            }
            break;
        case 5: // SW
            if (i + 1 < HEIGHT && j - 1 > 0) {

            }
            if (m->mapArray[i + 1][j - 1] != m->trainers[k]->previousTerrain) {
                generateDirections(m, k);
                findNextMoveWanderer(m, k);
            } else {
                i += 1;
                j -= 1;
            }
            break;
        case 6: // W
            if (j - 1 > 0) {
                if (m->mapArray[i][j - 1] != m->trainers[k]->previousTerrain) {
                    generateDirections(m, k);
                    findNextMoveWanderer(m, k);
                } else {
                    j -= 1;
                }
            }
            break;
        case 7: // NW
            if (i - 1 > 0 && j - 1 > 0) {
                if (m->mapArray[i - 1][j - 1] != m->trainers[k]->previousTerrain) {
                    generateDirections(m, k);
                    findNextMoveWanderer(m, k);
                } else {
                    i -= 1;
                    j -= 1;
                }
            }
            break;
    }

    // Ensure that new position is not already occupied by a Trainer or the PC, and that the Trainer has not changed direction.
    if (i < 20 && j < 79 && i > 1 && j > 1 && m->characterArray[i][j] == VACANT)
    {
        m->trainers[k]->nextMove.x = i;
        m->trainers[k]->nextMove.y = j;
        updateLocation(m, k);
    }
    else if (i < 20 && j < 79 && i > 0 && j > 0 && m->characterArray[i][j] != VACANT) generateDirections(m, k);
}

// Function to find the next move for the Random Walkers.
void findNextMoveRandomWalker(map_t *m, int k)
{
    int i, j;

    // Store Random Walker's current position and previous terrain.
    i = m->trainers[k]->xPos;
    j = m->trainers[k]->yPos;

    switch (m->trainers[k]->direction) {
        case 0: // N
            if (i - 1 > 0)
            {
                if (m->mapArray[i - 1][j] != BORDER && m->mapArray[i - 1][j] != TREE && m->mapArray[i - 1][j] != ROCK && m->mapArray[i - 1][j] != MART
                    && m->mapArray[i - 1][j] != CENTER && m->mapArray[i - 1][j] != PLAYER)
                {
                    i -= 1;
                }
                else
                {
                    generateDirections(m, k);
                    findNextMoveRandomWalker(m, k);
                }
            }
            break;
        case 1: // NE
            if (i - 1 > 0 && j + 1 < WIDTH)
            {
                if (m->mapArray[i - 1][j + 1] != BORDER && m->mapArray[i - 1][j + 1] != TREE && m->mapArray[i - 1][j + 1] != ROCK && m->mapArray[i - 1][j + 1] != MART
                    && m->mapArray[i - 1][j + 1] != CENTER && m->mapArray[i - 1][j + 1] != PLAYER)
                {
                    i -= 1;
                    j += 1;
                }
                else
                {
                    generateDirections(m, k);
                    findNextMoveRandomWalker(m, k);
                }
            }
            break;
        case 2: // E
            if (j + 1 < WIDTH)
            {
                if (m->mapArray[i][j + 1] != BORDER && m->mapArray[i][j + 1] != TREE && m->mapArray[i][j + 1] != ROCK && m->mapArray[i][j + 1] != MART
                    && m->mapArray[i][j + 1] != CENTER && m->mapArray[i][j + 1] != PLAYER)
                {
                    j += 1;
                }
                else
                {
                    generateDirections(m, k);
                    findNextMoveRandomWalker(m, k);
                }
            }
            break;
        case 3: // SE
            if (i + 1 < HEIGHT && j + 1 < WIDTH)
            {
                if (m->mapArray[i + 1][j + 1] != BORDER && m->mapArray[i + 1][j + 1] != TREE && m->mapArray[i + 1][j + 1] != ROCK && m->mapArray[i + 1][j + 1] != MART
                    && m->mapArray[i + 1][j + 1] != CENTER && m->mapArray[i + 1][j + 1] != PLAYER)
                {
                    i += 1;
                    j += 1;
                }
                else
                {
                    generateDirections(m, k);
                    findNextMoveRandomWalker(m, k);
                }
            }
            break;
        case 4: // S
            if (i + 1 < HEIGHT)
            {
                if (m->mapArray[i + 1][j] != BORDER && m->mapArray[i + 1][j] != TREE && m->mapArray[i + 1][j] != ROCK && m->mapArray[i + 1][j] != MART
                    && m->mapArray[i + 1][j] != CENTER && m->mapArray[i + 1][j] != PLAYER)
                {
                    i += 1;
                }
                else
                {
                    generateDirections(m, k);
                    findNextMoveRandomWalker(m, k);
                }
            }
            break;
        case 5: // SW
            if (i + 1 < HEIGHT && j - 1 > 0)
            {
                if (m->mapArray[i + 1][j - 1] != BORDER && m->mapArray[i + 1][j - 1] != TREE && m->mapArray[i + 1][j - 1] != ROCK && m->mapArray[i + 1][j - 1] != MART
                    && m->mapArray[i + 1][j - 1] != CENTER && m->mapArray[i + 1][j - 1] != PLAYER)
                {
                    i += 1;
                    j -= 1;
                }
                else
                {
                    generateDirections(m, k);
                    findNextMoveRandomWalker(m, k);
                }
            }
            break;
        case 6: // W
            if (j - 1 > 0)
            {
                if (m->mapArray[i][j - 1] != BORDER && m->mapArray[i][j - 1] != TREE && m->mapArray[i][j - 1] != ROCK && m->mapArray[i][j - 1] != MART
                    && m->mapArray[i][j - 1] != CENTER && m->mapArray[i][j - 1] != PLAYER)
                {
                    j -= 1;
                }
                else
                {
                    generateDirections(m, k);
                    findNextMoveRandomWalker(m, k);
                }
            }
            break;
        case 7: // NW
            if (i - 1 > 0 && j - 1 > 0)
            {
                if (m->mapArray[i - 1][j - 1] != BORDER && m->mapArray[i - 1][j - 1] != TREE && m->mapArray[i - 1][j - 1] != ROCK && m->mapArray[i - 1][j - 1] != MART
                    && m->mapArray[i - 1][j - 1] != CENTER  && m->mapArray[i - 1][j - 1] != PLAYER)
                {
                    i -= 1;
                    j -= 1;
                }
                else
                {
                    generateDirections(m, k);
                    findNextMoveRandomWalker(m, k);
                }
            }
            break;
    }

    if (i < 20 && j < 79 && i > 0 && j > 0 && m->characterArray[i][j] == VACANT)
    {
        m->trainers[k]->nextMove.x = i;
        m->trainers[k]->nextMove.y = j;
        updateLocation(m, k);
    }
    else if (i < 20 && j < 79 && i > 0 && j > 0 && m->characterArray[i][j] != VACANT) generateDirections(m, k);
}


// Function to call the above next move methods for each Trainer present in the game.
/*
void findNextMoves(map_t *m, const int NUM_TRAINERS)
{
    findNextMoveHikersAndRivals(m, NUM_TRAINERS);
    findNextMovePacers(m, NUM_TRAINERS);
    findNextMoveWanderers(m, NUM_TRAINERS);
    findNextMoveRandomWalkers(m, NUM_TRAINERS);
}
 */

// Function to update the locations of the Trainers present in the game after a call of 'findNextMoves()'.
void updateTrainerLocations(map_t*m, const int NUM_TRAINERS)
{
    int k;

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        // Check if the particular NPC is within range of the PC.
        if (m->trainers[k]->atPC == true)
        {
            // if the NPC is within range of the PC, no more moves for the particular character need to be made.
            continue;
        }
        if (m->trainers[k]->symbol != STATIONARIES)
        {
                switch(m->trainers[k]->symbol)
                {
                    case HIKERS:
                        findNextMoveHikersAndRival(m, k, NUM_TRAINERS);
                        break;
                    case RIVALS:
                        findNextMoveHikersAndRival(m, k, NUM_TRAINERS);
                    break;
                    case PACERS:
                        findNextMovePacer(m, k);
                        break;
                    case WANDERERS:
                        findNextMoveWanderer(m, k);
                        break;
                    case RANDOM_WALKERS:
                        findNextMoveRandomWalker(m, k);
                        break;
                }
        }
    }
    printMap(m);
}

// Function to update a NPC's location.
void updateLocation(map_t *m, int k)
{
    // Remove the NPC's from their previous locations on the characterArray.
    m->characterArray[m->trainers[k]->xPos][m->trainers[k]->yPos] = VACANT;
    // Update the Trainer's current position to their next move coordinates.
    m->trainers[k]->xPos = m->trainers[k]->nextMove.x;
    m->trainers[k]->yPos = m->trainers[k]->nextMove.y;
    // Update the location of the NPC's on the characterArray.
    m->characterArray[m->trainers[k]->xPos][m->trainers[k]->yPos] = m->trainers[k]->symbol;
}