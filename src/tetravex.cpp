/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <nlohmann/json.hpp>

#include <iostream>
#include <string>
#include <vector>

#include "tetravex.hh"

char help[] = 
    "TetraVex Help Menu. The options are:\n" \
    "\t--help: Display this helpful message\n" \
    "\t--generate: Generate a puzzle with randomised tile order\n" \
    "\t--generate-solved: Generate a puzzle with a solved tile order\n" \
    "All outputs are JSON\n";
              

int main(int argc, char** argv) {
    if (std::string(*(argv + 1)) == "--help") {
        std::cout << help;
        exit(EXIT_SUCCESS);
    }

    if (std::string(*(argv + 1)) == "--generate"){
        auto scenario = TetraVex::GenerateRandomScenario(4, 4);
        std::cout << scenario;
        exit(EXIT_SUCCESS);
    }

    if (std::string(*(argv + 1)) == "--generate-solved"){
        auto scenario = TetraVex::GenerateSolvedScenario(4, 4);
        std::cout << scenario;
        exit(EXIT_SUCCESS);
    }
}