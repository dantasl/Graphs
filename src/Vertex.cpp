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

bool Vertex::neighbor_same_color(int color, int source)
{
    for ( auto it = adjacent_vertices.begin(); it != adjacent_vertices.end(); ++it )
        if ( (*it)->colored && (*it)->identifier != source )
            if ( (*it)->vertex_color == color ) return true;
    return false;
}

void Vertex::update_neighbors_saturation_degree()
{
    // Iterates over the neighbors of given vertex
    for (auto it = adjacent_vertices.begin(); it != adjacent_vertices.end(); ++it)
    {
        if ( ! (*it)->neighbor_same_color(vertex_color, identifier) ) (*it)->saturation_degree += 1;
    }
}

void Vertex::color_vertex(std::set< int, std::greater<int> > &colors)
{
    // Get the color of all the neighbors into an auxiliary set
    std::set< int, std::greater<int> > aux;
    std::set< int, std::greater<int> > diff;
    for (auto it = this->adjacent_vertices.begin(); it != this->adjacent_vertices.end(); ++it)
        if ((*it)->colored) aux.insert( (*it)->vertex_color );
    
    // To find the color we can do: min(colors - aux)
    std::set_difference(
        colors.begin(), colors.end(),
        aux.begin(), aux.end(),
        std::inserter(diff, diff.end())
    );

    // If the difference of sets its not empty, we get the lesser color
    if (diff.size() > 0)
    {
        this->vertex_color = *diff.begin();
        return;
    }

    // Otherwise, we must add a new color and set this vertex to it
    colors.insert( *colors.end() + 1 );
    this->vertex_color = *colors.end();
}