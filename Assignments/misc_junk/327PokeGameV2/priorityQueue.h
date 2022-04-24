//
// Created by Devin Amdahl on 2/24/22.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "world.h"

// NOTE: The basis of this code comes from the following Geeks for Geeks article. However, I made some small adjustments for the code to fit my needs.
// C code to implement Priority Queue using Linked List

// Function to create a new node, for Dijkstra's algorithm.
cost_node_t *newNode(int x, int y, int p);

// Function to create a new node, for NPC movement.
cost_node_t *newNodeMovement(int k, int x, int y, int p);

// Return the coordinate values of the head.
coordinates_t peek(cost_node_t **head);

// Return the trainerNumber of the head.
int peekMovement(cost_node_t **head);

// Removes the element with the highest priority form the list
int pop(cost_node_t ** head);

// Function to push according to priority, for Dijkstra's algorithm.
void push(cost_node_t **head, int x, int y, int p);

// Function to push according to priority, for NPC movement.
void pushMovement(cost_node_t **head, int k, int x, int y, int p);

// Function to check is list is empty
int isEmpty(cost_node_t ** head);

#endif
