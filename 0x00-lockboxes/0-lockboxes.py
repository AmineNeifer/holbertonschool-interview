#!/usr/bin/env python3
""" contains a function that returns whether all boxes can be opened or not"""


def canUnlockAll(boxes):
    """ checks if there is an empty list in the middle
    or the beginning of the list"""
    for i in range(len(boxes)):
        if not boxes[i] and i < len(boxes) - 1:
            return False
    return True
