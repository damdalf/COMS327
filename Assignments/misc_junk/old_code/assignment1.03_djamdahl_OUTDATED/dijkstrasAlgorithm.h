//
// Created by Devin Amdahl on 2/23/22.
//

#include "map.h"
#include "priorityQueue.h"

#ifndef DIJKSTRASALGORITHM_H
#define DIJKSTRASALGORITHM_H

// Function to run Dijkstra's algorithm on a provided Rival cost map.
void dijkstraRival(map_t *m, pc_t *p);

// Function to run Dijkstra's algorithm on a provided Hiker cost map.
void dijkstraHiker(map_t *m, pc_t *p);

#endif
