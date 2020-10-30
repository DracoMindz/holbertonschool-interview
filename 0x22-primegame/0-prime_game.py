#!/usr/bin/python3
"""
Prime Game
"""


def countPrimeIn_list(numlist):
    """
    Count the number of prime numbers in list
    :param nums: list of integers
    :return: number of neg integers
    """

    primeCount = []

    for number in numlist:
        if number == 2:
            primeCount.append(number)
        elif number >= 2:
            prime = True
            for index in range(2, number):
                if number % index == 0:
                    prime = False
                    break
            if prime:
                primeCount.append(number)
    return len(primeCount)


def isWinner(x, nums):
    """
    Determine the winner of each game
    :param x: num of rounds
    :param nums: array of  ints >= n
    :param n: numbers
    :return: the Winner of the round
    """
    primeNums = countPrimeIn_list(nums)
    if primeNums == 0:
        return None
    if primeNums >= 1:
        if primeNums % 2 == 1:
            return "Maria"
        else:
            return "Ben"
