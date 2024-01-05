#include "doubly_linked_list.hpp"

doubly_linked_list::doubly_linked_list(int value)
{
    head = new node{value, nullptr, nullptr}; // Create a new node with the given value.
    tail = head;                              // Set the tail to the head.
}

doubly_linked_list::~doubly_linked_list()
{
    while (head) // Traverse the list and delete each node.
    {
        node *tmp = head;

        head = head->next;
        delete tmp;
    }
}

int doubly_linked_list::get_at(int index)
{
    node *current = head; // Start traversal from the head.
    int count = 0;        // Counter to track the current position.

    while (current) // Traverse the list until the desired index or the end.
    {
        if (count == index)
        {
            return current->value; // Return the value if the desired index is reached.
        }
        count++;
        current = current->next;
    }
    return -1; // Return -1 if the index is out of range.
}

void doubly_linked_list::set_at(int index, int value)
{
    node *current = head;
    int count = 0;

    while (current)
    {
        if (count == index)
        {
            current->value = value; // Update the value if the desired index is reached.
            return;
        }
        count++;
        current = current->next;
    }
}

void doubly_linked_list::insert_at(int index, int value)
{
    if (index == 0)
    {
        insert_first(value); // Use the insert_first method if index is 0.
        return;
    }
    node *current = head;
    int count = 1;

    while (current && count < index)
    {
        count++;
        current = current->next;
    }
    if (!current)
    {
        return; // Exit if the index is out of range.
    }
    node *new_node = new node{value, current->next, current}; // Create a new node with the given value.

    current->next->prev = new_node;
    current->next = new_node;
}

void doubly_linked_list::delete_at(int index)
{
    if (!head)
    {
        return; // If the list is empty, exit.
    }
    if (index == 0)
    {
        delete_first(); // Use the delete_first method if index is 0.
        return;
    }
    node *current = head;
    int count = 0;

    while (current->next && count < index) // Traverse the list until the desired index or the end.
    {
        count++;
        current = current->next;
    }
    if (!current)
    {
        return; // Exit if the index is out of range.
    }
    node *tmp = current;

    if (current->prev) // Update the previous and next pointers of the surrounding nodes.
    {
        current->prev->next = current->next;
    }
    if (current->next)
    {
        current->next->prev = current->prev;
    }
    delete tmp; // Release memory.
}

void doubly_linked_list::insert_first(int value)
{
    node *new_node = new node{value, head, nullptr}; // Create a new node with the given value.

    if (head) // If the list is not empty, update the previous pointer of the current head.
    {
        head->prev = new_node;
    }
    head = new_node; // Update the head pointer.
    if (!tail)       // If the list was empty, also update the tail pointer.
    {
        tail = head;
    }
}

void doubly_linked_list::delete_first()
{
    if (!head)
    {
        return; // If the list is empty, exit.
    }
    node *tmp = head; // Temporarily store the head node.

    if (head->next) // If there's a node after the head, update its previous pointer.
    {
        head->next->prev = nullptr;
    }
    else
    {
        tail = nullptr; // If head was the only node, also set tail to nullptr.
    }
    head = head->next; // Move the head pointer to the next node.
    delete tmp;        // Delete the old head node.
}

void doubly_linked_list::insert_last(int value)
{
    if (!tail) // If the list is empty, use the insert_first method.
    {
        insert_first(value);
        return;
    }
    node *new_node = new node{value, nullptr, tail}; // Create a new node with the given value.

    tail->next = new_node; // Update the next pointer of the current tail.
    tail = new_node;       // Update the tail pointer.
}

void doubly_linked_list::delete_last()
{
    if (!tail)
    {
        return; // If the list is empty, exit.
    }
    node *tmp = tail; // Temporarily store the tail node.

    if (tail->prev) // If there's a node before the tail, update its next pointer.
    {
        tail->prev->next = nullptr;
    }
    else
    {
        head = nullptr; // If tail was the only node, also set head to nullptr.
    }
    tail = tail->prev; // Move the tail pointer to the previous node.
    delete tmp;        // Delete the old tail node.
}

void doubly_linked_list::print_all()
{
    node *p = head; // Start from the head of the list.
    int size = 0;   // Counter to keep track of list size.

    std::cout << "All elements: ";
    while (p) // Traverse the list until the end.
    {
        std::cout << p->value << " ";
        p = p->next;
        ++size; // Increment the size for each node.
    }
    std::cout << std::endl;
    std::cout << "Size: " << size << std::endl; // Print the total size.
}