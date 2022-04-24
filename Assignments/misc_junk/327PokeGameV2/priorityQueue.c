// NOTE: The basis of this code comes from the following Geeks for Geeks article. However, I made some small adjustments for the code to fit my needs.
// C code to implement Priority Queue using Linked List

#include "priorityQueue.h"

// Function to Create A New Node
cost_node_t *newNode(int x, int y, int p)
{
    cost_node_t * temp = (cost_node_t *)malloc(sizeof(cost_node_t));
    temp->coords.x = x;
    temp->coords.y = y;
    temp->visited = false;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Function to create a new node, for NPC movement.
cost_node_t *newNodeMovement(int k, int x, int y, int p)
{
    cost_node_t * temp = (cost_node_t *)malloc(sizeof(cost_node_t));
    temp->trainerNumber = k;
    temp->coords.x = x;
    temp->coords.y = y;
    temp->visited = false;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Return the coordinates of the head.
coordinates_t peek(cost_node_t **head)
{
    return (*head)->coords;
}

// Return the trainerNumber of the head.
int peekMovement(cost_node_t **head)
{
    return (*head)->trainerNumber;
}

// Removes the element with the lowest priority form the list, and returns the priority.
int pop(cost_node_t **head)
{
    int cost = (*head)->priority;
    cost_node_t * temp = *head;
    (*head) = (*head)->next;
    free(temp);

    return cost;
}

// Function to push according to priority.
void push(cost_node_t **head, int x, int y, int p)
{
    cost_node_t *start = (*head);

    // Create new Node
    cost_node_t *temp = newNode(x, y, p);

    // Special Case: The head of list has greater priority (cost) than new node. So insert new node before head node and change head node.
    if ((*head)->priority > p)
    {

        // Insert New Node before head
        temp->next = *head;
        temp->coords.x = x;
        temp->coords.y = y;
        temp->visited = false;
        temp->priority = p;
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
        temp->coords.x = x;
        temp->coords.y = y;
        temp->visited = false;
        temp->priority = p;
        start->next = temp;
    }
}

// Function to push according to priority, for NPC movement.
void pushMovement(cost_node_t **head, int k, int x, int y, int p)
{
    cost_node_t *start = (*head);

    // Create new Node
    cost_node_t *temp = newNodeMovement(k, x, y, p);

    // Special Case: The head of list has greater priority (lower cost) than new node. So insert new node before head node and change head node.
    if ((*head)->priority > p)
    {

        // Insert New Node before head
        temp->trainerNumber = k;
        temp->next = *head;
        temp->coords.x = x;
        temp->coords.y = y;
        temp->visited = false;
        temp->priority = p;
        (*head) = temp;
    }
    else
    {
        // Traverse the list and find a position to insert new node
        while (start->next != NULL && start->next->priority < p)
        {
            start = start->next;
        }

        // Either at the end of the list or at required position.
        temp->trainerNumber = k;
        temp->next = start->next;
        temp->coords.x = x;
        temp->coords.y = y;
        temp->visited = false;
        temp->priority = p;
        start->next = temp;
    }
}

// Function to check is list is empty
int isEmpty(cost_node_t **head)
{
    return (*head) == NULL;
}