#!/usr/bin/python3


""" contains rain function"""


def rain(walls):
    """
    Given a list of non-negative integers representing walls of width 1,
    calculates how much water will be retained after it rains.
    """
    if not walls:
        return 0
    if not isinstance(walls, list):
        return 0
    for wall in walls:
        if not isinstance(wall, int) or wall < 0:
            return 0
    water = []
    i, j = 0, 0
    while i < len(walls) and walls[i] == 0:
        i += 1
    j = i + 1
    water = rain_helper(i, j, walls, water)
    return sum(water)


def rain_helper(i, j, walls, water):
    """
    Rain helper function find the first two number that have
    zeroes in between and it counts the "rain"
    """
    if (j >= len(walls) - 1):
        return water
    if j < len(walls) and walls[j] != 0:
        return rain_helper(i + 1, j + 1, walls, water)
    while j < len(walls) and walls[j] == 0:
        j += 1
    if j == len(walls):
        return water
    width = j - i - 1
    water.append(width * walls[i])
    return rain_helper(j, j + 1, walls, water)
