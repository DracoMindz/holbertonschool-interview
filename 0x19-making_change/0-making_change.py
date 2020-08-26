#!/usr/bin/python3
"""
Function will return fewest number of coins to make total
"""


def makeChange(coins, total):
    """
    function calculates the minimum number of coins to match total
    :param coins: array of coins to be used
    :param total: amount coins should match
    :return: minimun num of coins to match total
    """
    count = 0
    coin = 0
    if total <= 0:
        return 0
    if coins is None:
        return -1
    if coins == []:
        return -1

    coinsList = sorted(coins, reverse=True)
    while coin < len(coinsList):
        num = total // coinsList[coin]
        count += num
        total -= coinsList[coin] * num
        coin += 1

        if total == 0:
            return count
    return -1
