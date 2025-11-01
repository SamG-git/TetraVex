/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <algorithm>
#include <iostream>
#include <vector>

#include "tetravex.hh"

/**
 * @brief Attempts to solve the scenario by randomizing all the tiles position
 * and orientation until a correct solution is found.
 * 
 */
void TetraVex::Scenario::BogoSolve() {
    size_t count = 0;
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

/* Loop through every possible combination to find a working result */
void TetraVex::Scenario::BruteForceSolve() {
    size_t count = 0;
    double num_rotation_comb = pow(this->tiles_.size(), 4);

    do {
        /* Check if we have the right solution */
        if (this->Check() == true) {
            return;
        }

        // Try every combination of tile rotation
        for (size_t i = 0; i < num_rotation_comb; i++) {
            for (size_t j = 0; j < this->tiles_.size(); j++) {
                if (i % static_cast<int>(pow(4, j)) == 0) {
                    this->tiles_.at(j).Rotate();
                }
            }
            if (this->Check() == true) {
                return;
            }
        }

        count += num_rotation_comb;
    } while (std::next_permutation(this->tiles_.begin(), this->tiles_.end()));

    std::cout << "Tried all " << count << " possible permutations; no " \
    "solution found :-(\n";
}
