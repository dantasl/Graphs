/**
 * @file            Vertex.h
 * @author          Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author          Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief           This file defines the Vertex class.
 * @version         0.1
 * @date            2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GRAPHS_VERTEX_H
#define GRAPHS_VERTEX_H

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

namespace graphs
{
    class Vertex
    {
        public:
            // [1] Attributes
                
                int identifier;                       
                int saturation_degree = 0;
                int vertex_color = -1;
                bool colored = false;
                std::string schedule;
                std::vector<Vertex*> adjacent_vertices;

            // [2] Methods

                /**
                 * @brief Construct a new Vertex object with a null graph.
                 */
                Vertex ();

                /**
                 * @brief           Construct a new Vertex object with identifier.
                 * 
                 * @param id        Vertex identifier.
                 * @param schedule  The schedule of the vertex.
                 */
                Vertex (int id, std::string schedule);

                /**
                 * @brief Destroy the Vertex object
                 */
                ~Vertex () = default;

                /**
                 * @brief       Return the degree of this vertex.
                 * 
                 * @return int 
                 */
                inline int degree() const { return adjacent_vertices.size(); }

                /**
                 * @brief           Adds one adjancet vertex to this vertex list of
                 *                  neighbors.
                 * 
                 * @param vertex    The vertex to be added.
                 */
                void add_adjacent_vertex (Vertex *vertex);

                /**
                 * @brief               Removes a vertex from this vertex list of
                 *                      neighbors.
                 * 
                 * @param identifier    The identifier of the vertex to be removed.
                 */
                void remove_adjacent_vertex (int identifier);

                /**
                 * @brief           Checks if a given vertex is adjacent to this one.
                 * 
                 * @param   vertex  The vertex to be checked if its adjacent. 
                 * @return  true    If the vertex is adjancent to this vertex.
                 * @return  false   Otherwise.
                 */
                bool is_adjacent (Vertex &vertex);

                /**
                 * @brief               Overloading of assignment operator in order
                 *                      to change this vertex to the other. 
                 * 
                 * @param   other       The vertex to copy the values.
                 * @return  Vertex&     The vertex with its contents changed.
                 */
                Vertex& operator= (const Vertex &other)
                {
                    this->identifier = other.identifier;
                    this->saturation_degree = other.saturation_degree;
                    this->vertex_color = other.vertex_color;
                    this->colored = other.colored;
                    this->schedule = other.schedule;
                    this->adjacent_vertices = other.adjacent_vertices;
                    return *this;
                }

                /**
                 * @brief           Overloading equality operator to check if two
                 *                  vertices are the same.
                 * 
                 * @param   other   The vertex to be compared about equality. 
                 * @return  true    If they have the same identifier and degree.
                 * @return  false   Otherwise.
                 */
                bool operator== (const Vertex &other)
                {
                    return this->identifier == other.identifier && this->degree() == other.degree();
                }

                /**
                 * @brief           Overloading difference operator to check if two
                 *                  vertices are not the same.
                 * 
                 * @param   other   The vertex to be compared about difference. 
                 * @return  true    If they don't have the same identifier and degree.
                 * @return  false   Otherwise.
                 */
                bool operator!= (const Vertex &other)
                {
                    return !(*this == other);
                }

                /**
                 * @brief           Checks if a given color is the same of any neighbor's.
                 * 
                 * @param color     The color to be checked.
                 * @param source    The identifier of the source vertex (i.e. the one who called)
                 * @return true     If there's at least one neighbor with the given color.
                 * @return false    Otherwise.
                 */
                bool neighbor_same_color(int color, int source);

                /**
                 * @brief           Given a certain vertex, increments the saturation
                 *                  degree of its neighbors.
                 */
                void update_neighbors_saturation_degree();

                /**
                 * @brief           Searches this vertex neighbors and assigns to this one
                 *                  the lesser color available.
                 * 
                 * @param colors    Set of available colors.
                 */
                void color_vertex(std::set< int, std::greater<int> > &colors);

                /**
                 * @brief   This function will print the neighbors of this vertex.
                 */
                void print_neighbors();
    };
}

#endif // GRAPHS_VERTEX_H