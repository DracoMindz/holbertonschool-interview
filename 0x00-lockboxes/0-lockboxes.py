#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """
    Can all boxes be opened
    """
    for box_num in range(1, len(boxes) - 1):
        for value in range(len(boxes)):
            closed = box_num in boxes[value] and box_num != value
            if closed:
                break
        if closed is False:
            return False
    return True
