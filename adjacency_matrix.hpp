// File: adjacency_matrix.hpp
// Description: This file is part of libgraph project, distributed under the terms
// of the GNU General Public License version 3.0.
// Author: Abraham Gabrielyan

#pragma once

//Includes from this project

//Includes from standard libraries
#include <iostream>
#include <forward_list>
#include <algorithm>
#include <cstdint>
#include <vector>

namespace libgraph
{
	class adjacency_matrix;
}

class libgraph::adjacency_matrix
{
public:
	//User-defined constructor.
	adjacency_matrix(const uint32_t total_vertices = 0);

	//Copy constructor.
	adjacency_matrix(const adjacency_matrix&);

	//Copy assignment operator.
	adjacency_matrix& operator=(const adjacency_matrix&);

	//Move constructor.
	adjacency_matrix(adjacency_matrix&&);

	//Move assignment operator.
	adjacency_matrix& operator=(adjacency_matrix&&);

	//Destructor.
	~adjacency_matrix();

	/*@brief Adds vertices(default - 1 vertex)
	 */
	void add_vertex(const uint32_t total_vertices_to_add = 1) noexcept;

	/*@brief Removes vertex of given index.
	 * Note that each vertex ID is being decremented after this operation.
	 */
	void remove_vertex(const uint32_t vertex);
	
	/*@brief Adds an edge between given vertices.
	 * Note that each vertex ID can be incremented after this operation.
	 */
	void add_edge(const uint32_t vertex_one, const uint32_t vertex_two);

	/*@brief Removes an edge between given vertices.
	 */
	void remove_edge(const uint32_t vertex_one, const uint32_t vertex_two);

	/*@brief Returns a copy of adjacency matrix.
	 */
	std::vector<std::vector<bool>> get_matrix() const noexcept;

	/*@brief Returns vertices count.
	 */
    uint32_t get_total_vertices() const noexcept;

	/*@brief Returns edges count.
     */
	uint32_t get_total_edges() const noexcept;

private:
	uint32_t m_total_vertices;
	uint32_t m_total_edges;
	std::vector<std::vector<bool>> m_matrix;
};
