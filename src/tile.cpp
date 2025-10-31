/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <nlohmann/json.hpp>

#include "tetravex.hh"

/**
 * @brief Sets the edge values for the tile.
 * 
 * @param bottom 
 * @param top 
 * @param left 
 * @param right 
 */
void TetraVex::Tile::SetEdges(uint8_t bottom, uint8_t top,
                              uint8_t left, uint8_t right) {
    this->bottom_ = bottom;
    this->top_ = top;
    this->left_ = left;
    this->right_ = right;
}

/**
 * @brief Converts a tile obect to json object
 * 
 * @return json 
 */
json TetraVex::Tile::ToJSON() {
    json output;
    output["tile"]["bottom"] = this->bottom_;
    output["tile"]["top"] = this->top_;
    output["tile"]["left"] = this->left_;
    output["tile"]["right"] = this->right_;

    return output;
}
