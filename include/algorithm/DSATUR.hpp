/**
 * @file        DSATUR.hpp
 * @author      Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author      Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief       This file defines the DSATUR algorithm implementation.
 * @version     0.1
 * @date        2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GRAPHS_DSATUR_HPP
#define GRAPHS_DSATUR_HPP

#include "../graph/Graph.h"

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
        max_degree->vertex_color = 1;
        max_degree->colored = true;
        max_degree->update_neighbors_saturation_degree();
        max_degree->saturation_degree = max_degree->adjacent_vertices.size();

        // [3]      Coloring the remaining vertices
        // [3.1]    Tries to find the vertex with maximum saturation degree.
        //          If the algorithm cannot find one, all vertices are colored.
        // [3.2]    After finding the vertex with the most saturated degree,
        //          we must find its color. This is done by looking at the colors
        //          of its neighbors and getting the lesser unused color.
        // [3.3]    We now repeat steps [2.3] and [2.4].

        while (!graph.is_colored())
        {
            Vertex* max_sat_degree = graph.find_maximum_saturation_degree();
            max_sat_degree->color_vertex(graph.colors);
            max_sat_degree->colored = true;
            max_sat_degree->update_neighbors_saturation_degree();
        }

        return graph; 
    }
}

#endif // GRAPHS_DSATUR_HPP
