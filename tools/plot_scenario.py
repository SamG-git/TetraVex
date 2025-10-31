#!/bin/python3

# License: 3-Clause BSD
# Copyright: S J GEORGE (2025)

import json
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon
import math
import numpy as np

colours = ['r', 'b', 'y', 'w']

def plot_scenario(scenario):
    fig, ax = plt.subplots()
    num_tiles = len(scenario["scenario"])
    order = math.sqrt(num_tiles)
    if (order % 1.0 != 0):
        print("Invalid Scenario")
        exit()

    order = int(order)

    for i in range(0, int(order)):
        for j in range(0, int(order)):
            tile = scenario["scenario"][i * order + j]["tile"]
            top_left = [j, order - i]
            top_right = [j + 1, order - i]
            bottom_left = [j, order - i - 1]
            bottom_right = [ j + 1, order - i - 1]
            centre = [j + 0.5, order - i - 0.5]

            # Plot all the triangles
            # Left
            p = Polygon(np.array([top_left, bottom_left, centre]), \
                        facecolor = colours[tile["left"]])
            ax.add_patch(p)
            # Right
            p = Polygon(np.array([top_right, bottom_right, centre]), \
                        facecolor = colours[tile["right"]])
            ax.add_patch(p)
            
            # Top
            p = Polygon(np.array([top_left, top_right, centre]), \
                        facecolor = colours[tile["top"]])
            ax.add_patch(p)
            
            # Bottom
            p = Polygon(np.array([bottom_left, bottom_right, centre]), \
                        facecolor = colours[tile["bottom"]])
            ax.add_patch(p)
        
    ax.set_xlim([0, order])
    ax.set_ylim([0, order])
    plt.show()

def print_scenario(scenario):
    num_tiles = len(scenario["scenario"])
    order = math.sqrt(num_tiles)
    if (order % 1.0 != 0):
        print("Invalid Scenario")
        exit()

    order = int(order)
    
    for i in range(0, int(order)):
        # print top line
        for j in range(0, int(order)):
            tile = scenario["scenario"][i * order + j]["tile"]
            print(" ", end="")
            print(tile["top"], end="")
            print(" ", end="")
        print()

        # print middle line
        for j in range(0, int(order)):
            tile = scenario["scenario"][i * order + j]["tile"]
            print(tile["left"], end="")
            print(" ", end="")
            print(tile["right"], end="")
        print()

        # print bottom line
        for j in range(0, int(order)):
            tile = scenario["scenario"][i * order + j]["tile"]
            print(" ", end="")
            print(tile["bottom"], end="")
            print(" ", end="")

        print()

def main():
    plot_scenario(json.loads(input()))

if __name__ == "__main__":
    main()
