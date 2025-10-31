/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "tetravex.hh"

TEST(TetraVex, ToJson1) {
    json expected_json = json::parse(R"(
    {
    "tile": {
        "bottom": 1,
        "top": 2,
        "left": 3,
        "right": 4
    }})");

    TetraVex::Tile tile;
    tile.SetEdges(1,2,3,4);

    json output = tile.ToJSON();

    EXPECT_EQ(output, expected_json);

}

TEST(TetraVex, ToJson2) {
    json expected_json = json::parse(R"(
    {
    "tile": {
        "bottom": 5,
        "top": 6,
        "left": 7,
        "right": 8
    }})");

    TetraVex::Tile tile;
    tile.SetEdges(5,6,7,8);

    json output = tile.ToJSON();

    EXPECT_EQ(output, expected_json);

}