//
// Created by Devin Amdahl on 3/14/22.
//

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "dijkstrasAlgorithm.h"

// Function to update a NPC's location.
void updateLocation(map_t *m, int k);

// Function to find the next move of one of the map's Hikers or Rivals.
void findNextMoveHikersAndRivals(map_t *m, int k);

// Function to find the next move for the Pacers.
void findNextMovePacer(map_t *m, int k);

// Function to find the next move for the Wanderers.
void findNextMoveWanderer(map_t *m, int k);

// Function to find the next move for the Random Walkers.
void findNextMoveRandomWalker(map_t *m, int k);

// Function to call the above next move methods for each Trainer present in the game.
void findNextMoves(map_t *m, const int NUM_TRAINERS);

// Function to update the locations of the Trainers present in the game after a call of 'findNextMoves()'.
void updateTrainerLocations(map_t*m, const int NUM_TRAINERS);

#endif
