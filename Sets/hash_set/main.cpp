#include "hash_set.hpp"

int main()
{
    hash_set<int> set;

    set.insert(5);
    set.insert(10);
    set.insert(15);

    std::cout << "Contains 5? " << (set.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 20? " << (set.contains(20) ? "Yes" : "No") << std::endl;

    set.remove(5);
    std::cout << "Contains 5? " << (set.contains(5) ? "Yes" : "No") << std::endl;

    return 0;
}