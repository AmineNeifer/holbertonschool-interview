#!/usr/bin/python3
"""
Contains island_perimeter function.
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid.
    """
    somme = 0
    rows = len(grid)
    cols = len(grid[0])
    for i in range(rows):
        for j in range(cols):
            num = 0
            if grid[i][j] == 1:

                if i == 0:
                    num += 1
                elif grid[i - 1][j] == 0:
                    num += 1

                if j == 0:
                    num += 1
                elif grid[i][j - 1] == 0:
                    num += 1

                try:
                    if grid[i + 1][j] == 0:
                        num += 1
                except IndexError:
                    num += 1

                try:
                    if grid[i][j + 1] == 0:
                        num += 1
                except IndexError:
                    num += 1

            somme += num
    return somme
