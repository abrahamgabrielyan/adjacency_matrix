// File: adjacency_matrix.cpp
// Description: This file is part of libgraph project, distributed under the terms
// of the GNU General Public License version 3.0.
// Author: Abraham Gabrielyan

//Includes from this project
#include "adjacency_matrix.hpp"

//Includes from standard libraries

libgraph::adjacency_matrix::adjacency_matrix(const uint32_t total_vertices) : m_total_vertices(total_vertices),
									      m_total_edges(0),
							                      m_matrix(total_vertices)
{
	//Resize and default initialize each row of matrix.
	for(auto& vec : m_matrix)
	{
		vec.resize(total_vertices, false);
	}
}

libgraph::adjacency_matrix::adjacency_matrix(const libgraph::adjacency_matrix& other) : m_total_vertices(other.m_total_vertices),
											m_total_edges(other.m_total_edges),
											m_matrix(other.m_matrix)
{
}

libgraph::adjacency_matrix& libgraph::adjacency_matrix::operator=(const libgraph::adjacency_matrix& other)
{
	//Not checking for "this != &other". Most probably that case won't occur.
	m_matrix = other.m_matrix;
	m_total_vertices = other.m_total_vertices;
	m_total_edges = other.m_total_edges;
	return *this;
}

libgraph::adjacency_matrix::adjacency_matrix(libgraph::adjacency_matrix&& other) : m_total_vertices(other.m_total_vertices),
										   m_total_edges(other.m_total_edges),
										   m_matrix(other.m_matrix)
{
	other.m_total_vertices = 0;
	other.m_total_edges = 0;
	other.m_matrix.clear();
	other.m_matrix.shrink_to_fit();
}

libgraph::adjacency_matrix& libgraph::adjacency_matrix::operator=(libgraph::adjacency_matrix&& other)
{
	m_matrix = other.m_matrix;
	m_total_vertices = other.m_total_vertices;
	m_total_edges = other.m_total_vertices;
	other.m_total_vertices = 0;
	other.m_total_edges = 0;
	other.m_matrix.clear();
	other.m_matrix.shrink_to_fit();
	return *this;
}

libgraph::adjacency_matrix::~adjacency_matrix()
{
}

void libgraph::adjacency_matrix::add_vertex(const uint32_t total_vertices_to_add) noexcept
{
	m_total_vertices += total_vertices_to_add;
	m_matrix.resize(m_total_vertices);			
	for(auto& vec : m_matrix)
	{
		vec.resize(m_total_vertices, false);
	}
}

void libgraph::adjacency_matrix::remove_vertex(const uint32_t vertex)
{
	if(vertex > m_total_vertices)
	{
		throw std::logic_error("ERROR: Vertex does not exist and can't be removed.");
	}
	m_matrix.erase(m_matrix.begin() + vertex);
	for(auto& vec : m_matrix)
	{
		vec.erase(vec.begin() + vertex);
	}
	--m_total_vertices;
}

void libgraph::adjacency_matrix::add_edge(const uint32_t vertex_one, const uint32_t vertex_two)
{
	if(vertex_one >= m_total_vertices or vertex_two >= m_total_vertices)
	{
		throw std::logic_error("ERROR: Vertices not found, can't create an edge.");
	}
	if(vertex_one == vertex_two)
	{
		throw std::logic_error("ERROR: Can't create a loop in a simple graph.");
	}
	m_matrix[vertex_one][vertex_two] = true;
	m_matrix[vertex_two][vertex_one] = true;
	++m_total_edges;
}

void libgraph::adjacency_matrix::remove_edge(const uint32_t vertex_one, const uint32_t vertex_two)
{
	if(vertex_one >= m_total_vertices or vertex_two >= m_total_vertices)
	{
		throw std::logic_error("ERROR: Vertices not found, can't remove an edge.");
	}
	if(vertex_one == vertex_two)
	{
		throw std::logic_error("ERROR: Can't remove a loop. There aren't loops in a simple graph.");
	}
	m_matrix[vertex_one][vertex_two] = false;
	m_matrix[vertex_two][vertex_one] = false;
}

std::vector<std::vector<bool>> libgraph::adjacency_matrix::get_matrix() const noexcept
{
	return m_matrix;
}

uint32_t libgraph::adjacency_matrix::get_total_vertices() const noexcept
{
	return m_total_vertices;
}

uint32_t libgraph::adjacency_matrix::get_total_edges() const noexcept
{
	return m_total_edges;
}
