#!/usr/bin/env python3
"""
Prime Game
"""


def isWinner(x, nums):
    """
    Determine the winner of each game
    :param x: num of rounds
    :param nums: array of  ints >= n
    :param n: numbers
    :return: the Winner of the round
    """
    for i in range(x):
        for n in range(x):
            numlen = len(nums)
            integersOdd = (int(numlen / 2))
            win = (integersOdd / 3) * 2

            if (win % 2 == 0):
                return "Maria"
            if (win % 2 != 0):
                return "Ben"
            if len(nums) == 0:
                return None
