#ifndef rootish_array_stack_hpp
#define rootish_array_stack_hpp

#include <iostream>
#include <cmath>

class rootish_array_stack
{
private:
    int num_elements = 0;          // Number of elements currently in the stack.
    int num_blocks = 0;            // Number of blocks used by the stack.
    int **blocks;                  // A pointer to an array of pointers to blocks.
    int block_size(int b) const;   // Returns the size of the block number 'b'.
    int block_number(int i) const; // Returns the block number in which the i-th element is located.
    void grow();                   // Expands the number of blocks when needed.
    void shrink();                 // Reduces the number of blocks when feasible.

public:
    rootish_array_stack();  // Constructor for the stack.
    ~rootish_array_stack(); // Destructor to clean up allocated memory.
    int size() const;       // Returns the number of elements in the stack.
    int get(int i) const;   // Gets the i-th element.
    int set(int i, int x);  // Sets the i-th element to x and returns the old value.
    void add(int i, int x); // Adds element x at position i.
    void remove(int i);     // Removes the i-th element.
    void print_all() const; // Prints all the elements and the size of the stack.
};

#endif