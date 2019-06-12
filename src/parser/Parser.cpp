/**
 * @file        Parser.cpp
 * @author      Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author      Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief       This file implements the Parser class.
 * @version     0.1
 * @date        2019-06-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "../../include/parser/Parser.h"

using namespace graphs;
using namespace tinyxml2;

Parser::Parser(std::string filepath)
    : filename{filepath}
{
    // Extracting Node element from XML and checking if it exists
    graph_file.LoadFile(filename.c_str());
    pRoot = graph_file.FirstChildElement("graph");

    if (pRoot == nullptr)
    {
        std::cout << "ERROR: Not able to find root node." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Parser::run()
{
    parse_graph_file();
}

void Parser::parse_graph_file()
{
    
}