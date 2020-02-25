#!/usr/bin/python3
"""Caluculate minimum number of operations to create string"""


from math import sqrt


def minOperations(n):
    """Find minimum sum of factors of number"""

    numOps = 0
    m = 0

    if n <= 1:
        return 0
    for m in range(2, int(sqrt(n) + 1)):
        while (n % m == 0):
            n /= m
            numOps += m
        if (n % m != 0):
            numOps += 0
    return numOps
