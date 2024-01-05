#include "linked_list_queue.hpp"

int main()
{
    linked_list_queue test_queue;

    std::cout << "Test Case: enqueue(i), i = {0 ... 6}" << std::endl;
    for (int i = 0; i <= 6; ++i)
    {
        test_queue.enqueue(i);
        test_queue.print_queue();
    }
    std::cout << std::endl;

    std::cout << "Test Case: peek()" << std::endl;
    std::cout << "Front of the queue: " << test_queue.peek() << std::endl;
    std::cout << std::endl;

    std::cout << "Test Case: dequeue()" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Dequeued value: " << test_queue.dequeue() << std::endl;
        test_queue.print_queue();
    }
    std::cout << std::endl;

    std::cout << "Test Case: is_empty()" << std::endl;
    std::cout << "Is the queue empty? " << (test_queue.is_empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    std::cout << "Emptying the queue..." << std::endl;
    while (!test_queue.is_empty())
    {
        std::cout << "Dequeued value: " << test_queue.dequeue() << std::endl;
        test_queue.print_queue();
    }
    std::cout << std::endl;

    std::cout << "Test Case: is_empty() after emptying the queue" << std::endl;
    std::cout << "Is the queue empty? " << (test_queue.is_empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    return 0;
}