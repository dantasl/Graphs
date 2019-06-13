/**
 * @file        Parser.h   
 * @author      Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author      Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief       This file defines the Parser static class.
 * @version     0.1
 * @date        2019-06-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GRAPHS_PARSER_H
#define GRAPHS_PARSER_H

#include <iterator>
#include <sstream>
#include <string>
#include <list>
#include "tinyxml2.h"
#include "../graph/Graph.h"

using namespace tinyxml2;

namespace graphs
{
    const int TA = 5;
    class Parser
    {
        private:

            // [1] - Private Attributes

            tinyxml2::XMLDocument graph_file;
            tinyxml2::XMLNode *pRoot;
            std::list<std::string> schedules_list;

            // [2] - Private Methods

            /**
             * @brief                   This function will add minutes to an hour.
             * 
             * @param hour              The hour to add the minutes.
             * @param minutes_to_add    The minutes to be added.
             * @return std::string      The new hour, with the minutes added.
             */
            std::string add_minutes_to(std::string hour, int minutes_to_add);

            /**
             * @brief           This function will check if one hour is greater
             *                  than or equal to another hour.
             * 
             * @param h1        The first hour.
             * @param h2        The second hour.
             * @return true     If the first hour is greater than or equal the second.
             * @return false    Otherwise.
             */
            bool hour_greater_equal(std::string h1, std::string h2);
            
            /**
             * @brief           This function will iterate over the schedule list of
             *                  a patient, check for conflicts and add the schedules
             *                  to the schedules_list attribute.
             * 
             * @param patient   The patient to treat its schedule list.
             */
            void treat_patient_schedule(XMLElement *patient);

            /**
             * @brief           This function will check if there's a conflict between
             *                  two hours.
             * 
             * @param h1        The first hour to check conflict.
             * @param h2        The second hour to check conflict.
             * @return true     If there's a conflict between them.
             * @return false    Otherwise.
             */
            bool errors_minimization(std::string h1, std::string h2);

            /**
             * @brief Create vertices from schedules_list.
             */
            void create_vertices_from_list();

        public:

            // [3] - Public Attributes

            std::string filename;
            std::vector<Edge*> parser_edges;
            std::vector<Vertex*> parser_vertices;

            // [4] - Public Methods

            /**
             * @brief Construct a new Parser object
             * 
             * @param filepath 
             */
            Parser(std::string filepath);

            /**
             * @brief Destroy the Parser object
             */
            ~Parser() = default;

            /**
             * @brief This will load the graph file and treat its content.
             */
            void parse_graph_file();
    };    
}

#endif // GRAPHS_PARSER_H