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

### Greedy Coloring Algorithm

The `libgraph::greedy_coloring` function implements a greedy coloring algorithm. Given an input graph represented by an adjacency matrix, this algorithm assigns colors to vertices in such a way that no two adjacent vertices have the same color. The function returns a mapping of vertices to colors.

```cpp
std::unordered_map<uint32_t, uint32_t> greedy_coloring(const libgraph::adjacency_matrix& graph);
```

## Usage

To use the libgraph project, include the necessary header files in your code and link against the compiled object files.

Source 'export.sh' file to set necessary environment variable (LD_LIBRARY_PATH):
```cpp
source export.sh
```

### Make options

- **make all** - makes everything (libraries and tests).
- **make tests** - makes tests.
- **make libgraph** - makes libgraph only.
- **make libgcoloring** - makes libgcoloring (graph coloring library) only.
- **make clean** - removes redundant files/directories.

## Author

Abraham Gabrielyan, student at NUACA(National University of Architecture and Construction of Armenia), software engineer at AMD.

## Contacts
gabrielyanabraham@gmail.com
