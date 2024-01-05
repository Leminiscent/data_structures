#include "min_heap.hpp"

int main()
{
    std::vector<int> elements = {16, 7, 42, 14, 20, 0, 5, 9, 29, 11, 25, 10};

    min_heap heap(elements);
    std::cout << "Initial Heap Size: " << heap.size() << std::endl;

    std::cout << "Minimum value without deleting: " << heap.get_min() << std::endl;

    heap.add(3);
    heap.add(18);
    heap.add(-2);
    std::cout << "Heap Size after adding 3 more elements: " << heap.size() << std::endl;
    std::cout << "New Minimum after additions: " << heap.get_min() << std::endl;

    std::cout << "Does the heap contain 5? " << (heap.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Does the heap contain 100? " << (heap.contains(100) ? "Yes" : "No") << std::endl;

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Deleted root: " << heap.delete_root() << std::endl;
    }

    std::cout << "Heap Size after deleting 5 elements: " << heap.size() << std::endl;

    heap.clear();
    std::cout << "Heap Size after clearing: " << heap.size() << std::endl;

    std::cout << "Is the heap empty? " << (heap.is_empty() ? "Yes" : "No") << std::endl;

    try
    {
        std::cout << heap.get_min() << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}