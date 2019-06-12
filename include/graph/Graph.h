/**
 * @file        Graph.h
 * @author      Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author      Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief       This file defines the Graph class.
 * @version     0.1
 * @date        2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "Edge.h"
#include "Vertex.h"
#include <iostream>

namespace graphs
{
    class Graph
    {
        public:
            // [1] Attributes

            std::vector<Edge*> edges;
            std::vector<Vertex*> vertices;
            std::set< int, std::greater<int> > colors;

            // [2] Methods

            /**
             * @brief           Construct a new Graph object
             * 
             * @param edges     Vector of edges of this graph
             * @param vertices  Vector of verticies of this graph
             */
            Graph(std::vector<Edge*> edges, std::vector<Vertex*> vertices);

            /**
             * @brief           Finds the vertex with the maximum degree.
             * 
             * @return Vertex*  Vertex with the maximum degree within this graph. 
             */
            Vertex* find_maximum_degree();

            /**
             * @brief           Finds the vertex with the maximum saturation degree.
             * 
             * @return Vertex*  Vertex with the maximum saturation degree within this graph.
             */
            Vertex* find_maximum_saturation_degree();

            /**
             * @brief           Checks if the graph is fully colored.
             * 
             * @return true     If all vertices have a color.
             * @return false    Otherwise.
             */
            bool is_colored();

            /**
             * @brief           Checks if the graph has a valid coloring.
             * 
             * @return true     If no adjacent vertices share the same color.
             * @return false    Otherwise.
             */
            bool is_valid();

            /**
             * @brief           Computes the chromatic number of this graph, by the
             *                  perspective of DSATUR's algorithm.
             * 
             * @return int      The chromatic number.
             */
            int dsatur_chromatic();

            /**
             * @brief           Prints the colors of this graph's vertices.
             */
            void print_colors();
    };
}

#endif // GRAPHS_GRAPH_H