#!/usr/bin/python3
"""
Calculate how much water will be retained after is raind
"""


def rain(walls):
    """
    Calculate the maximum amount of water stored
    :param walls: list of non negative numbers
    :return: integer indicating amount of water retained
    """

    if len(walls) == 0:
        return 0
    waterRetained = 0   # total amount of water retained
    stackRight = 0   # height of tallest bar on right
    stackLeft = 0  # Height of tallest bart on the left

    for height in range(1, len(walls) - 1):
        stackLeft = max(walls[:height])
        stackRight = max(walls[height+1:])

        reservoir = min(stackLeft, stackRight) - walls[height]
        waterRetained += max(0, reservoir)
    return waterRetained
