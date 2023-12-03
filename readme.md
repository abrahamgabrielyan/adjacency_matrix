# libgraph

## Overview

The `libgraph` project is a C++ library that implements two key components in graph theory: an adjacency matrix for graph representation and a greedy coloring algorithm. Below is an overview of these components.

### Adjacency Matrix

The `libgraph::adjacency_matrix` class provides a versatile implementation of an adjacency matrix, a fundamental data structure for representing graphs. The adjacency matrix efficiently captures the connections between vertices in a graph, making it suitable for various graph-related applications.

#### Class Members

- **Constructor:** `adjacency_matrix(const uint32_t total_vertices = 0)`
  Initializes an adjacency matrix with the given number of vertices.

- **Copy Constructor:** `adjacency_matrix(const adjacency_matrix&)`
  Creates a copy of an existing adjacency matrix.

- **Copy Assignment Operator:** `adjacency_matrix& operator=(const adjacency_matrix&)`
  Assigns the values of one adjacency matrix to another.

- **Move Constructor:** `adjacency_matrix(adjacency_matrix&&)`
  Moves the contents of one adjacency matrix to another.

- **Move Assignment Operator:** `adjacency_matrix& operator=(adjacency_matrix&&)`
  Moves the contents of one adjacency matrix to another.

- **Destructor:** `~adjacency_matrix()`
  Destroys the adjacency matrix.

- **Member Functions:**
  - `void add_vertex(const uint32_t total_vertices_to_add = 1) noexcept`
  - `void remove_vertex(const uint32_t vertex)`
  - `void add_edge(const uint32_t vertex_one, const uint32_t vertex_two)`
  - `void remove_edge(const uint32_t vertex_one, const uint32_t vertex_two)`
  - `std::vector<std::vector<bool>> get_matrix() const noexcept`
  - `uint32_t get_total_vertices() const noexcept`
  - `uint32_t get_total_edges() const noexcept`

## Technologies/libraries used

- **Ubuntu 23.10**

- **C++20**

## Author

Abraham Gabrielyan, student at NUACA(National University of Architecture and Construction of Armenia), software engineer at AMD.

## Contacts
gabrielyanabraham@gmail.com
