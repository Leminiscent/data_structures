#ifndef doubly_linked_list_hpp
#define doubly_linked_list_hpp

#include <iostream>

class doubly_linked_list
{
private:
    struct node
    {
        int value;  // Data stored in the node.
        node *next; // Pointer to the next node in the list.
        node *prev; // Pointer to the previous node in the list.
    };
    node *head; // Pointer to the first node in the list.
    node *tail; // Pointer to the last node in the list.

public:
    doubly_linked_list(int value);        // Constructor.
    ~doubly_linked_list();                // Destructor.
    int get_at(int index);                // Function to retrieve the value stored at a specific index in the list.
    void set_at(int index, int value);    // Function to modify the value at a specific index in the list.
    void insert_at(int index, int value); // Function to insert a new value at a specific index in the list.
    void delete_at(int index);            // Function to delete the value at a specific index in the list.
    void insert_first(int value);         // Function to insert a new value at the beginning of the list.
    void delete_first();                  // Function to delete the value at the beginning of the list.
    void insert_last(int value);          // Function to insert a new value at the end of the list.
    void delete_last();                   // Function to delete the value at the end of the list.
    void print_all();                     // Function to print all values in the list.
};

#endif