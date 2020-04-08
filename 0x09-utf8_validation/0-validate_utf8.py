#!/usr/bin/env python3
"""
Write a method determines
if a given data set represents valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    method determines valid UTF-8 encoding
    """
    mask_utf8 = [0x0, 0x80, 0xE0, 0xF0, 0xF8]
    b = [0x0, 0x80, 0xE0, 0xF0, 0xF8]
    m = 0

    while data:
        for m in (4, 3, 2, 1):
            if data[0] & mask_utf8[m] == b[m]:
                break
        if m == 0 or m > 4:
            return False
        for n in range(1, m):
            if data[n] & 0xC0 != 0x80:
                return False
        data = data[m:]
    return True
