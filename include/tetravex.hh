/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#pragma once

#include <nlohmann/json.hpp>

#include <vector>

using nlohmann::json;

namespace TetraVex {
class Tile {
 private:
   uint8_t bottom_ = 0, left_ = 0, right_ = 0, top_ = 0;

 public:
   Tile();
   Tile(json &in);

   uint8_t GetBottom();
   uint8_t GetTop();
   uint8_t GetLeft();
   uint8_t GetRight();

   void SetEdges(uint8_t bottom, uint8_t top, uint8_t left, uint8_t right);
   void Rotate();
   json ToJSON();
};

json GenerateScenario(uint8_t order, uint8_t num_colours);
};  // namespace TetraVex
