//
// Created by Devin Amdahl on 3/14/22.
//

#include "movement.h"

// Function to find the next move of one of the map's Hikers or Rivals, and update their location.
void findNextMoveHikersAndRivals(map_t *m, int k)
{
    int i, j, l, min, minIndex;

    // Store the Hiker or Rival's current position.
    i = m->trainers[k]->xPos;
    j = m->trainers[k]->yPos;

    // Hikers.
    if (m->trainers[k]->symbol == HIKERS)
    {
        // Start at Hiker, choose the lowest-cost terrain cell.
        if (i - 1 > 0 && i + 1 < HEIGHT - 1 && j - 1 > 0 && j + 1 < WIDTH - 1)
        {
            // Check if the direction of the movement in question is not already inhabited by another character. If it is, then set the direction cost to infinity.

            // N
            if ((m->characterArray[i - 1][j] == VACANT) && m->hikersCostMap[i - 1][j].priority < INT_MAX && m->trainers[k]->directions[0] < INT_MAX) m->trainers[k]->directions[0] = m->hikersCostMap[i - 1][j].priority;
            else m->trainers[k]->directions[0] = INT_MAX;
            // NE
            if ((m->characterArray[i - 1][j + 1] == VACANT) && m->hikersCostMap[i - 1][j + 1].priority < INT_MAX && m->trainers[k]->directions[1] < INT_MAX) m->trainers[k]->directions[1] = m->hikersCostMap[i - 1][j + 1].priority;
            else m->trainers[k]->directions[1] = INT_MAX;
            // E
            if ((m->characterArray[i][j + 1] == VACANT) && m->hikersCostMap[i][j + 1].priority < INT_MAX && m->trainers[k]->directions[2] < INT_MAX) m->trainers[k]->directions[2] = m->hikersCostMap[i][j + 1].priority;
            else m->trainers[k]->directions[2] = INT_MAX;
            // SE
            if ((m->characterArray[i - 1][j + 1] == VACANT) && m->hikersCostMap[i - 1][j + 1].priority < INT_MAX && m->trainers[k]->directions[3] < INT_MAX) m->trainers[k]->directions[3] = m->hikersCostMap[i - 1][j + 1].priority;
            else m->trainers[k]->directions[3] = INT_MAX;
            // S
            if ((m->characterArray[i + 1][j] == VACANT) && m->hikersCostMap[i + 1][j].priority < INT_MAX && m->trainers[k]->directions[4] < INT_MAX) m->trainers[k]->directions[4] = m->hikersCostMap[i + 1][j].priority;
            else m->trainers[k]->directions[4] = INT_MAX;
            // SW
            if ((m->characterArray[i + 1][j - 1] == VACANT) && m->hikersCostMap[i + 1][j - 1].priority < INT_MAX && m->trainers[k]->directions[5] < INT_MAX) m->trainers[k]->directions[5] = m->hikersCostMap[i + 1][j - 1].priority;
            else m->trainers[k]->directions[5] = INT_MAX;
            // W
            if ((m->characterArray[i][j - 1] == VACANT) && m->hikersCostMap[i][j - 1].priority < INT_MAX && m->trainers[k]->directions[6] < INT_MAX) m->trainers[k]->directions[6] = m->hikersCostMap[i][j - 1].priority;
            else m->trainers[k]->directions[6] = INT_MAX;
            // NW
            if ((m->characterArray[i - 1][j - 1] == VACANT) && m->hikersCostMap[i - 1][j - 1].priority < INT_MAX && m->trainers[k]->directions[7] < INT_MAX) m->trainers[k]->directions[7] = m->hikersCostMap[i - 1][j - 1].priority;
            else m->trainers[k]->directions[7] = INT_MAX;
        }
    }
    // Rivals.
    else
    {
        // Start at Rival, choose the lowest-cost terrain cell.
        if (i - 1 > 0 && i + 1 < HEIGHT - 1 && j - 1 > 0 && j + 1 < WIDTH - 1)
        {
            // Check if the direction of the movement in question is not already inhabited by another character. If it is, then set the direction cost to infinity.

            // N
            if ((m->characterArray[i - 1][j] == VACANT) && m->rivalsCostMap[i - 1][j].priority < INT_MAX && m->trainers[k]->directions[0] < INT_MAX) m->trainers[k]->directions[0] = m->rivalsCostMap[i - 1][j].priority;
            // If the space is occupied by another NPC, then it is inaccessible.
            else m->trainers[k]->directions[0] = INT_MAX;
            // NE
            if ((m->characterArray[i - 1][j + 1] == VACANT) && m->rivalsCostMap[i - 1][j + 1].priority < INT_MAX && m->trainers[k]->directions[1] < INT_MAX) m->trainers[k]->directions[1] = m->rivalsCostMap[i - 1][j + 1].priority;
            // If the space is occupied by another NPC, then it is inaccessible.
            else m->trainers[k]->directions[1] = INT_MAX;
            // E
            if ((m->characterArray[i][j + 1] == VACANT) && m->rivalsCostMap[i][j + 1].priority < INT_MAX && m->trainers[k]->directions[2] < INT_MAX) m->trainers[k]->directions[2] = m->rivalsCostMap[i][j + 1].priority;
            // If the space is occupied by another NPC, then it is inaccessible.
            else m->trainers[k]->directions[2] = INT_MAX;
            // SE
            if ((m->characterArray[i + 1][j + 1] == VACANT) && m->rivalsCostMap[i + 1][j + 1].priority < INT_MAX && m->trainers[k]->directions[3] < INT_MAX) m->trainers[k]->directions[3] = m->rivalsCostMap[i + 1][j + 1].priority;
            // If the space is occupied by another NPC, then it is inaccessible.
            else m->trainers[k]->directions[3] = INT_MAX;
            // S
            if ((m->characterArray[i + 1][j] == VACANT) && m->rivalsCostMap[i + 1][j].priority < INT_MAX && m->trainers[k]->directions[4] < INT_MAX) m->trainers[k]->directions[4] = m->rivalsCostMap[i + 1][j].priority;
            // If the space is occupied by another NPC, then it is inaccessible.
            else m->trainers[k]->directions[4] = INT_MAX;
            // SW
            if ((m->characterArray[i + 1][j - 1] == VACANT) && m->rivalsCostMap[i + 1][j - 1].priority < INT_MAX && m->trainers[k]->directions[5] < INT_MAX) m->trainers[k]->directions[5] = m->rivalsCostMap[i + 1][j - 1].priority;
            // If the space is occupied by another NPC, then it is inaccessible.
            else m->trainers[k]->directions[5] = INT_MAX;
            // W
            if ((m->characterArray[i][j - 1] == VACANT) && m->rivalsCostMap[i][j - 1].priority < INT_MAX && m->trainers[k]->directions[6] < INT_MAX) m->trainers[k]->directions[6] = m->rivalsCostMap[i][j - 1].priority;
            // If the space is occupied by another NPC, then it is inaccessible.
            else m->trainers[k]->directions[6] = INT_MAX;
            // NW
            if ((m->characterArray[i - 1][j - 1] == VACANT) && m->rivalsCostMap[i - 1][j - 1].priority < INT_MAX && m->trainers[k]->directions[7] < INT_MAX) m->trainers[k]->directions[7] = m->rivalsCostMap[i - 1][j - 1].priority;
            // If the space is occupied by another NPC, then it is inaccessible.
            else m->trainers[k]->directions[7] = INT_MAX;
        }

        min = m->trainers[k]->directions[0];
        minIndex = 0;
    }

    min = m->trainers[k]->directions[0];
    minIndex = 0;

    for (l = 0; l < 8; l++)
    {
        // Check if our lowest move is equal to 0, indicating that we are at the PC, and if no other NPC is already there.
        if (m->trainers[k]->directions[l] == 0)
        {
            m->trainers[k]->atPC = true;
            m->trainers[k]->directions[l] = INT_MAX;
            minIndex = l;
        }
        // Find the minimum cost move.
        else if (min > m->trainers[k]->directions[l])
        {
            min = m->trainers[k]->directions[l];
            minIndex = l;
        }
    }

    // Change coordinate positions (i and j) depending upon which direction was found to have the lowest cost.
    switch (minIndex)
    {
        // N
        case 0:
        {
            i -= 1;
            break;
        }
            // NE
        case 1:
        {
            i -= 1;
            j += 1;
            break;
        }
            // E
        case 2:
        {
            j += 1;
            break;
        }
            // SE
        case 3:
        {
            i += 1;
            j += 1;
            break;
        }
            // S
        case 4:
        {
            i += 1;
            break;
        }
            // SW
        case 5:
        {
            i += 1;
            j -= 1;
            break;
        }
            // W
        case 6:
        {
            j -= 1;
            break;
        }
            // NW
        case 7:
        {
            i -= 1;
            j -= 1;
            break;
        }
    }

    if (m->trainers[k]->atPC == true)
    {
        m->rivalsCostMap[i][j].priority = INT_MAX;
        m->hikersCostMap[i][j].priority = INT_MAX;
        m->trainers[k]->nextMove.x = m->trainers[k]->xPos;
        m->trainers[k]->nextMove.y = m->trainers[k]->yPos;
        return;
    }

    // Update the position of the Hiker and Rival.
    m->trainers[k]->nextMove.x = i;
    m->trainers[k]->nextMove.y = j;
}

// Function to find the next move for a Pacer, and update their location.
void findNextMovePacer(map_t *m, int k)
{
    int i, j;

    // Store Pacer's current position.
    i = m->trainers[k]->xPos;
    j = m->trainers[k]->yPos;

    // Check the Pacer's direction.
    switch (m->trainers[k]->direction)
    {
        case 0: // N
        {
            // Check if a valid position for the Pacer to move.
            if ((i - 1 > 0) && m->rivalsCostMap[i - 1][j].priority < INT_MAX && m->characterArray[i - 1][j] == VACANT)
            {
                i -= 1;
            }
                // If not a valid position, change direction and re-enter function.
            else
            {
                m->trainers[k]->direction = 4;
                //findNextMovePacer(m, k);
            }
            break;
        }
        case 1: // NE
        {
            // Check if a valid position for the Pacer to move.
            if ((i - 1 > 0 && j + 1 < WIDTH) && m->rivalsCostMap[i - 1][j + 1].priority < INT_MAX &&
                m->characterArray[i - 1][j + 1] == VACANT)
            {
                i -= 1;
                j += 1;
            }
            else
            {
                m->trainers[k]->direction = 5;
                //findNextMovePacer(m, k);
            }
        }
            break;
        case 2: // E
        {
            // Check if a valid position for the Pacer to move.
            if ((j + 1 < WIDTH) && m->rivalsCostMap[i][j + 1].priority < INT_MAX &&
                m->characterArray[i][j + 1] == VACANT)
            {
                j += 1;
            }
            else
            {
                m->trainers[k]->direction = 6;
                //findNextMovePacer(m, k);
            }
            break;
        }
        case 3: // SE
        {
            // Check if a valid position for the Pacer to move.
            if ((i + 1 < HEIGHT && j + 1 < WIDTH) && m->rivalsCostMap[i + 1][j + 1].priority < INT_MAX &&
                m->characterArray[i + 1][j + 1] == VACANT)
            {
                i += 1;
                j += 1;
            }
            else
            {
                m->trainers[k]->direction = 7;
                //findNextMovePacer(m, k);
            }
            break;
        }
        case 4: // S
        {
            // Check if a valid position for the Pacer to move.
            if ((i + 1 < HEIGHT) && m->rivalsCostMap[i + 1][j].priority < INT_MAX &&
                m->characterArray[i + 1][j] == VACANT)
            {
                i += 1;
            }
            else
            {
                m->trainers[k]->direction = 0;
                //findNextMovePacer(m, k);
            }
            break;
        }
        case 5: // SW
        {
            // Check if a valid position for the Pacer to move.
            if ((i + 1 < HEIGHT && j - 1 > 0) && m->rivalsCostMap[i + 1][j - 1].priority < INT_MAX &&
                m->characterArray[i + 1][j - 1] == VACANT)
            {
                i += 1;
                j -= 1;
            }
            else
            {
                m->trainers[k]->direction = 1;
                //findNextMovePacer(m, k);
            }
            break;
        }
        case 6: // W
        {
            // Check if a valid position for the Pacer to move.
            if ((j - 1 > 0) && m->rivalsCostMap[i][j - 1].priority < INT_MAX && m->characterArray[i][j - 1] == VACANT)
            {
                j -= 1;
            }
            else
            {
                m->trainers[k]->direction = 2;
                //findNextMovePacer(m, k);
            }
            break;
        }
        case 7: // NW
        {
            // Check if a valid position for the Pacer to move.
            if ((i - 1 > 0 && j - 1 > 0) && m->rivalsCostMap[i - 1][j - 1].priority < INT_MAX &&
                m->characterArray[i - 1][j - 1] == VACANT)
            {
                i -= 1;
                j -= 1;
            }
            else
            {
                m->trainers[k]->direction = 3;
                //findNextMovePacer(m, k);
            }
            break;
        }
    }

    // Update the location of the Pacer.
    m->trainers[k]->nextMove.x = i;
    m->trainers[k]->nextMove.y = j;
    //updateLocation(m, k);
}

// Function to find the next move for a Wanderer, and update their location.
void findNextMoveWanderer(map_t *m, int k)
{
    int i, j;

    // Store Wanderer's current position.
    i = m->trainers[k]->xPos;
    j = m->trainers[k]->yPos;

    switch (m->trainers[k]->direction)
    {
        case 0: // N
        {
            if ((i - 1 > 0) && m->mapArray[i - 1][j] == m->trainers[k]->startingTerrain &&
                m->characterArray[i - 1][j] == VACANT)
            {
                i -= 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveWanderer(m, k);
            }
            break;
        }
        case 1: // NE
        {
            if ((i - 1 > 0 && j + 1 < WIDTH) && m->mapArray[i - 1][j + 1] == m->trainers[k]->startingTerrain &&
                m->characterArray[i - 1][j + 1] == VACANT)
            {
                i -= 1;
                j += 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveWanderer(m, k);
            }
            break;
        }
        case 2: // E
        {
            if ((j + 1 < WIDTH) && m->mapArray[i][j + 1] == m->trainers[k]->startingTerrain &&
                m->characterArray[i][j + 1] == VACANT)
            {
                j += 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveWanderer(m, k);
            }
            break;
        }
        case 3: // SE
        {
            if ((i + 1 < HEIGHT && j + 1 < WIDTH) &&
                m->mapArray[i + 1][j + 1] == m->trainers[k]->startingTerrain &&
                m->characterArray[i + 1][j + 1] == VACANT)
            {
                i += 1;
                j += 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveWanderer(m, k);
            }
            break;
        }
        case 4: // S
        {
            if ((i + 1 < HEIGHT) && m->mapArray[i + 1][j] == m->trainers[k]->startingTerrain &&
                m->characterArray[i + 1][j] == VACANT)
            {
                i += 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveWanderer(m, k);
            }
            break;
        }
        case 5: // SW
        {
            if ((i + 1 < HEIGHT && j - 1 > 0) && m->mapArray[i + 1][j - 1] == m->trainers[k]->startingTerrain &&
                m->characterArray[i + 1][j - 1] == VACANT)
            {
                i += 1;
                j -= 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveWanderer(m, k);
            }
            break;
        }
        case 6: // W
        {
            if ((j - 1 > 0) && m->mapArray[i][j - 1] == m->trainers[k]->startingTerrain && m->characterArray[i][j - 1] == VACANT)
            {
                j -= 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveWanderer(m, k);
            }
            break;
        }
        case 7: // NW
        {
            if ((i - 1 > 0 && j - 1 > 0) && m->mapArray[i - 1][j - 1] == m->trainers[k]->startingTerrain &&
                m->characterArray[i - 1][j - 1] == VACANT)
            {
                i -= 1;
                j -= 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveWanderer(m, k);
            }
            break;
        }
    }

    // Update the location of the Wanderer.
    m->trainers[k]->nextMove.x = i;
    m->trainers[k]->nextMove.y = j;
    //updateLocation(m, k);
}

// Function to find the next move for a Random Walker, and update their location.
void findNextMoveRandomWalker(map_t *m, int k)
{
    int i, j;

    // Store Random Walker's current position and previous terrain.
    i = m->trainers[k]->xPos;
    j = m->trainers[k]->yPos;

    switch (m->trainers[k]->direction)
    {
        case 0: // N
        {
            if ((i - 1 > 0) && m->rivalsCostMap[i - 1][j].priority < INT_MAX && m->characterArray[i - 1][j] == VACANT)
            {
                i -= 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveRandomWalker(m, k);
            }
            break;
        }
        case 1: // NE
        {
            if ((i - 1 > 0 && j + 1 < WIDTH) && m->rivalsCostMap[i - 1][j + 1].priority < INT_MAX && m->characterArray[i - 1][j + 1] == VACANT)
            {
                i -= 1;
                j += 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveRandomWalker(m, k);
            }
            break;
        }
        case 2: // E
        {
            if ((j + 1 < WIDTH) && m->rivalsCostMap[i][j + 1].priority < INT_MAX && m->characterArray[i][j + 1] == VACANT)
            {
                j += 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveRandomWalker(m, k);
            }
            break;
        }
        case 3: // SE
        {
            if ((i + 1 < HEIGHT && j + 1 < WIDTH) && m->rivalsCostMap[i + 1][j + 1].priority < INT_MAX && m->characterArray[i + 1][j + 1] == VACANT)
            {
                i += 1;
                j += 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveRandomWalker(m, k);
            }
            break;
        }
        case 4: // S
        {
            if ((i + 1 < HEIGHT) && m->rivalsCostMap[i + 1][j].priority < INT_MAX && m->characterArray[i + 1][j] == VACANT)
            {
                i += 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveRandomWalker(m, k);
            }
            break;
        }
        case 5: // SW
        {
            if ((i + 1 < HEIGHT && j - 1 > 0) && m->rivalsCostMap[i + 1][j - 1].priority < INT_MAX && m->characterArray[i + 1][j - 1] == VACANT)
            {
                i += 1;
                j -= 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveRandomWalker(m, k);
            }
            break;
        }
        case 6: // W
        {
            if ((j - 1 > 0) && m->rivalsCostMap[i][j - 1].priority < INT_MAX && m->characterArray[i][j - 1] == VACANT)
            {
                j -= 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveRandomWalker(m, k);
            }
            break;
        }
        case 7: // NW
        {
            if ((i - 1 > 0 && j - 1 > 0) && m->rivalsCostMap[i - 1][j - 1].priority < INT_MAX && m->characterArray[i - 1][j - 1] == VACANT)
            {
                i -= 1;
                j -= 1;
            }
            else
            {
                generateDirections(m, k);
                //findNextMoveRandomWalker(m, k);
            }
            break;
        }
    }

    // Update the location of the Random Walker.
    m->trainers[k]->nextMove.x = i;
    m->trainers[k]->nextMove.y = j;
    //updateLocation(m, k);
}


// Function to find the next moves for each Trainer present in the game, and update their locations.
void findNextMoves(map_t *m, const int NUM_TRAINERS)
{
    int k;

    for (k = 0; k < NUM_TRAINERS; k++)
    {
        if (m->trainers[k]->atPC == false)
        {
            switch (m->trainers[k]->symbol)
            {
                case STATIONARIES:
                {
                    m->trainers[k]->nextMove.x = INT_MAX;
                    m->trainers[k]->nextMove.y = INT_MAX;
                    break;
                }
                case PACERS:
                {
                    findNextMovePacer(m, k);
                    break;
                }
                case WANDERERS:
                {
                    findNextMoveWanderer(m, k);
                    break;
                }
                case RANDOM_WALKERS:
                {
                    findNextMoveRandomWalker(m, k);
                    break;
                }
                case HIKERS:
                {
                    findNextMoveHikersAndRivals(m, k);
                    break;
                }
                case RIVALS:
                {
                    findNextMoveHikersAndRivals(m, k);
                    break;
                }
            }
        }

    }
}

// Function to update a NPC's location.
void updateLocation(map_t *m, int k)
{
    if (m->trainers[k]->atPC == false)
    {
        // Remove the NPCs from their previous locations on the characterArray.
        m->characterArray[m->trainers[k]->xPos][m->trainers[k]->yPos] = VACANT;
        // Update the NPC's current position to their next move coordinates.
        m->trainers[k]->xPos = m->trainers[k]->nextMove.x;
        m->trainers[k]->yPos = m->trainers[k]->nextMove.y;
        // Update the location of the NPC's on the characterArray.
        m->characterArray[m->trainers[k]->xPos][m->trainers[k]->yPos] = m->trainers[k]->symbol;
    }
}

// Function to update the locations of the Trainers present in the game after a call of 'findNextMoves()'.
// Moves are updated in increasing order (of cost) using my singly-linked list implementation of a priority queue.
void updateTrainerLocations(map_t *m, const int NUM_TRAINERS)
{
    int k;
    cost_node_t *pq = newNodeMovement(INT_MAX, INT_MAX, INT_MAX, INT_MAX);

    // Find the next move for all the NPCs within the map.
    //findNextMoves(m, NUM_TRAINERS);

    // After finding the next moves for all the NPCs within the map, we need to add these new positions to a priority queue based on their cost.
    for (k = 0; k < NUM_TRAINERS; k++)
    {
        if (m->trainers[k]->symbol == HIKERS)
        {
            findNextMoveHikersAndRivals(m, k);

            switch (m->mapArray[m->trainers[k]->nextMove.x][m->trainers[k]->nextMove.y])
            {
                case TREE:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 15);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 15);
                    break;
                }
                case PATH:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    break;
                }
                case GRASS:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 15);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 15);
                    break;
                }
                case CLEARING:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    break;
                }
                case ROCK:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 15);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 15);
                    break;
                }
                case FLOWER:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    break;
                }
            }
        }
        else if (m->trainers[k]->symbol != STATIONARIES)
        {
            switch (m->trainers[k]->symbol)
            {
                case RIVALS:
                {
                    findNextMoveHikersAndRivals(m, k);
                    break;
                }
                case PACERS:
                {
                    findNextMovePacer(m, k);
                    break;
                }
                case WANDERERS:
                {
                    findNextMoveWanderer(m, k);
                    break;
                }
                case RANDOM_WALKERS:
                {
                    findNextMoveRandomWalker(m, k);
                    break;
                }
            }
            switch (m->mapArray[m->trainers[k]->nextMove.x][m->trainers[k]->nextMove.y])
            {
                case PATH:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    break;
                }
                case GRASS:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 20);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 20);
                    break;
                }
                case CLEARING:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    break;
                }
                case FLOWER:
                {
                    if (m->trainers[k]->atPC == true) break;

                    if (isEmpty(&pq)) pq = newNodeMovement(k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    else pushMovement(&pq, k, m->trainers[k]->nextMove.x, m->trainers[k]->nextMove.y, 10);
                    break;
                }
            }
        }

    }

    // Now, while the priority queue contains moves to be made, lets update the locations of our NPCs, and removing the lowest cost move every iteration.
    while (!isEmpty(&pq))
    {
        if ((*pq).coords.x == INT_MAX)
        {
            pop(&pq);
        }
        else
        {
            updateLocation(m, peekMovement(&pq));
            pop(&pq);
        }

        printMap(m);
    }
}

// TODO USING NEXT MOVE IS NOT WORKING, GOING TO TRY UPDATING LOCATIONS WITHIN FUNCTIONS AND ADDING CURRENT MOVES TO PQ.