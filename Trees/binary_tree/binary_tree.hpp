#ifndef binary_tree_hpp
#define binary_tree_hpp

#include <iostream>
#include <vector>
#include <queue>

class binary_tree
{
private:
    struct binary_tree_node
    {
        char key;                              // Key to identify a node.
        int value;                             // Value associated with the key.
        int height;                            // Height of the node.
        int num_nodes;                         // Number of nodes in the subtree rooted at this node.
        binary_tree_node *left;                // Pointer to left child node.
        binary_tree_node *right;               // Pointer to right child node.
        binary_tree_node *parent;              // Pointer to parent node.
        binary_tree_node(char key, int value); // Constructor for the node structure.
    };
    binary_tree_node *root;                                                                                // Pointer to the root node of the binary tree.
    bool use_successor = true;                                                                             // Flag for deletion operation, by default using the successor.
    void delete_tree(binary_tree_node *node);                                                              // Recursive function to delete the tree.
    binary_tree_node *copy_tree(const binary_tree_node *node);                                             // Recursive function to copy the tree.
    void initialize_height_and_number_of_nodes(binary_tree_node *u);                                       // Function to initialize height and num_nodes attributes.
    void update_height_and_number_of_nodes(binary_tree_node *node);                                        // Function to update height and num_nodes attributes after tree modifications.
    bool is_left(binary_tree_node *node);                                                                  // Function to check if a node is the left child of its parent.
    void connect_child_with_parent(binary_tree_node *child, binary_tree_node *grand_parent, bool is_left); // Connects child to its parent.

public:
    binary_tree();                                                                                                      // Default constructor.
    ~binary_tree();                                                                                                     // Destructor to deallocate memory.
    binary_tree(const binary_tree &other);                                                                              // Copy constructor.
    binary_tree &operator=(const binary_tree &other);                                                                   // Copy assignment operator.
    binary_tree(binary_tree &&other) noexcept;                                                                          // Move constructor.
    binary_tree &operator=(binary_tree &&other) noexcept;                                                               // Move assignment operator.
    binary_tree_node *build_from_vector(std::vector<std::pair<char, int>> &key_value_pairs, int left, int right);       // Constructs tree from a sorted vector.
    int get_number_of_nodes(binary_tree_node *u);                                                                       // Returns the number of nodes in the subtree rooted at u.
    int get_height(binary_tree_node *u);                                                                                // Returns the height of node u.
    binary_tree_node *&get_root();                                                                                      // Returns the root node of the tree
    binary_tree_node *get_node(binary_tree_node *u, int rank);                                                          // Returns the node at a specific rank.
    void add_node(binary_tree_node *u, int rank, char key, int value);                                                  // Adds a node to the tree at a specific rank.
    binary_tree_node *delete_node(binary_tree_node *u, int rank);                                                       // Deletes a node from the tree at a specific rank.
    void print_tree(binary_tree_node *node, const std::string &prefix = "", bool is_left = false, bool is_root = true); // Prints the tree in a visual format.
    void in_order_traversal(binary_tree_node *node);                                                                    // Performs in-order traversal of the tree.
    binary_tree_node *dfs(binary_tree_node *node, char target);                                                         // Depth-first search for a target key.
    binary_tree_node *bfs(binary_tree_node *node, char target);                                                         // Breadth-first search for a target key.
    binary_tree_node *bfs_layer_by_layer(binary_tree_node *node, char target);                                          // Layer-by-layer BFS for a target key.
};

#endif