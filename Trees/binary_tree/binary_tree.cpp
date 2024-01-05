#include "binary_tree.hpp"

binary_tree::binary_tree_node::binary_tree_node(char k, int v) : key(k), value(v), height(0), num_nodes(1), left(nullptr), right(nullptr), parent(nullptr) {}

binary_tree::binary_tree() : root(nullptr) {}

binary_tree::~binary_tree()
{
    delete_tree(root);
}

binary_tree::binary_tree(const binary_tree &other) : root(copy_tree(other.root)) {}

binary_tree &binary_tree::operator=(const binary_tree &other)
{
    if (this == &other) // Self-assignment check.
    {
        return *this;
    }
    delete_tree(root);            // Delete the current tree's nodes.
    root = copy_tree(other.root); // Deep copy the other tree.
    return *this;                 // Return a reference to the current object for chaining.
}

binary_tree::binary_tree(binary_tree &&other) noexcept : root(other.root)
{
    other.root = nullptr; // Nullify the source tree's root pointer.
}

binary_tree &binary_tree::operator=(binary_tree &&other) noexcept
{
    if (this == &other) // Self-assignment check.
    {
        return *this;
    }
    delete_tree(root);    // Delete the current tree's nodes.
    root = other.root;    // Transfer ownership of the source tree's root node to the current tree.
    other.root = nullptr; // Nullify the source tree's root pointer.
    return *this;         // Return a reference to the current object for chaining.
}

void binary_tree::delete_tree(binary_tree_node *node)
{
    if (node == nullptr) // Base case: If node is null, do nothing.
    {
        return;
    }
    delete_tree(node->left);  // Recursively delete the left subtree.
    delete_tree(node->right); // Recursively delete the right subtree.
    delete node;              // Delete the current node.
}

binary_tree::binary_tree_node *binary_tree::copy_tree(const binary_tree_node *node)
{
    if (node == nullptr) // Base case: If node is null, return null.
    {
        return nullptr;
    }
    binary_tree_node *newNode = new binary_tree_node(node->key, node->value);

    newNode->left = copy_tree(node->left);   // Recursively copy the left subtree.
    newNode->right = copy_tree(node->right); // Recursively copy the right subtree.
    return newNode;                          // Return the new node.
}

binary_tree::binary_tree_node *binary_tree::build_from_vector(std::vector<std::pair<char, int>> &key_value_pairs, int left, int right)
{
    if (left > right) // Base case: If left index is greater than right index, return null.
    {
        return nullptr;
    }
    int mid = (left + right) / 2;                                                                           // Calculate the middle index.
    binary_tree_node *node = new binary_tree_node(key_value_pairs[mid].first, key_value_pairs[mid].second); // Create a new node with the middle key-value pair.

    node->left = build_from_vector(key_value_pairs, left, mid - 1); // Recursively create the left subtree using the left half of the current vector subset.
    if (node->left != nullptr)                                      // If a left child was created, set its parent pointer.
    {
        node->left->parent = node;
    }
    node->right = build_from_vector(key_value_pairs, mid + 1, right); // Recursively create the right subtree using the right half of the current vector subset.
    if (node->right != nullptr)                                       // If a right child was created, set its parent pointer.
    {
        node->right->parent = node;
    }
    return node;
}

void binary_tree::initialize_height_and_number_of_nodes(binary_tree_node *u)
{
    if (u == nullptr) // Base condition: If node is null, do nothing.
    {
        return;
    }
    int u_height = 0, u_num_nodes = 1;

    if (u->left != nullptr) // Process left child.
    {
        initialize_height_and_number_of_nodes(u->left); // Recurse on left child.
        u_height = u->left->height + 1;                 // Update height based on left child's height.
        u_num_nodes += u->left->num_nodes;              // Update node count based on left child's node count.
    }
    if (u->right != nullptr) // Process right child.
    {
        initialize_height_and_number_of_nodes(u->right);     // Recurse on right child.
        u_height = std::max(u_height, u->right->height + 1); // Update height based on right child's height, if it's greater.
        u_num_nodes += u->right->num_nodes;                  // Update node count based on right child's node count.
    }
    u->height = u_height;       // Update the node's height.
    u->num_nodes = u_num_nodes; // Update the node's node count.
}

void binary_tree::update_height_and_number_of_nodes(binary_tree_node *node)
{
    if (node == nullptr) // Base condition: If node is null, do nothing.
    {
        return;
    }
    int left_h = (node->left ? node->left->height + 1 : 0);    // Calculate the height of the left subtree.
    int right_h = (node->right ? node->right->height + 1 : 0); // Calculate the height of the right subtree.

    node->height = std::max(left_h, right_h);                 // Update the node's height.
    int left_n = (node->left ? node->left->num_nodes : 0);    // Calculate the number of nodes in the left subtree.
    int right_n = (node->right ? node->right->num_nodes : 0); // Calculate the number of nodes in the right subtree.

    node->num_nodes = left_n + right_n + 1;          // Update the node's node count.
    update_height_and_number_of_nodes(node->parent); // Recursively update the height and node count of the parent.
}

bool binary_tree::is_left(binary_tree_node *node)
{
    if (node->parent == nullptr) // Base condition: If node doesn't have a parent, it's the root.
    {
        return true;
    }
    return node->parent->left == node; // Return true if the node is the left child of its parent.
}

void binary_tree::connect_child_with_parent(binary_tree_node *child, binary_tree_node *parent, bool is_left)
{
    if (is_left) // If the child is a left child, set the parent's left pointer.
    {
        parent->left = child;
    }
    else // If the child is a right child, set the parent's right pointer.
    {
        parent->right = child;
    }
    if (child != nullptr) // If the child is not null, set its parent pointer.
    {
        child->parent = parent;
    }
}

binary_tree::binary_tree_node *&binary_tree::get_root()
{
    return root;
}

binary_tree::binary_tree_node *binary_tree::get_node(binary_tree_node *u, int rank)
{
    if (u == nullptr) // If the node is null, we've reached a leaf or an empty spot, so return null.
    {
        return nullptr;
    }
    int num_left = u->left ? u->left->num_nodes : 0; // Calculate the number of nodes in the left subtree.

    if (rank == num_left) // If the rank is equal to the number of nodes in the left subtree, the target node is the current node.
    {
        return u;
    }
    else if (rank < num_left) // If the rank is less than the number of nodes in the left subtree, the target node is in the left subtree.
    {
        return get_node(u->left, rank); // Recursively search in the left subtree.
    }
    else // If the rank is greater than the number of nodes in the left subtree, the target node is in the right subtree.
    {
        return get_node(u->right, rank - num_left - 1); // Recursively search in the right subtree after adjusting the rank.
    }
}

void binary_tree::add_node(binary_tree_node *u, int rank, char key, int value)
{
    binary_tree_node *current_ith_node = get_node(root, rank); // Get the node at the given rank.

    if (current_ith_node == nullptr) // If the node is null, we've reached a leaf or an empty spot, so return.
    {
        return;
    }
    binary_tree_node *node_to_add_node = new binary_tree_node(key, value); // Create a new node with the given key and value.
    binary_tree_node *current_left = current_ith_node->left;               // Get the current node's left child.

    if (current_left == nullptr)
    {
        current_ith_node->left = node_to_add_node;   // Set the new node as the left child.
        node_to_add_node->parent = current_ith_node; // Link the parent pointer of the new node.
    }
    else // If the current node has a left child, we need to find the rightmost node in the left subtree.
    {
        binary_tree_node *rightmost_node = current_left; // Start from the left child.

        while (rightmost_node->right != nullptr) // Traverse the right subtree until we reach a leaf node.
        {
            rightmost_node = rightmost_node->right;
        }
        rightmost_node->right = node_to_add_node;  // Set the new node as the right child of the rightmost node.
        node_to_add_node->parent = rightmost_node; // Link the parent pointer of the new node.
    }
    update_height_and_number_of_nodes(node_to_add_node->parent); // Update the height and node count of the parent.
}

binary_tree::binary_tree_node *binary_tree::delete_node(binary_tree_node *u, int rank)
{
    binary_tree_node *node_to_delete = get_node(root, rank); // Get the node at the given rank.

    if (node_to_delete == nullptr)
    {
        return root; // Node with the given rank was not found, return the root unchanged.
    }
    if (!node_to_delete->left && !node_to_delete->right) // Case 1: The node is a leaf.
    {
        if (node_to_delete->parent) // If the node is not the root, adjust the parent's child pointer.
        {
            if (is_left(node_to_delete)) // If the node is the left child, set the parent's left pointer to null.
            {
                node_to_delete->parent->left = NULL;
            }
            else // If the node is the right child, set the parent's right pointer to null.
            {
                node_to_delete->parent->right = NULL;
            }
        }
        delete node_to_delete;
    }
    else if (!node_to_delete->left || !node_to_delete->right) // Case 2: The node has one child.
    {
        binary_tree_node *child = node_to_delete->left ? node_to_delete->left : node_to_delete->right;

        if (node_to_delete->parent) // If the node is not the root, adjust the parent's child pointer.
        {
            if (is_left(node_to_delete)) // If the node is the left child, set the parent's left pointer to the child.
            {
                node_to_delete->parent->left = child;
            }
            else // If the node is the right child, set the parent's right pointer to the child.
            {
                node_to_delete->parent->right = child;
            }
        }
        child->parent = node_to_delete->parent;
        delete node_to_delete;
    }
    else // Case 3: The node has two children.
    {
        binary_tree_node *successor = node_to_delete->right; // Find the successor of the node.

        while (successor->left) // Traverse the left subtree of the node's right child.
        {
            successor = successor->left;
        }
        if (successor->parent != node_to_delete) // If the successor is not the node's right child, adjust the successor's parent's child pointer.
        {
            successor->parent->left = successor->right;
            if (successor->right)
            {
                successor->right->parent = successor->parent;
            }
            successor->right = node_to_delete->right;
            successor->right->parent = successor;
        }
        if (node_to_delete->parent) // If the node is not the root, adjust the parent's child pointer.
        {
            if (is_left(node_to_delete))
            {
                node_to_delete->parent->left = successor;
            }
            else
            {
                node_to_delete->parent->right = successor;
            }
        }
        successor->left = node_to_delete->left;     // Set the successor's left child to the node's left child.
        successor->left->parent = successor;        // Link the parent pointer of the successor's left child.
        successor->parent = node_to_delete->parent; // Link the parent pointer of the successor.
        delete node_to_delete;
    }
    return root; // Return the root, especially relevant if there were any changes to the root node.
}

void binary_tree::print_tree(binary_tree_node *node, const std::string &prefix, bool is_left, bool isRoot)
{
    if (!node) // If the node is null, return.
    {
        return;
    }
    if (isRoot) // If the node is the root, print_tree its key and add_nodeitional information.
    {
        std::cout << "─────"; // Indicates that it's a root node.
    }
    else
    {
        std::cout << prefix << (is_left ? "L├────" : "R└────"); // L for left child, R for right child.
    }
    std::cout << node->key << ", "
              << "N=" << node->num_nodes << std::endl;                            // Print the node's key and number of nodes.
    print_tree(node->left, prefix + (is_left ? " │   " : "    "), true, false);   // Recursively print_tree the left subtree.
    print_tree(node->right, prefix + (is_left ? " │   " : "    "), false, false); // Recursively print_tree the right subtree.
}

void binary_tree::in_order_traversal(binary_tree_node *node)
{
    if (!node) // Base case: If the node is null, return.
    {
        return;
    }
    in_order_traversal(node->left);  // First, traverse and process the left subtree.
    std::cout << node->key << " ";   // Process and print_tree the current node's key.
    in_order_traversal(node->right); // Then, traverse and process the right subtree.
}

binary_tree::binary_tree_node *binary_tree::dfs(binary_tree_node *node, char target)
{
    if (!node || node->key == target) // If the node is null or if the node's key matches the target, return the node.
    {
        return node;
    }
    binary_tree_node *leftSearch = dfs(node->left, target); // Recursively search the left subtree.

    if (leftSearch)
    {
        return leftSearch; // If found in the left subtree, return the node.
    }
    return dfs(node->right, target); // Otherwise, recursively search the right subtree.
}

binary_tree::binary_tree_node *binary_tree::bfs(binary_tree_node *node, char target)
{
    if (node == nullptr) // Base case: If the root node is null, the tree is empty and the search is over.
    {
        return nullptr;
    }
    std::queue<binary_tree_node *> open_queue; // A queue to manage nodes that need to be checked.

    open_queue.push(node);      // Start the search from the root node by pushing it into the queue.
    while (!open_queue.empty()) // Continue until all nodes are checked.
    {
        binary_tree_node *current_node = open_queue.front(); // Take the front node from the queue.

        open_queue.pop();                // Remove the just-taken node from the queue.
        if (current_node->key == target) // If the node's key matches the target, we've found our node.
        {
            return current_node;
        }
        if (current_node->left != nullptr)
        {
            open_queue.push(current_node->left); // If the node has a left child, enqueue it.
        }
        if (current_node->right != nullptr)
        {
            open_queue.push(current_node->right); // If the node has a right child, enqueue it.
        }
    }
    return nullptr; // If we've checked all nodes and haven't returned, then the target node isn't in the tree.
}

binary_tree::binary_tree_node *binary_tree::bfs_layer_by_layer(binary_tree_node *node, char target)
{
    if (node == nullptr) // Base case: If the root node is null, the tree is empty.
    {
        return nullptr;
    }
    std::queue<binary_tree_node *> current_layer, next_layer; // Two queues: one for the current layer and one for the next layer of nodes.

    current_layer.push(node);      // Start with the root node in the current layer.
    while (!current_layer.empty()) // Continue while there are nodes in the current layer.
    {
        binary_tree_node *current_node = current_layer.front(); // Take the front node from the current layer.

        current_layer.pop();             // Remove the just-taken node from the queue.
        if (current_node->key == target) // If the node's key matches the target, we've found our node.
        {
            return current_node;
        }
        if (current_node->left != nullptr)
        {
            next_layer.push(current_node->left); // If the node has a left child, enqueue it.
        }
        if (current_node->right != nullptr)
        {
            next_layer.push(current_node->right); // If the node has a right child, enqueue it.
        }
        if (current_layer.empty()) // When the current layer is empty, it means we've finished that layer.
        {
            std::swap(current_layer, next_layer); // Move to the next layer by swapping the two queues.
        }
    }
    return nullptr; // If we've checked all nodes and haven't returned, then the target node isn't in the tree.
}