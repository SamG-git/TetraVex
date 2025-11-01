/*
License: 3-Clause BSD
Copyright: S J GEORGE (2025)
*/

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "tetravex.hh"

TEST(TetraVexSolvers, BruteForceOrder2) {
    // Generate a random 2x2 puzzle
    TetraVex::Scenario scenario;
    scenario.GenerateRandomScenario(2, 4);
    auto pre_vec = scenario.GetTiles();

    scenario.BruteForceSolve();
    auto post_vec = scenario.GetTiles();

    EXPECT_TRUE(scenario.Check());
}

TEST(TetraVexSolvers, BruteForceOrder3) {
    // Generate a random 2x2 puzzle
    TetraVex::Scenario scenario;
    scenario.GenerateRandomScenario(3, 4);
    auto pre_vec = scenario.GetTiles();

    scenario.BruteForceSolve();
    auto post_vec = scenario.GetTiles();

    EXPECT_TRUE(scenario.Check());
}
