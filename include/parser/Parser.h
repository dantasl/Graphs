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

            // [2] - Private Methods

            std::string add_minutes_to(std::string hour, int minutes_to_add);
            bool hour_greater_equal(std::string h1, std::string h2);
            void treat_patient_schedule(XMLElement *patient);
            bool errors_minimization(std::string h1, std::string h2);

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
            
            /**
             * @brief Calls all the necessary functions to fully parse the file.
             */
            void run();
    };    
}

#endif // GRAPHS_PARSER_H