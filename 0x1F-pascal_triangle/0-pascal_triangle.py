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
    trow = []

    for x in range(1, n + 1):
        trow.append([1] * x)
    for y in range(2, n):
        numrow = trow[y]
        oldrow = trow[y - 1]
        for z in range(1, len(numrow) - 1):
            numrow[z] = oldrow[z - 1] + oldrow[z]
    return trow
