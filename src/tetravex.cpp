/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "tetravex.hh"

char help[] = 
    "TetraVex Help Menu. The options are:\n" \
    "\t--help: Display this helpful message\n" \
    "\t--generate: Generate a puzzle with randomised tile order\n" \
    "\t--generate-solved: Generate a puzzle with a solved tile order\n" \
    "\t --bogo-solve FILE: Solve the puzzle in FILE using random" \
    "permutations.\n" \
    "\t --brute-force FILE: Solve the puzzle in FILE using brute force\n" \
    "All outputs are JSON, all inputs are JSON files\n";
              

int main(int argc, char** argv) {
    if (std::string(*(argv + 1)) == "--help") {
        std::cout << help;
        exit(EXIT_SUCCESS);
    }

    if (std::string(*(argv + 1)) == "--generate"){
        auto scenario = TetraVex::GenerateRandomScenario(3, 4);
        std::cout << scenario;
        exit(EXIT_SUCCESS);
    }

    if (std::string(*(argv + 1)) == "--generate-solved"){
        auto scenario = TetraVex::GenerateSolvedScenario(4, 4);
        std::cout << scenario;
        exit(EXIT_SUCCESS);
    }

    if (std::string(*(argv + 1)) == "--bogo-solve"){
        if (argc < 3) {
            std::cout << "--bogo-solve needs a FILE as argument" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::ifstream f(*(argv + 2));
        json scenario_json = json::parse(f);

        auto scenario = TetraVex::Scenario(scenario_json);
        scenario.BogoSolve();
        std::cout << scenario.ToJSON();
        exit(EXIT_SUCCESS);
    }

    if (std::string(*(argv + 1)) == "--brute-force") {
        if (argc < 3) {
            std::cout << "--brute-force needs a FILE as argument" << std::endl;
            exit(EXIT_FAILURE);
        }

        std::ifstream f(*(argv + 2));
        json scenario_json = json::parse(f);

        auto scenario = TetraVex::Scenario(scenario_json);
        scenario.BruteForceSolve();
        std::cout << scenario.ToJSON();
        exit(EXIT_SUCCESS);
    }
}