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

#include "../include/algorithm/DSATUR.hpp"
#include "../include/parser/Parser.h"

using namespace graphs;

void init_engine(const char* filename);

int main(int argc, char *argv[])
{
    // [1]  Get from user the graph file.
    if (argc != 2)
    {
        std::cout << "Unable to run the algorithm without the graph file." << std::endl;
        std::cout << "Expecting: ./graphs.out <xml_file>" << std::endl;
        exit(EXIT_FAILURE);
    }

    // [2]  Printing welcome menu
    std::cout << "+=========================================+\n"
              << "|       Graphs -- Implementing DSATUR     |\n"
              << "|            Lucas Gomes Dantas           |\n"
              << "|         Tayanne Ferreira da Rocha       |\n" 
              << "+=========================================+\n";
    std::cout << "\nRunning: " << argv[1] << std::endl;

    // [3]  Calling the subprogram that preprocess the graph file
    init_engine(argv[1]);
}

void init_engine(const char* filename)
{
    // [1]  Parser file with the graph
    Parser parser(filename);
    parser.parse_graph_file();
}