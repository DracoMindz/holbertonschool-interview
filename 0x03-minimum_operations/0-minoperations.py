#!/usr/bin/python3
"""Caluculate minimum number of operations to create string"""


from math import sqrt


def minOperations(n):
    """Find minimum sum of factors of number"""

    numOps = 0
    m = 2

    if n < 2:
        return 0
    for m in range(2, int(sqrt(n) + 1)):
        if (n % m == 0):
            n /= m
            numOps = numOps + m
        else:
            m += 1
    numOps += int(n)
    return numOps
