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
        tile.SetIndex(i);
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

/**
 * @brief Checks whether the current scenario is solved.
 * 
 * @return true 
 * @return false 
 */
bool TetraVex::Scenario::Check() {
    // Loop through each tile in row and column order, from top row to bottom 
    // row.
    for (size_t i = 0; i < this->order_; i++) {
        for (size_t j = 0; j < this->order_; j++) {
            size_t pos = i * this->order_ + j;
            
            // Check the left edge
            if (j == 0) {
                if (i > 0) {
                    // Check with tile one higher
                    if (this->tiles_.at(pos).GetLeft() != 
                                this->tiles_.at(pos - this->order_).GetLeft()) {
                        return false;
                    }
                } else {
                    // Check it is a corner
                    if (this->tiles_.at(pos).GetLeft() != 
                                            this->tiles_.at(pos).GetTop()) {
                        return false;
                    }
                }
            } else {
                if (this->tiles_.at(pos).GetLeft() 
                                       != this->tiles_.at(pos - 1).GetRight()) {
                    return false;
                }
            }

            // Check the right edge if on outer
            if (j == this->order_ - 1) {
                if (i > 0) {
                    // Check with tile one higher
                    if (this->tiles_.at(pos).GetRight() != 
                               this->tiles_.at(pos - this->order_).GetRight()) {
                        return false;
                    }
                } else {
                    // Check it is a corner
                    if (this->tiles_.at(pos).GetRight() != 
                                                this->tiles_.at(pos).GetTop()) {
                        return false;
                    }
                }
            }

            // Check the top edge. Top corners have already been checked by 
            // previous logic.
            if (i == 0) {
                if (j > 0) {
                    // Check with previous tile
                    if (this->tiles_.at(pos).GetTop() 
                                         != this->tiles_.at(pos - 1).GetTop()) {
                        return false;
                    }
                }
            } else {
                // Check with tile in row above
                if (this->tiles_.at(pos).GetTop() != 
                                         this->tiles_.at(pos - this->order_).GetBottom()) {
                    return false;
                }
            }

            // Check the bottom edge if an outer and bottom
            if (i == this->order_ - 1) {
                if (j == 0) {
                    // Check bottom left corner
                    if (this->tiles_.at(pos).GetBottom() != 
                                               this->tiles_.at(pos).GetLeft()) {
                        return false;
                    }
                } else {
                    if (this->tiles_.at(pos).GetBottom() != 
                                         this->tiles_.at(pos - 1).GetBottom()) {
                        return false;
                    }
                    // Check bottom right corner
                    if (j == this->order_ - 1) {
                        if (this->tiles_.at(pos).GetBottom() != 
                                              this->tiles_.at(pos).GetRight()) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}
