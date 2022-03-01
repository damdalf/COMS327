// NOTE: The basis of this code comes from the following Geeks for Geeks article. However, I made some small adjustments for the code to fit my needs.
// C code to implement Priority Queue using Linked List

#include "priorityQueue.h"

// Function to Create A New Node
cost_node_t * newNode(int x, int y, int p)
{
    cost_node_t * temp = (cost_node_t *)malloc(sizeof(cost_node_t));
    temp->coords.x = x;
    temp->coords.y = y;
    temp->visited = false;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Return the coordinates at the head
coordinates_t peek(cost_node_t ** head)
{
    return (*head)->coords;
}

// Removes the element with the highest priority form the list, and returns the priority.
int pop(cost_node_t ** head)
{
    int cost = (*head)->priority;
    cost_node_t * temp = *head;
    (*head) = (*head)->next;
    free(temp);

    return cost;
}

// Function to push according to priority
void push(cost_node_t** head, int x, int y, int p)
{
    cost_node_t* start = (*head);

    // Create new Node
    cost_node_t* temp = newNode(x, y, p);

    // Special Case: The head of list has greater priority (cost) than new node. So insert new node before head node and change head node.
    if ((*head)->priority > p)
    {

        // Insert New Node before head
        temp->next = *head;
        temp->coords.x = x; // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
        temp->coords.y = y; // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
        temp->visited = false; // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
        temp->priority = p; // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
        (*head) = temp;
    }
    else
    {
        // Traverse the list and find a position to insert new node
        while (start->next != NULL && start->next->priority < p)
        {
            start = start->next;
        }

        // Either at the ends of the list or at required position
        temp->next = start->next;
        temp->coords.x = x; // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
        temp->coords.y = y; // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
        temp->visited = false; // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
        temp->priority = p; // TODO THESE LINES WERE THE ISSUES IN MY 1.03 SUBMISSION
        start->next = temp;
    }
}

// Function to check is list is empty
int isEmpty(cost_node_t ** head)
{
    return (*head) == NULL;
}

