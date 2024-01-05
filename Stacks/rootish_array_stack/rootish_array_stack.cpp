#include "rootish_array_stack.hpp"

int rootish_array_stack::block_size(int b) const
{
    return b + 2;
}

int rootish_array_stack::block_number(int i) const
{
    double formula = (-3 + std::sqrt(9 + 8 * i)) / 2; // Derived formula to find the block number.

    return static_cast<int>(formula);
}

void rootish_array_stack::grow()
{
    blocks[num_blocks] = new int[block_size(num_blocks)]; // Allocate a new block of appropriate size.
    num_blocks++;                                         // Increment the number of blocks.
}

void rootish_array_stack::shrink()
{
    num_blocks--;                // Decrement the number of blocks.
    delete[] blocks[num_blocks]; // Deallocate the last block.
}

rootish_array_stack::rootish_array_stack() : blocks(new int *[100]()) {}

rootish_array_stack::~rootish_array_stack()
{
    for (int i = 0; i < num_blocks; i++) // Iterate over all allocated blocks.
    {
        delete[] blocks[i]; // Deallocate each block.
    }
    delete[] blocks; // Deallocate the array of block pointers.
}

int rootish_array_stack::size() const
{
    return num_elements;
}

int rootish_array_stack::get(int i) const
{
    int b = block_number(i);     // Find the block number for element 'i'.
    int j = i - b * (b + 1) / 2; // Compute the index within the block.

    return blocks[b][j];
}

int rootish_array_stack::set(int i, int x)
{
    int b = block_number(i);     // Find the block number for element 'i'.
    int j = i - b * (b + 1) / 2; // Compute the index within the block.
    int y = blocks[b][j];        // Get the current value.

    blocks[b][j] = x; // Update the value.
    return y;         // Return the old value.
}

void rootish_array_stack::add(int i, int x)
{
    int r = block_number(num_elements); // Find the block number for the last element.

    if (r == num_blocks)
    {
        grow(); // If required, grow the number of blocks.
    }
    num_elements++;                            // Increment the element count.
    for (int j = num_elements - 1; j > i; j--) // Shift subsequent elements right.
    {
        set(j, get(j - 1));
    }
    set(i, x); // Set the element at position 'i'.
}

void rootish_array_stack::remove(int i)
{
    for (int j = i; j < num_elements - 1; j++) // Shift subsequent elements left.
    {
        set(j, get(j + 1));
    }
    num_elements--;                     // Decrement the element count.
    int r = block_number(num_elements); // Get the block number for the last element.

    if ((r - 2) * (r - 1) / 2 <= num_elements) // If the number of elements is too small, shrink the number of blocks.
    {
        shrink();
    }
}

void rootish_array_stack::print_all() const
{
    for (int i = 0; i < num_elements; i++) // Iterate over all elements.
    {
        std::cout << get(i) << " "; // Print each element.
    }
    std::cout << "\nSize: " << num_elements << std::endl; // Print the size of the stack.
}