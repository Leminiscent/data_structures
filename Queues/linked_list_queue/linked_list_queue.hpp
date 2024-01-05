#ifndef linked_list_queue_hpp
#define linked_list_queue_hpp

#include <iostream>

class linked_list_queue
{
private:
    struct node
    {
        int value;  // Holds the value/data of the node.
        node *next; // Pointer to the next node in the queue.
    };
    node *head; // Pointer to the first node in the queue.
    node *tail; // Pointer to the last node in the queue.

public:
    linked_list_queue();  // Constructor. Initializes an empty queue.
    ~linked_list_queue(); // Destructor. Releases all the memory used by the queue.
    void enqueue(int value);  // Inserts a value at the end of the queue.
    int dequeue();            // Removes and returns the value from the front of the queue.
    int peek() const;         // Returns the value at the front of the queue without removing it.
    bool is_empty() const;    // Checks if the queue is empty.
    void print_queue() const; // Prints all the elements of the queue.
};

#endif