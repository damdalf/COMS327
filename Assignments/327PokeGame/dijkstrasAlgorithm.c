//
// Created by Devin Amdahl on 2/23/22.
//

#include "dijkstrasAlgorithm.h"

// Function to run Dijkstra's algorithm on a provided Rival cost map.
void dijkstraRival(map_t *m, pc_t *p)
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

    distance[p->xPos][p->yPos] = 0;
    cost_node_t* pq = newNode(p->xPos, p->yPos, 0);

    while(!isEmpty(&pq))
    {
        x = peek(&pq).x;
        y = peek(&pq).y;
        pop(&pq);
        m->rivalCostMap[x][y].visited = true;

        // Check above neighbor.
        if ( x > 0 && m->rivalCostMap[x - 1][y].priority != INT_MAX)
        {
            if (!m->rivalCostMap[x - 1][y].visited)
            {
                newDist = distance[x][y] + m->rivalCostMap[x - 1][y].priority;
                if (newDist < distance[x - 1][y])
                {
                    distance[x - 1][y] = newDist;
                    if (pq == NULL) pq = newNode(x - 1, y, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x - 1, y, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check right-upper-diagonal neighbor.
        if (x > 0 && y < 79 && m->rivalCostMap[x - 1][y + 1].priority != INT_MAX)
        {
            if (!m->rivalCostMap[x - 1][y + 1].visited)
            {
                newDist = distance[x][y] + m->rivalCostMap[x -1][y + 1].priority;
                if (newDist < distance[x - 1][y + 1])
                {
                    distance[x - 1][y + 1] = newDist;
                    if (pq == NULL) pq = newNode(x - 1, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x - 1, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check right neighbor.
        if (y < 79 && m->rivalCostMap[x][y + 1].priority != INT_MAX)
        {
            if (!m->rivalCostMap[x][y + 1].visited)
            {
                newDist = distance[x][y] + m->rivalCostMap[x][y + 1].priority;
                if (newDist < distance[x][y + 1])
                {
                    distance[x][y + 1] = newDist;
                    if (pq == NULL) pq = newNode(x, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check right-lower-diagonal.
        if (x < 20 && y < 79 && m->rivalCostMap[x + 1][y + 1].priority != INT_MAX)
        {
            if (!m->rivalCostMap[x + 1][y + 1].visited)
            {
                newDist = distance[x][y] + m->rivalCostMap[x + 1][y + 1].priority;
                if (newDist < distance[x + 1][y + 1])
                {
                    distance[x + 1][y + 1] = newDist;
                    if (pq == NULL) pq = newNode(x + 1, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x + 1, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check below neighbor.
        if (x < 20 && m->rivalCostMap[x + 1][y].priority != INT_MAX)
        {
            if (!m->rivalCostMap[x + 1][y].visited)
            {
                newDist = distance[x][y] + m->rivalCostMap[x + 1][y].priority;
                if (newDist < distance[x + 1][y])
                {
                    distance[x + 1][y] = newDist;
                    if (pq == NULL) pq = newNode(x + 1, y, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x + 1, y, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check left-lower-diagonal neighbor.
        if (x < 20 && y > 0 && m->rivalCostMap[x + 1][y - 1].priority != INT_MAX)
        {
            if (!m->rivalCostMap[x + 1][y - 1].visited)
            {
                newDist = distance[x][y] + m->rivalCostMap[x + 1][y - 1].priority;
                if (newDist < distance[x + 1][y - 1])
                {
                    distance[x + 1][y - 1] = newDist;
                    if (pq == NULL) pq = newNode(x + 1, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x + 1, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check left neighbor.
        if (y > 0 && m->rivalCostMap[x][y - 1].priority != INT_MAX)
        {
            if (!m->rivalCostMap[x][y - 1].visited)
            {
                newDist = distance[x][y] + m->rivalCostMap[x][y - 1].priority;
                if (newDist < distance[x][y - 1])
                {
                    distance[x][y - 1] = newDist;
                    if (pq == NULL) pq = newNode(x, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check left-upper-diagonal neighbor.
        if (x > 0 && y > 0 && m->rivalCostMap[x - 1][y - 1].priority != INT_MAX)
        {
            if (!m->rivalCostMap[x - 1][y - 1].visited)
            {
                newDist = distance[x][y] + m->rivalCostMap[x - 1][y - 1].priority;
                if (newDist < distance[x - 1][y - 1])
                {
                    distance[x - 1][y - 1] = newDist;
                    if (pq == NULL) pq = newNode(x - 1, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x - 1, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }
    }

    // Copy contents of the distance array into the Rival cost map.
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            m->rivalCostMap[i][j].priority = distance[i][j];
        }
    }
}

// Function to run Dijkstra's algorithm on a provided Rival cost map.
void dijkstraHiker(map_t *m, pc_t *p)
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

    distance[p->xPos][p->yPos] = 0;
    cost_node_t* pq = newNode(p->xPos, p->yPos, 0);

    while(!isEmpty(&pq))
    {
        x = peek(&pq).x;
        y = peek(&pq).y;
        pop(&pq);
        m->hikerCostMap[x][y].visited = true;

        // Check above neighbor.
        if ( x > 0 && m->hikerCostMap[x - 1][y].priority != INT_MAX)
        {
            if (!m->hikerCostMap[x - 1][y].visited)
            {
                newDist = distance[x][y] + m->hikerCostMap[x - 1][y].priority;
                if (newDist < distance[x - 1][y])
                {
                    distance[x - 1][y] = newDist;
                    if (pq == NULL) pq = newNode(x - 1, y, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x - 1, y, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check right-upper-diagonal neighbor.
        if (x > 0 && y < 79 && m->hikerCostMap[x - 1][y + 1].priority != INT_MAX)
        {
            if (!m->hikerCostMap[x - 1][y + 1].visited)
            {
                newDist = distance[x][y] + m->hikerCostMap[x -1][y + 1].priority;
                if (newDist < distance[x - 1][y + 1])
                {
                    distance[x - 1][y + 1] = newDist;
                    if (pq == NULL) pq = newNode(x - 1, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x - 1, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check right neighbor.
        if (y < 79 && m->hikerCostMap[x][y + 1].priority != INT_MAX)
        {
            if (!m->hikerCostMap[x][y + 1].visited)
            {
                newDist = distance[x][y] + m->hikerCostMap[x][y + 1].priority;
                if (newDist < distance[x][y + 1])
                {
                    distance[x][y + 1] = newDist;
                    if (pq == NULL) pq = newNode(x, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check right-lower-diagonal.
        if (x < 20 && y < 79 && m->hikerCostMap[x + 1][y + 1].priority != INT_MAX)
        {
            if (!m->hikerCostMap[x + 1][y + 1].visited)
            {
                newDist = distance[x][y] + m->hikerCostMap[x + 1][y + 1].priority;
                if (newDist < distance[x + 1][y + 1])
                {
                    distance[x + 1][y + 1] = newDist;
                    if (pq == NULL) pq = newNode(x + 1, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x + 1, y + 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check below neighbor.
        if (x < 20 && m->hikerCostMap[x + 1][y].priority != INT_MAX)
        {
            if (!m->hikerCostMap[x + 1][y].visited)
            {
                newDist = distance[x][y] + m->hikerCostMap[x + 1][y].priority;
                if (newDist < distance[x + 1][y])
                {
                    distance[x + 1][y] = newDist;
                    if (pq == NULL) pq = newNode(x + 1, y, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x + 1, y, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check left-lower-diagonal neighbor.
        if (x < 20 && y > 0 && m->hikerCostMap[x + 1][y - 1].priority != INT_MAX)
        {
            if (!m->hikerCostMap[x + 1][y - 1].visited)
            {
                newDist = distance[x][y] + m->hikerCostMap[x + 1][y - 1].priority;
                if (newDist < distance[x + 1][y - 1])
                {
                    distance[x + 1][y - 1] = newDist;
                    if (pq == NULL) pq = newNode(x + 1, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x + 1, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check left neighbor.
        if (y > 0 && m->hikerCostMap[x][y - 1].priority != INT_MAX)
        {
            if (!m->hikerCostMap[x][y - 1].visited)
            {
                newDist = distance[x][y] + m->hikerCostMap[x][y - 1].priority;
                if (newDist < distance[x][y - 1])
                {
                    distance[x][y - 1] = newDist;
                    if (pq == NULL) pq = newNode(x, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }

        // Check left-upper-diagonal neighbor.
        if (x > 0 && y > 0 && m->hikerCostMap[x - 1][y - 1].priority != INT_MAX)
        {
            if (!m->hikerCostMap[x - 1][y - 1].visited)
            {
                newDist = distance[x][y] + m->hikerCostMap[x - 1][y - 1].priority;
                if (newDist < distance[x - 1][y - 1])
                {
                    distance[x - 1][y - 1] = newDist;
                    if (pq == NULL) pq = newNode(x - 1, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                    else push(&pq, x - 1, y - 1, newDist); // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
                }
            }
        }
    }

    // Copy contents of the distance array into the Rival cost map.
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            m->hikerCostMap[i][j].priority = distance[i][j];
        }
    }
}