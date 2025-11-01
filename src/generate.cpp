/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <nlohmann/json.hpp>

#include <vector>

#include "tetravex.hh"

using nlohmann::json;

/**
 * @brief Generates a valid scenario. Output is a vector of tiles in order from
 * left to right, top to bottom.
 * 
 * @param order 
 * @param num_colours 
 * @return std::vector<TetraVex::Tile> 
 */
static inline std::vector<TetraVex::Tile> GenerateScenarioVec(uint8_t order, 
                                                          uint8_t num_colours) {
    /* Generate the tiles in a loop */
    srand(time(NULL));
    uint8_t outer = rand() % num_colours;
    std::vector<TetraVex::Tile> tile_vec;
    for (size_t i = 0; i < order; i++) {
        for (size_t j = 0; j < order; j++) {
            size_t pos = order * i + j;
            TetraVex::Tile tile;
            uint8_t bottom, top, left, right;

            /* Set the left edge to outer if first in row.
               Set the left edge to previous right edge colour if not on a 
               a side.*/
            if (j == 0) {
                left = outer;
            } else {
                left = tile_vec.at(pos - 1).GetRight();
            }

            /* Set the right edge to outer if last in row. Otherwise set to a 
               random number. */
            if (j == order - 1) {
                right = outer;
            } else {
                right = rand() % num_colours;
            }

            /* Set the top edge to outer if first in column.
               Set the top edge to the previous bottom edge if not on a side. */
            if (i == 0) {
                top = outer;
            } else {
                top = tile_vec.at(pos - order).GetBottom();
            }

            /* Set the bottom edge to outer if last in column. */
            if (i == order - 1) {
                bottom = outer;
            } else {
                bottom = rand() % num_colours;
            }

            tile.SetEdges(bottom, top, left, right);
            tile_vec.push_back(tile);
        }
    }

    return tile_vec;
}

/**
 * @brief Generate a solved scenario object.
 * 
 * @param order 
 * @param num_colours 
 */
void TetraVex::Scenario::GenerateSolvedScenario(uint8_t order,  
                                                          uint8_t num_colours) {
    this->tiles_ = GenerateScenarioVec(order, num_colours);
    this->order_ = order;
}

/**
 * @brief Generate a random, solvable scenario object.
 * 
 * @param order 
 * @param num_colours 
 */
void TetraVex::Scenario::GenerateRandomScenario(uint8_t order, 
                                                          uint8_t num_colours) {
    this->GenerateSolvedScenario(order, num_colours);
    this->Randomise();
}

/**
 * @brief Generates a random valid set of tiles. The tiles are output as a json
 * object from left to right, top to bottom. Outer edges are always one colour.
 * 
 * @param order 
 * @return json 
 */
json TetraVex::GenerateSolvedScenario(uint8_t order, uint8_t num_colours) {
    TetraVex::Scenario scenario;
    scenario.GenerateSolvedScenario(order, num_colours);
    return scenario.ToJSON();
}

/**
 * @brief Generates a random valid set of tiles. The tiles are output as a json
 * object in a random order.
 * 
 * @param order 
 * @param num_colours 
 * @return json 
 */
json TetraVex::GenerateRandomScenario(uint8_t order, uint8_t num_colours) {
    TetraVex::Scenario scenario;
    scenario.GenerateRandomScenario(order, num_colours);
    return scenario.ToJSON();
}
