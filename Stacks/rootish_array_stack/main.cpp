#include "rootish_array_stack.hpp"

int main()
{
    rootish_array_stack test_stack;

    std::cout << "Test Case: Adding elements from 0 to 6" << std::endl;
    for (int i = 0; i <= 6; ++i)
    {
        test_stack.add(test_stack.size(), i);
        test_stack.print_all();
    }
    std::cout << std::endl;

    std::cout << "Test Case: add(3, 10)" << std::endl;
    test_stack.add(3, 10);
    test_stack.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: remove(3)" << std::endl;
    test_stack.remove(3);
    test_stack.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: Removing the first element" << std::endl;
    test_stack.remove(0);
    test_stack.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: Removing the last element" << std::endl;
    test_stack.remove(test_stack.size() - 1);
    test_stack.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: Removing the first element 10 times" << std::endl;
    for (int i = 0; i < 10 && test_stack.size() > 0; ++i)
    {
        test_stack.remove(0);
        test_stack.print_all();
    }
    return 0;
}