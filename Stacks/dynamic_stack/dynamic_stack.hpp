#ifndef dynamic_stack_hpp
#define dynamic_stack_hpp

#include <iostream>

class dynamic_stack
{
private:
    struct node
    {
        int value;  // Holds the value of the node.
        node *next; // Points to the next node in the stack.
    };

    node *top_node; // Pointer to the top node of the stack.

public:
    dynamic_stack();        // Constructor - Sets top_node to nullptr.
    ~dynamic_stack();       // Destructor - Removes all nodes from the stack.
    void push(int value);   // Adds a value to the top of the stack.
    int pop();              // Removes the top value from the stack and returns it.
    int top() const;        // Returns the top value of the stack without removing it.
    bool is_empty() const;  // Returns true if the stack is empty, false otherwise.
    void print_all() const; // Prints all values in the stack.
};

#endif