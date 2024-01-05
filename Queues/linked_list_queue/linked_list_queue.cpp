#include "linked_list_queue.hpp"

linked_list_queue::linked_list_queue() : head(nullptr), tail(nullptr) {}

linked_list_queue::~linked_list_queue()
{
    while (head)
    {
        node *tmp = head;  // Temporary pointer to the current node.
        head = head->next; // Moves the head pointer to the next node.
        delete tmp;        // Deletes the current node, freeing memory.
    }
}

void linked_list_queue::enqueue(int value)
{
    node *new_node = new node{value, nullptr};

    if (tail) // If there's already a tail (i.e., the queue isn't empty),
    {
        tail->next = new_node; // the new node becomes the tail's next node.
    }
    else
    {
        head = new_node; // If the queue is empty, the new node becomes the head.
    }
    tail = new_node; // In both cases, the new node becomes the new tail.
}

int linked_list_queue::dequeue()
{
    if (!head) // If the queue is empty,
    {
        std::cerr << "Queue is empty." << std::endl; // print an error message and
        return -1;                                   // return -1 as an error value.
    }
    node *tmp = head;        // Temporary pointer to the current head node.
    int result = tmp->value; // Retrieves the value from the head node.

    head = head->next; // Moves the head pointer to the next node.
    if (!head)         // If the queue is now empty after the dequeue,
    {
        tail = nullptr; // sets the tail to nullptr.
    }
    delete tmp;    // Deletes the previous head node, freeing memory.
    return result; // Returns the dequeued value.
}

int linked_list_queue::peek() const
{
    if (!head) // If the queue is empty,
    {
        std::cerr << "Queue is empty." << std::endl; // print an error message and
        return -1;                                   // return -1 as an error value.
    }
    return head->value; // Returns the value of the head node.
}

bool linked_list_queue::is_empty() const
{
    return head == nullptr; // Returns true if the head pointer is nullptr, false otherwise.
}

void linked_list_queue::print_queue() const
{
    node *p = head; // Starts at the head of the queue.

    std::cout << "Queue elements: ";
    while (p) // While there are nodes left in the queue,
    {
        std::cout << p->value << " "; // prints each node's value and
        p = p->next;                  // moves to the next node.
    }
    std::cout << std::endl; // Ends the line after printing all values.
}