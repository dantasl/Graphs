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
#include <chrono>

using namespace graphs;

std::vector<Vertex*> run_parser(const char* filename);

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
    
    auto vertices = run_parser(argv[1]);

    // [4]  Creating graph
    
    std::vector<Edge*> edges;
    Graph graph(edges, vertices);

    // [5] Invoking the DSATUR algorithm

    // ====================== Measuring DSATUR running time ======================
    auto start_dsatur = std::chrono::steady_clock::now();
    graph = DSATUR(graph);
    auto end_dsatur = std::chrono::steady_clock::now();
    // ===========================================================================
    
    auto time_diff = end_dsatur - start_dsatur;
    double run_time = std::chrono::duration <double, std::milli> (time_diff).count();

    // [6] Checking graph
    
    if (graph.is_valid()) std::cout << "The resulting vertex coloring is valid." << std::endl;
    else std::cout << "The above is an invalid vertex coloring." << std::endl;
    std::cout << "TA of " << TA << " minutes." << std::endl;
    std::cout << "The DSATUR algorithm ran in " << run_time << " milliseconds." << std::endl;
    graph.print_colors();
}

std::vector<Vertex*> run_parser(const char* filename)
{
    // [1]  Parser file with the graph
    Parser parser(filename);
    parser.parse_graph_file();
    return parser.parser_vertices;
}