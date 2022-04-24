//
// Created by Devin Amdahl on 3/14/22.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdbool.h>

typedef struct coordinates
{
    int x, y;
} coordinates_t;

typedef struct npc
{
    // Stores the value of the character's x position (row).
    int xPos;
    // Stores the value of the character's y position (column).
    int yPos;
    // Stores the text representation of the character.
    char symbol;
    // Stores the text representation of the terrain in which the character was generated upon.
    char startingTerrain;
    // Stores the direction that the character is facing.
    int direction;
    // Stores the cost of each eight-possible moves that a Hiker and Rival can make.
    int directions[8];
    // Stores the index of the NPC's next move.
    coordinates_t nextMove;
    // Stores true if the NPC has reached the PC.
    bool atPC;
} npc_t;

typedef struct player
{
    // Stores the value of the character's x position (row).
    int xPos;
    // Stores the value of the character's y position (column).
    int yPos;
    // Stores the text representation of the character.
    char symbol;
    // Stores the text representation of the terrain in which the character was generated upon.
    char startingTerrain;
    // Stores the index of the PC's next move.
    coordinates_t nextMove;
} player_t;

#endif
