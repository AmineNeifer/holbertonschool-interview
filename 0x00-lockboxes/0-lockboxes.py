#!/usr/bin/python3
""" contains a function that returns whether all boxes can be opened or not"""


def canUnlockAll(boxes):
    """ checks if there is an empty list in the middle
    or the beginning of the list"""
    if boxes is not list:
        return False
    for i in boxes:
        if i is not list:
            return False
    opened = [i for i in boxes[0]]
    closed = [i for i in range(1, len(boxes)) if i not in opened]
    if len(boxes) == 1:
        return True
    while True:
        for index in opened:
            test_opened = opened[:]
            for i in boxes[index]:
                if (i not in opened):
                    opened.append(i)
                try:
                    closed.remove(i)
                except ValueError:
                    pass
            if closed == []:
                return True
            if test_opened == opened:
                return False
