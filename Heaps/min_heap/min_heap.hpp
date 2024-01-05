#ifndef min_heap_hpp
#define min_heap_hpp

#include <iostream>
#include <vector>

class min_heap
{
private:
    std::vector<int> heap;     // Vector to hold heap elements.
    void sift_up(int index);   // Bubbles up element at 'index' to its proper position.
    void sift_down(int index); // Bubbles down element at 'index' to its proper position.

public:
    min_heap();                                          // Default constructor.
    explicit min_heap(const std::vector<int> &elements); // Constructor to build heap from vector.
    min_heap(const min_heap &other);                     // Copy constructor.
    min_heap(min_heap &&other) noexcept;                 // Move constructor.
    ~min_heap();                                         // Destructor.
    min_heap &operator=(const min_heap &other);          // Copy assignment.
    min_heap &operator=(min_heap &&other) noexcept;      // Move assignment.
    void add(int new_value);                             // Inserts 'new_value' into the heap.
    int delete_root();                                   // Removes and returns the smallest element (root) from the heap.
    int get_min() const;                                 // Returns the smallest element (root) without removing.
    int size() const;                                    // Returns number of elements in heap.
    bool is_empty() const;                               // Returns true if heap is empty, false otherwise.
    bool contains(int value) const;                      // Checks if 'value' exists in heap.
    void clear();                                        // Clears the heap.
    void build_heap(const std::vector<int> &elements);   // Builds heap from a vector.
};

#endif