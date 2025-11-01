/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <nlohmann/json.hpp>

#include "tetravex.hh"

/**
 * @brief Construct a new Tetra Vex:: Tile object
 * 
 */
TetraVex::Tile::Tile() {
    return;
}

/**
 * @brief Construct a new Tetra Vex:: Tile:: Tile object
 * 
 * @param in 
 */
TetraVex::Tile::Tile(json &in) {
    this->bottom_ = in["tile"]["bottom"];
    this->top_ = in["tile"]["top"];
    this->right_ = in["tile"]["right"];
    this->left_ = in["tile"]["left"];
}

/**
 * @brief Get the value of the bottom edge
 * 
 * @return uint8_t 
 */
const uint8_t TetraVex::Tile::GetBottom() {
    return this->bottom_;
}

/**
 * @brief Get the value of the top edge
 * 
 * @return uint8_t 
 */
const uint8_t TetraVex::Tile::GetTop() {
    return this->top_;
}

/**
 * @brief Get the value of the left edge
 * 
 * @return uint8_t 
 */
const uint8_t TetraVex::Tile::GetLeft() {
    return this->left_;
}

/**
 * @brief Get the value of the right edge
 * 
 * @return uint8_t 
 */
const uint8_t TetraVex::Tile::GetRight() {
    return this->right_;
}

/**
 * @brief Gets the index value of the tile
 * 
 * @return const size_t 
 */
const size_t TetraVex::Tile::GetIndex() {
    return this->idx_;
}

/**
 * @brief Rotates the tile 90 degrees clockwise.
 * 
 */
void TetraVex::Tile::Rotate() {
    uint8_t new_top, new_bottom, new_left, new_right;

    new_top = this->left_;
    new_bottom = this->right_;
    new_left = this->bottom_;
    new_right = this->top_;

    this->left_ = new_left;
    this->right_ = new_right;
    this->top_ = new_top;
    this->bottom_ = new_bottom;
}

/**
 * @brief Set the tile's index
 * 
 * @param idx 
 */
void TetraVex::Tile::SetIndex(size_t idx) {
    this->idx_ = idx;
}

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
