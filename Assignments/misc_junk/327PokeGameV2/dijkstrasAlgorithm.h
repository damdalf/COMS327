//
// Created by Devin Amdahl on 2/23/22.
//

#ifndef DIJKSTRASALGORITHM_H
#define DIJKSTRASALGORITHM_H

#include "priorityQueue.h"

// Function to run Dijkstra's algorithm on a Trainer's cost map.
void dijkstraTrainer(map_t *m, char npcType);

// Function to run Dijkstra's algorithm on the Trainer's cost maps.
void dijkstraTrainers(map_t *m);

// Function to run Dijkstra's algorithm on a provided PC cost map.
void dijkstraPC(map_t *m);

// Function to randomly generate the map.
void randomFullGeneration(map_t *m, const int NUM_TRAINERS);

#endif
