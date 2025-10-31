/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <nlohmann/json.hpp>

#include <iostream>
#include <vector>

#include "tetravex.hh"

int main(int argc, char** argv) {
    auto scenario = TetraVex::GenerateScenario(4, 4);
    std::cout << scenario;
}