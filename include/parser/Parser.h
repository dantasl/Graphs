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

#include "tinyxml2.h"
#include "../graph/Graph.h"

using namespace tinyxml2;

namespace graphs
{
    class Parser
    {
        private:

            // [1] - Private Attributes

            tinyxml2::XMLDocument graph_file;
            tinyxml2::XMLNode *pRoot;

        public:

            // [2] - Public Attributes

            std::string filename;

            // [3] - Public Methods

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

            void parse_graph_file();
            
            /**
             * @brief Calls all the necessary functions to fully parse the file.
             */
            void run();
    };    
}

#endif // GRAPHS_PARSER_H