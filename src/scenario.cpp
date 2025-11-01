/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <nlohmann/json.hpp>

#include <vector>

#include "tetravex.hh"

using nlohmann::json;

/**
 * @brief Construct a new Tetra Vex:: Scenario:: Scenario object
 * 
 */
TetraVex::Scenario::Scenario() {
    return;
}

/**
 * @brief Construct a new Tetra Vex:: Scenario:: Scenario object
 * 
 * @param tiles 
 */
TetraVex::Scenario::Scenario(std::vector<TetraVex::Tile> tiles) {
    this->tiles_ = tiles;
    this->order_ = sqrt(this->tiles_.size());
}

/**
 * @brief Construct a new Tetra Vex:: Scenario:: Scenario object
 * 
 * @param in 
 */
TetraVex::Scenario::Scenario(json &in) {
    for (size_t i = 0; i < in["scenario"].size(); i++) {
        TetraVex::Tile tile(in["scenario"].at(i));
        this->tiles_.push_back(tile);
    }
    
    this->order_ = sqrt(this->tiles_.size());
}

/**
 * @brief Returns a copy of the internal tile list as a vector. 
 * 
 * @return std::vector<TetraVex::Tile> 
 */
std::vector<TetraVex::Tile> TetraVex::Scenario::GetTiles() {
    return this->tiles_;
}

/**
 * @brief Exports a Scenario object as json.
 * 
 * @return json 
 */
json TetraVex::Scenario::ToJSON() {
    json output;
    output["scenario"] = json::array();

    for (size_t i = 0; i < this->tiles_.size(); i++) {
        output["scenario"].push_back(this->tiles_.at(i).ToJSON());
    }

    return output;
}

/**
 * @brief Randomises the order and rotation of the tiles.
 * 
 */
void TetraVex::Scenario::Randomise() {
    /* Randomize the order of the vector */
    std::vector<TetraVex::Tile> rand_tiles;

    for (size_t i = 0; i < pow(this->order_, 2); i++) {
        size_t index = rand() % this->tiles_.size();
        TetraVex::Tile tile = this->tiles_.at(index);

        /* Rotate the tile a random number of times */
        size_t num_rotate = rand() % 3;
        for (size_t j = 0; j < num_rotate; j++) {
            tile.Rotate();
        }

        rand_tiles.push_back(tile);
        this->tiles_.erase(this->tiles_.begin() + index);
    }

    this->tiles_ = rand_tiles;
}
