#!/usr/bin/python3
"""
Script reads stdin line by line and computes metrics
"""

import sys

totalSize = [0]
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
counter = 0


def code_match(line):
    """
    match code to Status_codes
    """
    try:
        line = line[:-1]
        lineWords = line.split(" ")
        totalSize[0] += int(lineWords[-1])
        codenum = int(lineWords[-2])
        if codenum in status_codes:
            status_codes[codenum] += 1
    except Exception:
        pass


def print_stats():
    """
    print stats
    """
    print("Total file size: {}".format(totalSize[0]))
    for m in sorted(status_codes.keys()):
        if status_codes[m] != 0:
            print("{}: {}".format(m, status_codes[m]))


try:
    for line in sys.stdin:
        code_match(line)
        if counter % 10 == 0:
            print_stats()
        counter += 1
except Exception:
    print_stats()
    raise

print_stats()
