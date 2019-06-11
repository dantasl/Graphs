/**
 * @file        Vertex.cpp
 * @author      Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author      Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief       This file implements the Vertex class.
 * @version     0.1
 * @date        2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/Vertex.h"

using namespace graphs;

Vertex::Vertex(){/* empty */}

Vertex::Vertex(int identifier)
    : identifier{identifier}
    , adjacent_vertices{std::vector<Vertex*>()}
    {/* empty */}

void Vertex::add_adjacent_vertex (Vertex *vertex)
{
    // Adding the vertices to the adjacent list
    this->adjacent_vertices.push_back(vertex);
    vertex->adjacent_vertices.push_back(this);

    // Incrementing the vertices degree
    this->degree++;
    vertex->degree++;
}

void Vertex::remove_adjacent_vertex (int identifier)
{
    // If the list of adjacent vertices is empty, there is nothing to erase
    if (this->adjacent_vertices.empty()) return;

    // Now we must iterate over the adjacent vertices searching the one to erase
    for (auto v = this->adjacent_vertices.begin(); v != this->adjacent_vertices.end(); ++v)
        if ((*v)->identifier == identifier)
        {
            this->adjacent_vertices.erase(v, v + 1);
            this->degree--;
            break;
        }
}

bool Vertex::is_adjacent (Vertex &vertex)
{
    // If the list of adjacent vertices is empty, there are no neighbors
    if (this->adjacent_vertices.empty()) return false;
    
    // Iterating over the adjacent vertices.
    for (auto v = this->adjacent_vertices.begin(); v != this->adjacent_vertices.end(); ++v)
        if (**v == vertex) return true;
    
    return false;
}

void Vertex::update_neighbors_saturation_degree()
{
    // Iterates over the neighbors of given vertex and update their saturation degree
    for (auto it = this->adjacent_vertices.begin(); it != this->adjacent_vertices.end(); ++it)
        (*it)->saturation_degree ++;
}

void Vertex::color_vertex()
{
    
}