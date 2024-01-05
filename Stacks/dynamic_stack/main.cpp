#include "dynamic_stack.hpp"

int main()
{
    dynamic_stack test_stack;

    std::cout << "Test Case: push(i), i = {0 ... 6}" << std::endl;
    for (int i = 0; i <= 6; ++i)
    {
        test_stack.push(i);
        test_stack.print_all();
    }
    std::cout << std::endl;

    std::cout << "Test Case: pop()" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        test_stack.pop();
        test_stack.print_all();
    }
    std::cout << std::endl;

    std::cout << "Test Case: check top()" << std::endl;
    std::cout << "Top of the stack: " << test_stack.top() << std::endl;
    test_stack.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: pop() until empty" << std::endl;
    while (!test_stack.is_empty())
    {
        test_stack.pop();
        test_stack.print_all();
    }
    std::cout << std::endl;

    std::cout << "Test Case: trying pop() on an empty stack" << std::endl;
    test_stack.pop();
    std::cout << std::endl;

    std::cout << "Test Case: trying top() on an empty stack" << std::endl;
    std::cout << "Top of the stack: " << test_stack.top() << std::endl;

    return 0;
}