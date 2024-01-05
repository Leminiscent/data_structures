#ifndef linked_list_hpp
#define linked_list_hpp

#include <iostream>

class linked_list
{
private:
    struct node
    {
        int value;  // Value stored in the node
        node *next; // Pointer to the next node in the list
    };
    node *head; // Pointer to the first node in the list

public:
    linked_list(int value);               // Constructor
    ~linked_list();                       // Destructor
    int get_at(int index);                // Returns the value at the given index
    void set_at(int index, int value);    // Sets the value at the given index
    void insert_at(int index, int value); // Inserts a new node at the given index
    void delete_at(int index);            // Deletes the node at the given index
    void insert_first(int value);         // Inserts a new node at the beginning of the list
    void delete_first();                  // Deletes the first node in the list
    void print_all();                     // Prints all the values in the list
};

#endif