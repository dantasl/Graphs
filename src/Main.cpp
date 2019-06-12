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

using namespace graphs;

int main(int argc, char *argv[])
{
    // [1]  Get from user the graph file.
    std::string filename;
    if (argc == 2) filename = argv[1];
    else
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

    // [3]  Calling the parser

}