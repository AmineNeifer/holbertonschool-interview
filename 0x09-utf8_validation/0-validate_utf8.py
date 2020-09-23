#!/usr/bin/python3


""" contains a function to validate UTF8 encoding"""


def validUTF8(data):
    """
      0   0   0   0   0  0  0  0
    128  64  32  16   8  4  2  1
    """
    i = 0
    for byte in data:
        if byte > 247:
            return False
    while i < len(data):
        if data[i] < 128:
            i += 1
        elif data[i] >= 240:
            i += 1
            try:
                for j in range(3):
                    i += j
                    if not (128 <= data[i + j] <= 191):
                        return False
            except IndexError:
                return False
        elif data[i] >= 224:
            i += 1
            try:
                for j in range(2):
                    i += j
                    if not (128 <= data[i + j] <= 191):
                        return False
            except IndexError:
                return False
        elif data[i] >= 192:
            i += 1
            try:
                if not (128 <= data[i] <= 191):
                    return False
            except IndexError:
                return False
    return True
