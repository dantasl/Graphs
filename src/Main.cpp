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
#include <fstream>

using namespace graphs;

std::vector<Vertex*> run_parser(const char* filename);
void print_to_txt(std::vector<std::string> &log);

int main(int argc, char *argv[])
{
    std::vector<std::string> log;
    std::string temp;

    // [1]  Get from user the graph file.
    
    if (argc != 2)
    {
        std::cout << "Unable to run the algorithm without the graph file." << std::endl;
        std::cout << "Expecting: ./graphs.out <xml_file>" << std::endl;
        exit(EXIT_FAILURE);
    }

    // [2]  Printing welcome menu

    temp = std::string("+=========================================+\n")
                     + "|       Graphs -- Implementing DSATUR     |\n"
                     + "|            Lucas Gomes Dantas           |\n"
                     + "|         Tayanne Ferreira da Rocha       |\n" 
                     + "+=========================================+\n";
    std::cout << temp << std::endl;
    log.push_back(temp);

    temp = std::string("Running: ") + argv[1] + "\n";
    std::cout << temp;
    log.push_back(temp);

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
    
    if (graph.is_valid()) temp = "The resulting vertex coloring is valid.\n";
    else temp = "The above is an invalid vertex coloring.\n";
    std::cout << temp;
    log.push_back(temp);

    temp = std::string("TA of ") + std::to_string(TA) + " minutes. \n"
           + "The DSATUR algorithm ran in " + std::to_string(run_time) + " milliseconds. \n";
    std::cout << temp << std::endl;
    log.push_back(temp);
    
    temp = graph.get_colored();
    std::cout << temp << std::endl;
    log.push_back(temp);

    // [7] Printing to output file
    
    print_to_txt(log);
}

void print_to_txt(std::vector<std::string> &log)
{
    std::ofstream file("files/result_dsatur.txt");
    for (unsigned int i = 0; i < log.size(); ++i) file << log[i];
    file.close();
    std::cout << "Log generated at files/result_dsatur.txt" << std::endl;
}

std::vector<Vertex*> run_parser(const char* filename)
{
    // [1]  Parser file with the graph
    Parser parser(filename);
    parser.parse_graph_file();
    return parser.parser_vertices;
}