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
   size_t idx_ = 0;

 public:
   Tile();
   Tile(json &in);

   const uint8_t GetBottom();
   const uint8_t GetTop();
   const uint8_t GetLeft();
   const uint8_t GetRight();
   const size_t GetIndex();
   
   void SetIndex(size_t idx);
   void SetEdges(uint8_t bottom, uint8_t top, uint8_t left, uint8_t right);
   void Rotate();
   json ToJSON();

   friend bool operator== (const Tile &lhs, const Tile& rhs) {
      if (lhs.bottom_ == rhs.bottom_ && lhs.top_ == rhs.top_ &&
          lhs.left_ == rhs.left_ && lhs.right_ == rhs.right_) {
         return true;
      } else {
         return false;
      }
   }

   friend bool operator< (const Tile&lhs, const Tile&rhs) {
      return lhs.idx_ < rhs.idx_;
   }
};

class Scenario {
 private:
    std::vector<Tile> tiles_;
    uint8_t order_;
 public:
    // Constructors 
    Scenario();
    Scenario(std::vector<Tile> tiles);
    Scenario(json &in);

    // Exporters
    std::vector<TetraVex::Tile> GetTiles();
    json ToJSON();

    // Helpers
    void Randomise();
    bool Check();

    // Generators
    void GenerateSolvedScenario(uint8_t order, uint8_t num_colours);
    void GenerateRandomScenario(uint8_t order, uint8_t num_colours);

    // Solvers
    void BogoSolve();
    void BruteForceSolve();
};

/* Helper functions for scenario generation */
json GenerateSolvedScenario(uint8_t order, uint8_t num_colours);
json GenerateRandomScenario(uint8_t order, uint8_t num_colours);
};  // namespace TetraVex
