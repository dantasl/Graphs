/**
 * @file        Main.cpp
 * @author      Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author      Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief       Implements interface between user and algorithm.
 * @version     0.1
 * @date        2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../include/DSATUR.hpp"

using namespace graphs;

int main()
{
    // [1] Creating dummy vertices and edges
    Vertex *v1 = new Vertex(1);
    Vertex *v2 = new Vertex(2);
    Vertex *v3 = new Vertex(3);
    Vertex *v4 = new Vertex(4);
    Vertex *v5 = new Vertex(5);
    Vertex *v6 = new Vertex(6);
    Vertex *v7 = new Vertex(7);
    Vertex *v8 = new Vertex(8);
    Vertex *v9 = new Vertex(9);
    Vertex *v10 = new Vertex(10);

    // [2] Adding adjacent vertices
    
    v1->add_adjacent_vertex(v2);
    v1->add_adjacent_vertex(v3);
    v1->add_adjacent_vertex(v4);
    v1->add_adjacent_vertex(v5);
    v1->add_adjacent_vertex(v9);

    v2->add_adjacent_vertex(v3);
    v2->add_adjacent_vertex(v4);
    v2->add_adjacent_vertex(v9);
    v2->add_adjacent_vertex(v10);

    v3->add_adjacent_vertex(v5);

    v4->add_adjacent_vertex(v5);
    v4->add_adjacent_vertex(v7);

    v5->add_adjacent_vertex(v6);
    v5->add_adjacent_vertex(v8);
    v5->add_adjacent_vertex(v7);

    v6->add_adjacent_vertex(v8);
    v6->add_adjacent_vertex(v9);

    v7->add_adjacent_vertex(v9);
    v7->add_adjacent_vertex(v10);

    v8->add_adjacent_vertex(v9);

    v9->add_adjacent_vertex(v10);

    // [3] Adding vertices to vector

    std::vector<Edge*> edges;
    std::vector<Vertex*> vertices;
    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);
    vertices.push_back(v5);
    vertices.push_back(v6);
    vertices.push_back(v7);
    vertices.push_back(v8);
    vertices.push_back(v9);
    vertices.push_back(v10);
    

    // [4] Creating the graph

    Graph graph(edges, vertices);

    // [5] Invoking the DSATUR algorithm

    graph = DSATUR(graph);

    // [6] Checking graph
    if (graph.is_valid()) std::cout << "Yay!" << std::endl;
    graph.print_colors();
}