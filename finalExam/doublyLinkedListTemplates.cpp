#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
public:
    // public variables
    T payload;
    Node<T> *next;
    Node<T> *prev;

    // constructor
    Node(T new_payload)
    {
        payload = new_payload;
    }

    // default constructor
    Node()
    {

    }

    // deconstructor
    ~Node()
    {
        delete next;
        delete prev;
    }

    // inserting a node at the end of the list
    void append(Node<T> **head_node, T new_payload)
    {
        Node<T> *new_node = new Node<T>(new_payload);
        // since adding to the end of the list, new_node's 'next' will be NULL
        new_node->next = NULL;

        // now time to check if the list is empty
        if (*head_node == NULL)
        {
            // if empty, new_node becomes the head of the list
            new_node->prev = NULL;
            *head_node = new_node;
            return;
        }

        // if we have not returned at this point, the list is not empty. now we must traverse the list until we find the end of it
        Node<T> *end = *head_node;
        while (end->next != NULL)
        {
            end = end->next;
        }

        // now that we have found the end of the list, it is time to append the new_node
        end->next = new_node;
        new_node->prev = end;
    }

    // inserting a Node at the head of the list
    void push(Node<T> **head_node, T new_payload)
    {
        Node<T> *new_node = new Node<T>(new_payload);

        new_node->next = *head_node;
        new_node->prev = NULL;

        // must change 'prev' of old head to be the new_node
        if (*head_node != NULL)
        {
            *head_node->prev = new_node;
        }
        // 'head' Node must now point to the new_node
        *head_node = new_node;
    }

    // inserting a Node after a specified node
    void insert_after(Node<T> *prev_node, T new_payload)
    {
        // can't overlook, must check if the Node we are inserting after actually exists
        if (prev_node != NULL)
        {
            Node<T> *new_node = new Node<T>(new_payload);

            // set the new_node's 'next' Node to equal the prev_node's 'next' Node
            new_node->next = prev_node->next;

            // check if new_node has a 'next' Node, if so, set this 'next' Node's 'prev' Node to be equal to the new_node
            if (new_node->next != NULL)
            {
                new_node->next->prev = new_node;
            }

            // change prev_node's 'next' to equal new_node, and the new_node's 'prev' to the prev_node
            prev_node->next = new_node;
            new_node->prev = prev_node;
        }
    }

    // inserting a node before a specified Node
    void insert_before(Node *next_node, T new_payload)
    {
        // can't overlook, must check if the Node we are inserting before actually exists
        if (next_node != NULL)
        {
            Node<T> *new_node = new Node<T>(new_payload);

            // set the new_node's 'prev' Node to the next_node's 'prev' Node
            new_node->prev = next_node->prev;

            // check if next_node has a 'prev' Node, if so, set this 'prev' Node's 'next' Node to be equal to the new_node
            if (next_node->prev != NULL)
            {
                new_node->prev->next = new_node;
            }

            // change next_node's 'prev' to equal to new_node, and the new_node's 'next' to the next_node
            next_node->prev = new_node;
            new_node->next = next_node;
        }
    }


    void print_head_to_tail(Node<T> **head_node)
    {
        Node<T> *next = *head_node;
        while (next->next != NULL) {
            cout << next->payload << "," << endl;
            next = next->next;
        }

        // print the last Node's payload
        cout << next->payload << endl;
    }
};

template<class T>
ostream& operator<<(ostream& stream, const T& payload)
    {
        stream << payload;
        return stream;
    }

int main()
{
    // Node* head = new Node(1);
    Node<string> *head = NULL;
    Node<int> *head2 = NULL;
    head->append(&head, "A");
    head->append(&head, "B");
    head->append(&head, "C");
    head->append(&head, "D");
    head->append(&head, "E");
    head2->append(&head2, 1);
    head2->append(&head2, 2);
    head2->append(&head2, 3);
    head2->append(&head2, 4);
    head2->append(&head2, 5);

    head->print_head_to_tail(&head);
    head2->print_head_to_tail(&head2);

    return 0;
}