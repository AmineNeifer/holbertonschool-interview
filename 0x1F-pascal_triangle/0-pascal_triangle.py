#!/usr/bin/python3
"""
Contains pascal_triangle function
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing the Pascal’s triangle of n
    """
    init = []
    if n <= 0:
        return []
    for i in range(1, n + 1):
        lis = [1 for x in range(i)]
        init.append(lis)
        if i > 2:
            for k in range(1, len(init[i - 1])):
                try:
                    init[i - 1][k] = init[i - 2][k] + init[i - 2][k - 1]
                except IndexError:
                    pass
    return init
