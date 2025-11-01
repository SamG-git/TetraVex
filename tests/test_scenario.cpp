/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "tetravex.hh"

/* This file tests the Scenario object's constructors & exporters */

// Test to see if a Scenario object can be created from a vector of tiles.
TEST(TetraVexScenario, FromVector1) {
    // Create the vector of Tiles
    TetraVex::Tile tile1, tile2, tile3, tile4;
    tile1.SetEdges(1, 2, 3, 4);
    tile2.SetEdges(4, 3, 2, 1);
    tile3.SetEdges(4, 2, 3, 2);
    tile4.SetEdges(1, 1, 4, 1);
    std::vector<TetraVex::Tile> tile_vec = {tile1, tile2, tile3, tile4};

    // Create the Scenario object and test the output
    TetraVex::Scenario scenario(tile_vec);
    EXPECT_EQ(scenario.GetTiles(), tile_vec);
}

// Test to see if a Scenario object can be created from a vector of tiles.
TEST(TetraVexScenario, FromVector2) {
    // Create the vector of Tiles
    TetraVex::Tile tile1, tile2, tile3, tile4;
    tile1.SetEdges(4, 3, 2, 1);
    tile2.SetEdges(4, 1, 3, 1);
    tile3.SetEdges(4, 3, 3, 1);
    tile4.SetEdges(4, 2, 4, 1);
    std::vector<TetraVex::Tile> tile_vec = {tile1, tile2, tile3, tile4};

    // Create the Scenario object and test the output
    TetraVex::Scenario scenario(tile_vec);
    EXPECT_EQ(scenario.GetTiles(), tile_vec);
}

TEST(TetraVexScenario, JsonLoopback1) {
    json expected_json = json::parse(
    R"({"scenario":[{"tile":{"bottom":0,"left":0,"right":0,"top":1}},{"tile":
    {"bottom":0,"left":1,"right":2,"top":0}},{"tile":{"bottom":1,"left":0,
    "right":0,"top":0}},{"tile":{"bottom":0,"left":1,"right":0,"top":0}},
    {"tile":{"bottom":1,"left":3,"right":1,"top":0}},{"tile":{"bottom":2,
    "left":1,"right":2,"top":0}},{"tile":{"bottom":3,"left":2,"right":0,
    "top":0}},{"tile":{"bottom":2,"left":1,"right":0,"top":0}},{"tile":
    {"bottom":0,"left":0,"right":0,"top":3}},{"tile":{"bottom":0,"left":2,
    "right":0,"top":1}},{"tile":{"bottom":0,"left":3,"right":0,"top":2}},
    {"tile":{"bottom":2,"left":0,"right":2,"top":2}},{"tile":{"bottom":0,
    "left":0,"right":1,"top":3}},{"tile":{"bottom":0,"left":0,"right":1,
    "top":0}},{"tile":{"bottom":2,"left":0,"right":0,"top":2}},{"tile":
    {"bottom":2,"left":1,"right":2,"top":3}}]})");

    TetraVex::Scenario scenario(expected_json);
    EXPECT_EQ(scenario.ToJSON(), expected_json);
}

TEST(TetraVexScenario, JsonLoopback2) {
    json expected_json = json::parse(
    R"({"scenario":[{"tile":{"bottom":3,"left":2,"right":0,"top":0}},{"tile":
    {"bottom":0,"left":2,"right":0,"top":0}},{"tile":{"bottom":3,"left":3,
    "right":0,"top":3}},{"tile":{"bottom":1,"left":1,"right":1,"top":0}},
    {"tile":{"bottom":1,"left":1,"right":0,"top":1}},{"tile":{"bottom":3,
    "left":2,"right":0,"top":3}},{"tile":{"bottom":0,"left":1,"right":3,
    "top":3}},{"tile":{"bottom":1,"left":0,"right":1,"top":2}},{"tile":
    {"bottom":0,"left":1,"right":2,"top":0}},{"tile":{"bottom":3,"left":1,
    "right":3,"top":1}},{"tile":{"bottom":1,"left":2,"right":2,"top":1}},
    {"tile":{"bottom":0,"left":0,"right":0,"top":2}},{"tile":{"bottom":1,
    "left":3,"right":2,"top":0}},{"tile":{"bottom":0,"left":3,"right":0,
    "top":0}},{"tile":{"bottom":0,"left":3,"right":0,"top":3}},{"tile":
    {"bottom":0,"left":0,"right":2,"top":1}}]})");

    TetraVex::Scenario scenario(expected_json);
    EXPECT_EQ(scenario.ToJSON(), expected_json);
}

/* Checks to see that the Check method returns true on a known good scenario */
TEST(TetraVexScenario, KnownGoodCheck) {
    json scenario_json = json::parse(
    R"({"scenario":[{"tile":{"bottom":3,"left":0,"right":3,"top":0}},{"tile":
    {"bottom":2,"left":3,"right":3,"top":0}},{"tile":{"bottom":2,"left":3,
    "right":0,"top":0}},{"tile":{"bottom":0,"left":0,"right":0,"top":0}},
    {"tile":{"bottom":2,"left":0,"right":2,"top":3}},{"tile":{"bottom":1,
    "left":2,"right":3,"top":2}},{"tile":{"bottom":3,"left":3,"right":3,
    "top":2}},{"tile":{"bottom":2,"left":3,"right":0,"top":0}},{"tile":
    {"bottom":0,"left":0,"right":3,"top":2}},{"tile":{"bottom":2,"left":3,
    "right":2,"top":1}},{"tile":{"bottom":0,"left":2,"right":2,"top":3}},
    {"tile":{"bottom":3,"left":2,"right":0,"top":2}},{"tile":{"bottom":0,
    "left":0,"right":2,"top":0}},{"tile":{"bottom":0,"left":2,"right":3,
    "top":2}},{"tile":{"bottom":0,"left":3,"right":2,"top":0}},{"tile":
    {"bottom":0,"left":2,"right":0,"top":3}}]})");

    TetraVex::Scenario scenario(scenario_json);
    EXPECT_TRUE(scenario.Check());
}

/* Checks to see that the Check method returns false on a known bad scenario */
TEST(TetraVexScenario, KnownBadCheck) {
    json scenario_json = json::parse(
    R"({"scenario":[{"tile":{"bottom":0,"left":0,"right":3,"top":1}},{"tile":
    {"bottom":2,"left":0,"right":2,"top":1}},{"tile":{"bottom":1,"left":1,
    "right":1,"top":0}},{"tile":{"bottom":0,"left":3,"right":2,"top":2}},
    {"tile":{"bottom":0,"left":1,"right":3,"top":2}},{"tile":{"bottom":3,
    "left":2,"right":2,"top":2}},{"tile":{"bottom":0,"left":1,"right":0,
    "top":1}},{"tile":{"bottom":2,"left":0,"right":0,"top":0}},{"tile":
    {"bottom":0,"left":1,"right":0,"top":2}},{"tile":{"bottom":1,"left":0,
    "right":2,"top":0}},{"tile":{"bottom":2,"left":1,"right":0,"top":3}},
    {"tile":{"bottom":2,"left":3,"right":0,"top":1}},{"tile":{"bottom":0,
    "left":0,"right":0,"top":2}},{"tile":{"bottom":0,"left":0,"right":1,
    "top":3}},{"tile":{"bottom":2,"left":1,"right":1,"top":3}},{"tile":
    {"bottom":0,"left":1,"right":2,"top":0}}]})");

    TetraVex::Scenario scenario(scenario_json);
    EXPECT_FALSE(scenario.Check());
}