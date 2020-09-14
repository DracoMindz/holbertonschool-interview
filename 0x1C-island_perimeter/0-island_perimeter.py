#!/usr/bin/python3
"""
Function retrurns the perimeter of the island
"""


def island_perimeter(grid):
    """
    calculate the perimeter of the island
    :param grid: list of list of ints

    Notre:  0 reps water
            1 reps lands
            Each cell is square, w/ side len = 1
            Cells connected horizontally/vert only
            grid is rectangular
            width and height < 100
    Note:   grid completely surrounded by water
            only one island or nothing
            island has no lakes
    :return: perimeter of the island in grid
    """
    waterLand = len(grid)
    onlyLand = len(grid[0])
    perimeter = 0

    if not grid:
        return 0
    if (waterLand <= 0):
        return 0

    # check length list in larger grid, smaller grid
    for row in range(waterLand):
        for col in range(onlyLand):
            if grid[row][col] == 1:
                perimeter += 4
                # account for water on all sides
                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 2
                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 2
    return perimeter
