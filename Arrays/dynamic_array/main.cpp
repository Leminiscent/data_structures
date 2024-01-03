#include "dynamic_array.hpp"

int main()
{
    dynamic_array test_array(0);

    std::cout << "Test Case: insert_last(i), i = {0 ... 6}" << std::endl;
    for (int i = 0; i <= 6; ++i)
    {
        test_array.insert_last(i);
        test_array.print_all();
    }
    std::cout << std::endl;

    std::cout << "Test Case: insert_at(3, 10)" << std::endl;
    test_array.insert_at(3, 10);
    test_array.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_at(3)" << std::endl;
    test_array.delete_at(3);
    test_array.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_first()" << std::endl;
    test_array.delete_first();
    test_array.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_last()" << std::endl;
    test_array.delete_last();
    test_array.print_all();
    std::cout << std::endl;

    std::cout << "Test Case: delete_first(i), i = {0 ... 9}" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        test_array.delete_first();
        test_array.print_all();
    }
    return 0;
}