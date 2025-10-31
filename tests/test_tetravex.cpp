/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "tetravex.hh"

/* Test to see if a JSON Tile object is parsed correctly */
TEST(TetraVexTile, ToJson1) {
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

/* Test to see if a JSON Tile object is parsed correctly */
TEST(TetraVexTile, ToJson2) {
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

/* Test to see if a Tile object is created from a JSON string correctly */
TEST(TetraVexTile, FromJson1) {
    json tile_json = json::parse(R"(
    {
    "tile": {
        "bottom": 1,
        "top": 2,
        "left": 3,
        "right": 4
    }})");

    TetraVex::Tile tile(tile_json);

    EXPECT_EQ(tile.GetBottom(), 1);
    EXPECT_EQ(tile.GetTop(), 2);
    EXPECT_EQ(tile.GetLeft(), 3);
    EXPECT_EQ(tile.GetRight(), 4);
}

/* Test to see if a Tile object is created from a JSON string correctly */
TEST(TetraVexTile, FromJson2) {
    json tile_json = json::parse(R"(
    {
    "tile": {
        "bottom": 5,
        "top": 6,
        "left": 7,
        "right": 8
    }})");

    TetraVex::Tile tile(tile_json);

    EXPECT_EQ(tile.GetBottom(), 5);
    EXPECT_EQ(tile.GetTop(), 6);
    EXPECT_EQ(tile.GetLeft(), 7);
    EXPECT_EQ(tile.GetRight(), 8);
}

/* Test to see if Roate method works as intended */
TEST(TetraVexTile, Rotate1) {
    json tile_json = json::parse(R"(
    {
    "tile": {
        "bottom": 1,
        "top": 2,
        "left": 3,
        "right": 4
    }})");

    TetraVex::Tile tile(tile_json);

    tile.Rotate();

    EXPECT_EQ(tile.GetBottom(), 4);
    EXPECT_EQ(tile.GetTop(), 3);
    EXPECT_EQ(tile.GetLeft(), 1);
    EXPECT_EQ(tile.GetRight(), 2);
}

/* Test to see if Roate method works as intended */
TEST(TetraVexTile, Rotate2) {
    json tile_json = json::parse(R"(
    {
    "tile": {
        "bottom": 5,
        "top": 6,
        "left": 7,
        "right": 8
    }})");

    TetraVex::Tile tile(tile_json);

    tile.Rotate();

    EXPECT_EQ(tile.GetBottom(), 8);
    EXPECT_EQ(tile.GetTop(), 7);
    EXPECT_EQ(tile.GetLeft(), 5);
    EXPECT_EQ(tile.GetRight(), 6);
}
