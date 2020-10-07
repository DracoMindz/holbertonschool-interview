#!/usr/bin/python3
"""
Function returns a list of lists of integers representing
the Pascal's triangle of n
"""


def pascal_triangle(n):
    """
    returns a list of list of integers representing
    Pascal's Triangle of n
    :param n: integers
    :return: Pascal's Trangle
    """
    trow = [1]
    y = [0]

    for x in range(n):
        print(trow)
        trow = [left + right for left, right in zip(trow + y, y + trow)]
    return n > 1
