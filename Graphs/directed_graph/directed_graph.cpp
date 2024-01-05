#include "directed_graph.hpp"

bool directed_graph::is_valid_vertex(int v) const
{
    return v >= 0 && v < num_vertices; // Vertex index should be non-negative and less than total vertices.
}

void directed_graph::update_adjacency_matrix(const std::pair<int, int> &edge)
{
    int source = edge.first;
    int destination = edge.second;

    if (adjacency_matrix[source][destination] == 1) // Check if the edge already exists.
    {
        throw std::runtime_error("Edge already exists");
    }
    adjacency_matrix[source][destination] = 1;
}

void directed_graph::update_adjacency_list(const std::pair<int, int> &edge)
{
    int source = edge.first;
    int destination = edge.second;

    adjacency_list[source].push_back(destination); // Add the destination to the adjacency list of the source vertex.
}

directed_graph::directed_graph(int n, const std::vector<std::pair<int, int>> &edges) : num_vertices(n) // Initialize total vertices.
{
    adjacency_matrix.assign(num_vertices, std::vector<int>(num_vertices, 0)); // Initialize the adjacency matrix.
    adjacency_list.assign(num_vertices, std::vector<int>());                  // Initialize the adjacency list.

    for (const auto &edge : edges) // Iterate over the edges.
    {
        if (!is_valid_vertex(edge.first) || !is_valid_vertex(edge.second)) // Check if the edge's vertices are valid indices.
        {
            throw std::out_of_range("Vertex index out of range");
        }
        update_adjacency_matrix(edge);
        update_adjacency_list(edge);
    }
}

const std::vector<std::vector<int>> &directed_graph::get_adjacency_matrix() const
{
    return adjacency_matrix; // Simply returns a reference to the adjacency matrix.
}

const std::vector<std::vector<int>> &directed_graph::get_adjacency_list() const
{
    return adjacency_list; // Simply returns a reference to the adjacency list.
}

void directed_graph::add_edge(int source, int destination)
{
    if (!is_valid_vertex(source) || !is_valid_vertex(destination)) // Check if the edge's vertices are valid indices.
    {
        throw std::out_of_range("Vertex index out of range");
    }
    update_adjacency_matrix({source, destination});
    update_adjacency_list({source, destination});
}

void directed_graph::remove_edge(int source, int destination)
{
    if (!is_valid_vertex(source) || !is_valid_vertex(destination)) // Check if the edge's vertices are valid indices.
    {
        throw std::out_of_range("Vertex index out of range");
    }
    if (adjacency_matrix[source][destination] == 0) // Check if the edge exists.
    {
        throw std::runtime_error("Edge does not exist");
    }
    adjacency_matrix[source][destination] = 0;                                                                                                          // Remove the edge from the adjacency matrix.
    adjacency_list[source].erase(std::remove(adjacency_list[source].begin(), adjacency_list[source].end(), destination), adjacency_list[source].end()); // Remove the destination from the adjacency list of the source vertex.
}

bool directed_graph::edge_exists(int source, int destination) const
{
    if (!is_valid_vertex(source) || !is_valid_vertex(destination)) // Check if the edge's vertices are valid indices.
    {
        throw std::out_of_range("Vertex index out of range");
    }
    return adjacency_matrix[source][destination] == 1;
}

std::vector<int> directed_graph::get_neighbors(int vertex) const
{
    if (!is_valid_vertex(vertex)) // Check if the vertex is a valid index.
    {
        throw std::out_of_range("Vertex index out of range");
    }
    return adjacency_list[vertex];
}