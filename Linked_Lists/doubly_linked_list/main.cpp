#include "doubly_linked_list.hpp"

int main()
{
    doubly_linked_list test_list(1);

    std::cout << "Test Case: insert_first(i), i = {0 ... 6}" << std::endl;
    for (int i = 0; i <= 6; ++i)
    {
        test_list.insert_first(i);
        test_list.print_all();
    }
    std::cout << std::endl;

    std::cout << "Test Case: insert_last(i), i = {20 ... 25}" << std::endl;
    for (int i = 20; i <= 25; ++i)
    {
        test_list.insert_last(i);
        test_list.print_all();
    }
    std::cout << std::endl;

    std::cout << "Test Case: insert_at(3, 10)" << std::endl;
    test_list.insert_at(3, 10);
    test_list.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_at(3)" << std::endl;
    test_list.delete_at(3);
    test_list.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_first()" << std::endl;
    test_list.delete_first();
    test_list.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_last()" << std::endl;
    test_list.delete_last();
    test_list.print_all();

    return 0;
}