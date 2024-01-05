#ifndef directed_graph_hpp
#define directed_graph_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class directed_graph
{
private:
    int num_vertices;                                              // Total number of vertices in the graph.
    std::vector<std::vector<int>> adjacency_matrix;                // 2D vector representing the adjacency matrix of the graph.
    std::vector<std::vector<int>> adjacency_list;                  // 2D vector representing the adjacency list of the graph.
    bool is_valid_vertex(int v) const;                             // Checks if the given vertex 'v' is a valid index.
    void update_adjacency_matrix(const std::pair<int, int> &edge); // Updates the adjacency matrix when an edge is added.
    void update_adjacency_list(const std::pair<int, int> &edge);   // Updates the adjacency list when an edge is added.

public:
    directed_graph(int n, const std::vector<std::pair<int, int>> &edges); // Constructor to initialize the graph.
    const std::vector<std::vector<int>> &get_adjacency_matrix() const;    // Returns the adjacency matrix of the graph.
    const std::vector<std::vector<int>> &get_adjacency_list() const;      // Returns the adjacency list of the graph.
    void add_edge(int source, int destination);                           // Adds an edge from 'source' to 'destination'.
    void remove_edge(int source, int destination);                        // Removes the edge from 'source' to 'destination'.
    bool edge_exists(int source, int destination) const;                  // Checks if the edge from 'source' to 'destination' exists.
    std::vector<int> get_neighbors(int vertex) const;                     // Returns the neighbors of the given vertex.
};

#endif