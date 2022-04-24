//
// Created by Devin Amdahl on 2/23/22.
//

#include "map.h"
#include "priorityQueue.h"

#ifndef DIJKSTRASALGORITHM_H
#define DIJKSTRASALGORITHM_H

// Function to run Dijkstra's algorithm on the Trainer's cost maps.
void dijkstraTrainer(map_t *m, const int NUM_TRAINERS);

// Function to run Dijkstra's algorithm on a provided PC cost map.
void dijkstraPC(map_t *m);

// Function to find the next move of all the Hikers and Rivals.
void findNextMoveHikersAndRivals(map_t *m, const int NUM_TRAINERS);

// Function to find the next move for the Pacers.
void findNextMovePacers(map_t *m, const int NUM_TRAINERS);

// Function to find the next move for the Wanderers.
void findNextMoveWanderers(map_t *m, const int NUM_TRAINERS);

// Function to find the next move for the Random Walkers.
void findNextMoveRandomWalkers(map_t *m, const int NUM_TRAINERS);

// Function to call the above next move methods for each Trainer present in the game.
void findNextMoves(map_t *m, const int NUM_TRAINERS);

// Function to update the locations of the Trainers present in the game after a call of 'findNextMoves()'.
void updateTrainerLocations(map_t*m, const int NUM_TRAINERS);

#endif
