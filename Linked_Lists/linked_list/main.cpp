#include "linked_list.hpp"

int main()
{
    linked_list list(1);

    std::cout << "Test Case: insert_first(i), i = {0 ... 6}" << std::endl;
    for (int i = 0; i <= 6; ++i)
    {
        list.insert_first(i);
        list.print_all();
    }
    std::cout << std::endl;

    std::cout << "Test Case: insert_at(3, 10)" << std::endl;
    list.insert_at(3, 10);
    list.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_at(3)" << std::endl;
    list.delete_at(3);
    list.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_first()" << std::endl;
    list.delete_first();
    list.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_first(i), i = {0 ... 9}" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        list.delete_first();
        list.print_all();
    }
    return 0;
}