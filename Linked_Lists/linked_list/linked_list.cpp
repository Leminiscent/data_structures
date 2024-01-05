#include "linked_list.hpp"

linked_list::linked_list(int value)
{
    head = new node{value, nullptr}; // Create a new node and set it as the head
}

linked_list::~linked_list()
{
    while (head) // Loop until the list is empty
    {
        node *tmp = head; // Temporary pointer to the current head

        head = head->next; // Move the head pointer to the next node
        delete tmp;        // Delete the node pointed by tmp
    }
}

int linked_list::get_at(int index)
{
    node *current = head; // Initialize a pointer to the head node
    int count = 0;        // Counter to keep track of the current index

    while (current) // Loop until we reach the end of the list
    {
        if (count == index)        // Check if we have reached the desired index
            return current->value; // Return the value at the current node
        count++;
        current = current->next; // Move to the next node
    }
    return -1; // Return -1 if the index is out of bounds
}

void linked_list::set_at(int index, int value)
{
    node *current = head; // Initialize a pointer to the head node
    int count = 0;

    while (current) // Loop until we reach the end of the list
    {
        if (count == index) // Check if we have reached the desired index
        {
            current->value = value; // Update the value at the current node
            return;
        }
        count++;                 // Increment the counter
        current = current->next; // Move to the next node
    }
}

void linked_list::insert_at(int index, int value)
{
    if (index == 0)
    {
        head = new node{value, head}; // Create a new node and set it as the new head
        return;
    }
    node *current = head;
    int count = 1;

    while (current && count < index) // Loop until we reach the end of the list
    {
        count++;                 // Increment the counter
        current = current->next; // Move to the next node
    }
    if (!current) // If the index is out of bounds, do nothing
    {
        return;
    }
    node *new_node = new node{value, current->next}; // Create a new node

    current->next = new_node;
}

void linked_list::delete_at(int index)
{
    if (!head) // If the list is empty, do nothing
    {
        return;
    }
    if (index == 0)
    {
        node *tmp = head;  // Temporary pointer to store the current head
        head = head->next; // Update the head pointer to the next node
        delete tmp;        // Delete the old head
        return;
    }
    node *current = head;
    int count = 0;

    while (current->next && count < index - 1)
    {
        count++;
        current = current->next;
    }
    if (!current->next)
    {
        return;
    }
    node *tmp = current->next;

    current->next = current->next->next;
    delete tmp;
}

void linked_list::insert_first(int value)
{
    insert_at(0, value); // Call the insert_at method with index 0
}

void linked_list::delete_first()
{
    delete_at(0); // Call the delete_at method with index 0
}

void linked_list::print_all()
{
    node *p = head; // Initialize a pointer to the head node
    int size = 0;   // Counter to keep track of the list's size

    std::cout << "All elements: "; // Print introductory text
    while (p)                      // Loop through the list to print all values
    {
        std::cout << p->value << " ";
        p = p->next;
        ++size;
    }
    std::cout << std::endl;
    std::cout << "Size: " << size << std::endl; // Print the size of the list
}