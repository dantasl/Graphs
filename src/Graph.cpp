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

#include "../include/Graph.h"

using namespace graphs;

Graph::Graph(std::vector<Edge*> edges, std::vector<Vertex*> vertices)
    : edges{edges}
    , vertices{vertices}
{/* empty */}

Vertex* Graph::find_maximum_degree()
{
    // Takes the first element to initialize comparison
    auto aux = vertices.begin();

    // Iterates over the vector of vertices comparing the degrees
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it)
        if ((*it)->degree > (*aux)->degree) aux = it;
    
    return *aux;
}

Vertex* Graph::find_maximum_saturation_degree()
{
    // This method will only consider the vertices that are uncolored
    auto aux = vertices.begin();
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it)
        if ( ( (*it)->saturation_degree > (*aux)->saturation_degree ) && !(*it)->colored )
            aux = it;

    return *aux;
}

bool Graph::is_colored()
{
    // It is necessary only one uncolored vertex for this method to return false.
    bool colored = true;
    for (auto it = this->vertices.begin(); it != this->vertices.end(); ++it)
        if ( !(*it)->colored ) return false;
    return colored;
}