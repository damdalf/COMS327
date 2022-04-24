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

// Function to find the shortest path between two nodes (terrain cells).
void findShortestPathHikersAndRivals(map_t *m, const int NUM_TRAINERS);

#endif
