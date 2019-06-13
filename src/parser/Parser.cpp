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

std::string Parser::add_minutes_to(std::string hour, int minutes_to_add)
{
    // Replace "h" by a white space and splitting hours and minutes
    std::replace(hour.begin(), hour.end(), 'h', ' ');
    std::istringstream iss(hour);
    int temp;
    std::vector<int> hours;
    while (iss >> temp)
        hours.push_back(temp);       

    // Adding the minutes
    hours[1] += minutes_to_add;

    // If minutes are bigger than 59, we have to increment the hour
    if (hours[1] > 59)
    {
        if ( (hours[0] + 1) > 23 ) hours[0] = 0;
        else
        {
            hours[0] += 1;
            hours[1] -= 60;
        }
    }

    // Composing resulting string
    std::string result = "";
    if (hours[0] < 10) result += "0" + std::to_string(hours[0]);
    else result += std::to_string(hours[0]);

    if (hours[1] < 10) result += "h0" + std::to_string(hours[1]);
    else result += "h" + std::to_string(hours[1]);

    return result;
}

bool Parser::hour_greater_equal(std::string h1, std::string h2)
{
    // Replace "h" by a white space and splitting hours and minutes
    std::replace(h1.begin(), h1.end(), 'h', ' ');
    std::replace(h2.begin(), h2.end(), 'h', ' ');
    
    int temp;
    std::istringstream stream(h1);
    std::istringstream stream_two(h2);
    std::vector<int> hours_1;
    std::vector<int> hours_2;
    
    while (stream >> temp) hours_1.push_back(temp);
    while (stream_two >> temp) hours_2.push_back(temp);

    // Comparing hours
    if (hours_1[0] > hours_2[0])
        return true;
    else if (hours_1[0] == hours_2[0])
        return hours_1[1] >= hours_2[1];
    else
        return false;
}

bool Parser::errors_minimization(std::string h1, std::string h2)
{
    std::string min_hour, max_hour;
    // We need to find the minimum hour between h1 and h2
    if (hour_greater_equal(h1, h2))
    {
        max_hour = h1;
        min_hour = h2;
    }
    else
    {
        max_hour = h2;
        min_hour = h1;
    }    
    min_hour = add_minutes_to(min_hour, TA);
    return hour_greater_equal(min_hour, max_hour);
}

void Parser::treat_patient_schedule(XMLElement *patient)
{
    XMLElement *schedule = patient->FirstChildElement("schedule");
    std::string schedule_list = schedule->Attribute("list");

    // Splitting the list of schedules
    std::istringstream iss( schedule_list );
    std::set<std::string> schedules_split(
        std::istream_iterator<std::string>{iss},
        std::istream_iterator<std::string>()
    );

    // Comparing if any of the schedules of this patient share no conflicts
    std::set<std::string> no_conflicts;
    for (auto i = schedules_split.begin(); i != schedules_split.end(); ++i)
        for (auto j = i; j != schedules_split.end(); ++j)
            if (i != j)
            {
                if (!errors_minimization(*i, *j))
                {
                    no_conflicts.insert(*i);
                    no_conflicts.insert(*j);
                }
                else
                {
                    no_conflicts.erase(i, ++i);
                }
            }

    // Sending this to the list of schedules
    for (auto n : no_conflicts)
        this->schedules_list.push_back(n);
}

void Parser::create_vertices_from_list()
{
    // Taking only those who share no conflicts
    std::set<std::string> no_conflicts;
    bool conflicted = false;
    for (auto i = schedules_list.begin(); i != schedules_list.end(); ++i)
    {
        conflicted = false;
        for (auto j = schedules_list.begin(); j != schedules_list.end(); ++j)
        {
            if (i == j) continue;
            if ( errors_minimization(*i, *j) ) conflicted = true;                    
        }
        if (!conflicted) no_conflicts.insert(*i);
    }

    // We make a copy of the list
    std::list<std::string> conflicts(schedules_list.begin(), schedules_list.end());

    // And remove from this copied list the non-conflicting schedules
    for (const auto n: no_conflicts)
        conflicts.remove(n);
}

void Parser::parse_graph_file()
{
    // [1]  Iterating over all patients

    for ( auto patient = pRoot->FirstChildElement("patient");
          patient != nullptr;
          patient = patient->NextSiblingElement() )
    {
        treat_patient_schedule(patient);                                
    }

    // [2]  Now, its time to create the vertices of the graph

    create_vertices_from_list();
}