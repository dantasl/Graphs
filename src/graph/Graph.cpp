/**
 * @file        Graph.cpp
 * @author      Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author      Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief       This file implements the Graph class.
 * @version     0.1
 * @date        2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../../include/graph/Graph.h"

using namespace graphs;

Graph::Graph(std::vector<Edge*> edges, std::vector<Vertex*> vertices)
    : edges{edges}
    , vertices{vertices}
{
    // Initialize the vector of colors with the lesser color
    colors.insert(1);
}

Vertex* Graph::find_maximum_degree()
{
    // Takes the first element to initialize comparison
    auto aux = vertices.begin();

    // Iterates over the vector of vertices comparing the degrees
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it)
        if ((*it)->degree() > (*aux)->degree()) aux = it;
    
    return *aux;
}

Vertex* Graph::find_maximum_saturation_degree()
{
    // Finding maximum saturation degree
    int max_saturation_degree = 0;
    for (auto it = vertices.begin(); it != vertices.end(); ++it)
        if ( ((*it)->saturation_degree > max_saturation_degree) && (!(*it)->colored) )
            max_saturation_degree = (*it)->saturation_degree;            
    
    // Iterating over vertices with maximum saturation degree
    int degree = 0;
    Vertex* max_saturated = nullptr;
    for (auto it = vertices.begin(); it != vertices.end(); ++it)
        if ( ((*it)->saturation_degree == max_saturation_degree) && (!(*it)->colored) )
            if ( (*it)->degree() >= degree )
            {
                degree = (*it)->degree();
                max_saturated = *it;
            }

    return max_saturated;
}

bool Graph::is_colored()
{
    // It is necessary only one uncolored vertex for this method to return false.
    bool colored = true;
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it)
        if ( !(*it)->colored ) return false;
    return colored;
}

bool Graph::is_valid()
{
    // Iterates over the whole graph to check if two adjacent vertices have the same color
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it)
    {
        int this_color = (*it)->vertex_color;
        for (auto adj = (*it)->adjacent_vertices.begin();
             adj != (*it)->adjacent_vertices.end(); ++adj)
        {
            if (this_color == (*adj)->vertex_color) return false;
        }
    }
    return true;
}

int Graph::dsatur_chromatic() { return colors.size(); }

void Graph::print_colors()
{
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it)
        std::cout   << "* (ID " << (*it)->identifier
                    << ") - (SCHEDULE " << (*it)->schedule
                    << ") - (COLOR " << (*it)->vertex_color << ")" << std::endl;
}

std::string Graph::get_colored()
{
    std::string buffer;
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it)
        buffer +=   std::string("* (ID ") + std::to_string((*it)->identifier)
                    + ") - (SCHEDULE " + (*it)->schedule
                    + ") - (COLOR " + std::to_string((*it)->vertex_color) + ")\n";
    return buffer;  
}