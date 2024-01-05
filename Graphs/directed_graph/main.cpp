#include "directed_graph.hpp"

int main()
{
    try
    {
        std::vector<std::pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}};
        directed_graph graph(4, edges);

        // Display the initial state of the graph
        std::cout << "Initial Graph:\n";

        // Display the adjacency matrix
        std::cout << "Adjacency Matrix:\n";
        const auto &matrix = graph.get_adjacency_matrix();
        for (const auto &row : matrix)
        {
            for (int val : row)
            {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }

        // Display the adjacency list
        std::cout << "\nAdjacency List:\n";
        const auto &list = graph.get_adjacency_list();
        for (int i = 0; i < list.size(); ++i)
        {
            std::cout << i << ": ";
            for (int dest : list[i])
            {
                std::cout << dest << " ";
            }
            std::cout << "\n";
        }

        // Test adding an edge
        std::cout << "\nAdding edge from vertex 2 to vertex 0...\n";
        graph.add_edge(2, 0);

        // Test checking existence of an edge
        std::cout << "Does edge from vertex 2 to vertex 0 exist? " << (graph.edge_exists(2, 0) ? "Yes" : "No") << "\n";

        // Test getting neighbors
        std::cout << "Neighbors of vertex 2: ";
        for (int v : graph.get_neighbors(2))
        {
            std::cout << v << " ";
        }
        std::cout << "\n";

        // Test removing an edge
        std::cout << "Removing edge from vertex 2 to vertex 0...\n";
        graph.remove_edge(2, 0);

        // Test error handling with invalid operations
        std::cout << "\nAttempting to add edge with invalid vertex...\n";
        graph.add_edge(4, 5); // This should throw an exception

        std::cout << "\nAttempting to remove non-existent edge...\n";
        graph.remove_edge(1, 3); // This should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}