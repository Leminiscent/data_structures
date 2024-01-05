#include "binary_tree.hpp"

int main()
{
    std::cout << "Test Case 1: Build Tree from Sorted Vector" << std::endl;
    std::vector<std::pair<char, int>> sorted_vector = {{'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 5}, {'F', 6}, {'G', 7}};
    binary_tree tree;

    tree.get_root() = tree.build_from_vector(sorted_vector, 0, sorted_vector.size() - 1);
    tree.print_tree(tree.get_root());
    std::cout << std::endl;

    std::cout << "Test Case 2: add_node Node" << std::endl;
    tree.add_node(tree.get_root(), 3, 'H', 8);
    tree.print_tree(tree.get_root());
    std::cout << std::endl;

    std::cout << "Test Case 3: delete_node Node" << std::endl;
    tree.delete_node(tree.get_root(), 3);
    tree.print_tree(tree.get_root());
    std::cout << std::endl;

    std::cout << "Test Case 4: Depth-First Search" << std::endl;
    auto found_node = tree.dfs(tree.get_root(), 'C');
    if (found_node)
    {
        std::cout << "Found Node with Key: " << found_node->key << ", Value: " << found_node->value << std::endl;
    }
    else
    {
        std::cout << "Node not found" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Test Case 5: Breadth-First Search" << std::endl;
    found_node = tree.bfs(tree.get_root(), 'E');
    if (found_node)
    {
        std::cout << "Found Node with Key: " << found_node->key << ", Value: " << found_node->value << std::endl;
    }
    else
    {
        std::cout << "Node not found" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Test Case 6: In-Order Traversal" << std::endl;
    tree.in_order_traversal(tree.get_root());
    std::cout << std::endl;

    return 0;
}