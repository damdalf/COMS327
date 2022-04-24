//
// Created by Devin Amdahl on 2/23/22.
//

#include "dijkstrasAlgorithm.h"

// Function to run Dijkstra's algorithm on the Trainer's cost maps.
void dijkstraTrainer(map_t *m) // TODO ADD SHORTEST PATH FUNCTIONALITY
{
    int i, j, k;

    for (k = 0; k < 10; k++)
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

        distance[m->pc.xPos][m->pc.yPos] = 0;
        cost_node_t* pq = newNode(m->pc.xPos, m->pc.yPos, 0);

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