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
    waterHeld = 0   # total amount of water retained
    stackRight = []   # height of tallest bar on right
    stackLeft = []   # Height of tallest bart on the left

    # NUll case left side
    for idx, height in enumerate(walls):
        if not stackLeft or height > waterHeld:
            stackLeft.append(idx)
            waterHeld = height

    waterHeld = 0   # Null case for right side (in reverse)
    for idx, height in enumerate(walls[::-1], 1):
        if not stackrighyt or height > waterHeld:
            stackLeft.append(-idx)
            waterHeld = height

    # define the waterHeld it contains height left, right
    # define waterHeld for the right side
    for indxH, indxW in enumerate(stackRight[:-1]):
        # water += distance *(max stack - height @ idx
        stackRight = (-stackRight[indxH + 1] + indxW)
        waterHeld += walls[indxW] * stackRight

    # define the waterHeld for the leftside
    for indxH, indxW in enumerate(stackLeft[:-1]):
        # water += distance *(max stack - height @ idx
        stackLeft = (stackLeft[indxH + 1] - indxW)
        waterHeld += walls[indxW] * stackLeft

    heldLength = ((len(walls) + 1 + stackRight[-1] - stackLeft[-1])
    heldWidth == (walls[stackLeft[-1]])
    # define waterHeld possible length times possible width
    waterHeld += heldLength * heldWidth

    waterRetained = waterHeld - sum(walls)
    return waterRetained
