#include "array_deque.hpp"

int main()
{
    array_deque<int> test_deque(0);

    std::cout << "Test Case: push_back(i), i = {0 ... 6}" << std::endl;
    for (int i = 0; i <= 6; ++i)
    {
        test_deque.push_back(i);
        test_deque.print_deque();
    }
    std::cout << std::endl;

    std::cout << "Test Case: push_front(10)" << std::endl;
    test_deque.push_front(10);
    test_deque.print_deque();
    std::cout << std::endl;

    std::cout << "Test Case: pop_back()" << std::endl;
    test_deque.pop_back();
    test_deque.print_deque();
    std::cout << std::endl;

    std::cout << "Test Case: pop_front()" << std::endl;
    test_deque.pop_front();
    test_deque.print_deque();
    std::cout << std::endl;

    std::cout << "Test Case: pop_back() until deque is empty" << std::endl;
    while (!test_deque.is_empty())
    {
        test_deque.pop_back();
        test_deque.print_deque();
    }

    return 0;
}