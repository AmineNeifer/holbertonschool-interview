#!/usr/bin/python3


""" function minimum operations"""


def minOperations(n):
    """ Return min number of operations needed copy paste and get n number of Hs"""
    count = 0
    s = "H"
    wanted = s * n
    if n < 2 or type(n) is not int:
        return 0
    while len(s) < n:
        if n % len(s) == 0:
            s = s * 2
            count += 2
            prev = s
        else:
            s = s + prev
            count += 1
    return count
