/**
 * @file        DSATUR.h
 * @author      Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author      Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief       This file defines the DSATUR algorithm implementation.
 * @version     0.1
 * @date        2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GRAPHS_DSATUR_H
#define GRAPHS_DSATUR_H

#include "Graph.h"

namespace graphs
{
    Graph DSATUR (Graph &graph)
    {
        // [1]  Checking if the graph is empty. If it is, simply return it back.
    
        if (graph.vertices.size() == 0) return graph;

        // [2]      Treating the vertex with maximum degree.
        // [2.1]    Find vertex with maximum degree.
        // [2.2]    Assign first color to it.
        // [2.3]    Mark this vertex as colored.
        // [2.4]    Update the saturation degree of its neighbors.
        // [2.5]    Since all the neighbors of this vertex will be colored
        //          we can update its saturation degree. This will be done
        //          only on this first vertex. 
        
        auto max_degree = graph.find_maximum_degree();
        max_degree->vertex_color = 0;
        max_degree->colored = true;
        max_degree->update_neighbors_saturation_degree();
        max_degree->saturation_degree = max_degree->adjacent_vertices.size();

        return graph;
    }
}

#endif // GRAPHS_DSATUR_H