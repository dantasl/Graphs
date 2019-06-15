/**
 * @file        TestCaseGenerator.hpp
 * @author      Lucas Gomes Dantas (dantaslucas@ufrn.edu.br)
 * @author      Tayanne Ferreira da Rocha (tayaneferreiradarocha@gmail.com)
 * @brief       This implements the code to generate random test cases.
 * @version     0.1
 * @date        2019-06-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GRAPHS_TESTCASEGENERATOR_HPP
#define GRAPHS_TESTCASEGENERATOR_HPP

#include <random>
#include <iostream>
#include <string>
#include "../parser/tinyxml2.h"

using namespace tinyxml2;

namespace graphs
{
    const int PATIENTS_NUMBER = 1000;
    const int MAX_SCHEDULES = 10;
    
    void generate_test_case(std::string filename)
    {
        // Create the test case file with a root node
        XMLDocument test_case;
        XMLNode *pRoot = test_case.NewElement("graph");
        test_case.InsertFirstChild(pRoot);
        XMLElement *pPatient, *pSchedule;

        // Instantiating random configuration
        std::random_device device;
        std::mt19937 generator(device());
        std::uniform_int_distribution<int> schedules(1, MAX_SCHEDULES);
        std::uniform_int_distribution<int> minutes(0,59);
        std::uniform_int_distribution<int> hours(0, 23);

        // Generating the "n" patients
        int n_schedules, n_hour, n_minute;
        std::string str_hour, str_minute;
        std::string sch_list;
        for (int patient_id(1); patient_id <= PATIENTS_NUMBER; ++patient_id)
        {
            pPatient = test_case.NewElement("patient");
            pPatient->SetAttribute("id", std::to_string(patient_id).c_str());
            n_schedules = schedules(generator);
            sch_list = "";
            for (int schedules_patient(0); schedules_patient < n_schedules; ++schedules_patient)
            {
                n_hour = hours(generator);
                n_minute = minutes(generator);

                if (n_hour < 10) str_hour = "0" + std::to_string(n_hour);
                else str_hour = std::to_string(n_hour);

                if (n_minute < 10) str_minute = "0" + std::to_string(n_minute);
                else std::to_string(n_minute);

                sch_list += str_hour + "h" + str_minute;
                if ( (schedules_patient + 1) != n_schedules ) sch_list += " "; 
            }
            pSchedule = test_case.NewElement("schedule");
            pSchedule->SetAttribute("list", sch_list.c_str());
            pPatient->InsertEndChild(pSchedule);
            pRoot->InsertEndChild(pPatient);
        }
        test_case.SaveFile(filename.c_str());
    }
}

#endif // GRAPHS_TESTCASEGENERATOR_HPP