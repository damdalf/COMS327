//
// Created by Devin Amdahl on 2/23/22.
//

#include "dijkstrasAlgorithm.h"

// Function to run Dijkstra's algorithm on the Trainer's cost maps.
void dijkstraTrainer(map_t *m, const int NUM_TRAINERS) // TODO ADD SHORTEST PATH FUNCTIONALITY
/*
 * TODO ADD A prev ARRAY THAT KEEPS TRACK OF THE INDEX OF THE NODE THAT
 * WAS TAKEN TO GET TO NODE I. INITIALLY, THE prev ARRAY SHOULD BE FILLED
 * WITH A SENTINEL VALUE, SUCH AS -1. WE WANT TO UPDATE THE ARRAY TO SAY
 * THAT THE NODE YOU ARE GOING TO, CAME FROM THE NODE YOU'RE CURRENTLY
 * AT. THEN, THIS ARRAY SHOULD BE RETURNED.
 */
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
void findShortestPathHikersAndRivals(map_t *m, const int NUM_TRAINERS)
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

            // Start at Trainer, choose the lowest-cost terrain cell.
            if (i - 1 > 0 && i + 1 < 79 && j - 1 > 0 && j + 1 < 20)
            {
                directions[0] = m->trainers[k]->costMap[i - 1][j].priority;
                directions[1] = m->trainers[k]->costMap[i - 1][j + 1].priority;
                directions[2] = m->trainers[k]->costMap[i][j + 1].priority;
                directions[3] = m->trainers[k]->costMap[i + 1][j + 1].priority;
                directions[4] = m->trainers[k]->costMap[i + 1][j].priority;
                directions[5] = m->trainers[k]->costMap[i + 1][j - 1].priority;
                directions[6] = m->trainers[k]->costMap[i][j - 1].priority;
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
                if (m->trainers[k]->xPos != i && m->trainers[k]->yPos != j) occupied = false;
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