#!/usr/bin/python3
"""
Write a method determines
if a given data set represents valid UTF-8 encoding
"""


def validUTF8(data):
    """
    method determines valid UTF-8 encoding
    """
    index = 0
    for i, m in enumerate(data):
        mask = m & 0xFF
        if (index == 0):
            while( 1 << abs(7 - index)) & mask:
                index += 1
            if index == 1 or index > 4:
                return False
        elif index > 0:
            if (m >> 6) != 0b10:
                return False
            index -= 1
    return True
