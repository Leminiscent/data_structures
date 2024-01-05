#include "dynamic_stack.hpp"

dynamic_stack::dynamic_stack() : top_node(nullptr) {}

dynamic_stack::~dynamic_stack()
{
    while (!is_empty())
    {
        pop();
    }
}

void dynamic_stack::push(int value)
{
    node *new_node = new node{value, top_node}; // Create new node with value and current top_node as next.
    top_node = new_node;                        // Update the top_node to point to the new node.
}

int dynamic_stack::pop()
{
    if (is_empty()) // If the stack is empty, print an error and return -1.
    {
        std::cerr << "Stack is empty. Cannot pop." << std::endl;
        return -1;
    }
    int value = top_node->value; // Store the value of the top node.
    node *temp = top_node;       // Temporarily store the top node.

    top_node = top_node->next; // Update top_node to point to the next node.
    delete temp;               // Free the memory of the previously top node.
    return value;              // Return the value of the popped node.
}

int dynamic_stack::top() const
{
    if (is_empty())
    {
        std::cerr << "Stack is empty. Cannot get the top element." << std::endl;
        return -1;
    }
    return top_node->value; // Return the value of the top node.
}

bool dynamic_stack::is_empty() const
{
    return top_node == nullptr; // Returns true if top_node is null, indicating an empty stack.
}

void dynamic_stack::print_all() const
{
    node *p = top_node; // Start from the top node.
    int depth = 0;      // Counter to keep track of the stack's depth.

    std::cout << "Stack: ";
    while (p) // While p is not null, print the value of the node and move to the next node.
    {
        std::cout << p->value << " ";
        p = p->next; // Move to the next node.
        ++depth;     // Increment depth counter.
    }
    std::cout << std::endl;
    std::cout << "Depth: " << depth << std::endl; // Print the depth of the stack.
}