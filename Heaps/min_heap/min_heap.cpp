#include "min_heap.hpp"
#include <algorithm>
#include <stdexcept>

min_heap::min_heap() {} // Default constructor does nothing, as vector is default-initialized.

min_heap::min_heap(const std::vector<int> &elements) // Constructs heap from a vector.
{
    build_heap(elements); // Utilizes the build_heap function.
}

min_heap::min_heap(const min_heap &other) : heap(other.heap) {} // Copy constructor.

min_heap::min_heap(min_heap &&other) noexcept : heap(std::move(other.heap)) {} // Move constructor.

min_heap::~min_heap() {} // Destructor. No dynamic memory, so it does nothing.

min_heap &min_heap::operator=(const min_heap &other)
{
    if (this != &other) // Check for self-assignment.
    {
        heap = other.heap; // Copy other's heap to this heap.
    }
    return *this;
}

min_heap &min_heap::operator=(min_heap &&other) noexcept
{
    if (this != &other) // Check for self-assignment.
    {
        heap = std::move(other.heap); // Move other's heap to this heap.
    }
    return *this;
}

void min_heap::sift_up(int index)
{
    if (index <= 0 || index >= heap.size()) // If index is out of bounds, return.
    {
        return;
    }
    int parent_index = (index - 1) / 2; // Calculate parent's index.

    if (heap[index] < heap[parent_index]) // If element at index is smaller than parent, swap.
    {
        std::swap(heap[index], heap[parent_index]);
        sift_up(parent_index); // Recursive call to sift_up for parent.
    }
}

void min_heap::sift_down(int index)
{
    int left = index * 2 + 1;  // Calculate left child's index.
    int right = index * 2 + 2; // Calculate right child's index.
    int smallest = index;      // Initialize the smallest as the current index.

    if (left < heap.size() && heap[smallest] > heap[left]) // Compare with left child.
    {
        smallest = left;
    }
    if (right < heap.size() && heap[smallest] > heap[right]) // Compare with right child.
    {
        smallest = right;
    }
    if (smallest != index) // If smallest is not the current index, swap and sift down.
    {
        std::swap(heap[index], heap[smallest]);
        sift_down(smallest);
    }
}

void min_heap::add(int new_value)
{
    heap.push_back(new_value); // Add new_value to the end.
    sift_up(heap.size() - 1);  // Sift it up to its proper position.
}

int min_heap::delete_root()
{
    if (is_empty()) // If heap is empty, throw error.
    {
        throw std::runtime_error("Heap is empty. Cannot delete root.");
    }
    int ans = heap[0]; // Store the root value.

    heap[0] = heap.back(); // Replace root with the last element.
    heap.pop_back();       // Remove the last element.
    sift_down(0);          // Sift down the new root to its proper position.
    return ans;            // Return the original root value.
}

int min_heap::get_min() const // Public function to get the root without removing.
{
    if (is_empty())
    {
        throw std::runtime_error("Heap is empty. Cannot get minimum value.");
    }
    return heap[0]; // Return the root value.
}

int min_heap::size() const // Returns the number of elements in the heap.
{
    return heap.size();
}

bool min_heap::is_empty() const // Checks if the heap is empty.
{
    return heap.empty();
}

bool min_heap::contains(int value) const // Checks if the heap contains a value.

{
    return std::find(heap.begin(), heap.end(), value) != heap.end();
}

void min_heap::clear() // Clears the heap.
{
    heap.clear();
}

void min_heap::build_heap(const std::vector<int> &elements) // Builds heap from a vector.
{
    heap = elements;                         // Directly assign the elements to heap.
    int start_index = (heap.size() / 2) - 1; // Start from the last non-leaf node.

    for (int i = start_index; i >= 0; i--) // Traverse backwards and sift down each node.
    {
        sift_down(i);
    }
}