/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <iostream>
#include <vector>

#include "tetravex.hh"

/**
 * @brief Attempts to solve the scenario by randomizing all the tiles position
 * and orientation until a correct solution is found.
 * 
 */
void TetraVex::Scenario::BogoSolve() {
    size_t count;
    srand(time(NULL));
    while (this->Check() == false) {
        this->Randomise();
        count++;

        if (count % 100000 == 0) {
            std::cout << count << '\n';
        }
    }

    std::cout << "Solution found in " << count << " tries!\n";
}
