#!/usr/bin/python3
def validUTF8(data):
    """
      0   0   0   0   0  0  0  0
    128  64  32  16   8  4  2  1
    """
    i = 0
    while i < len(data):
        if data[i] < 128:
            i += 1
        elif data[i] >= 248:
            return False
        elif data[i] >= 240:
            i += 1
            for j in range(3):
                i += j
                if not (128 <= data[i + j] <= 191):
                    return False
        elif data[i] >= 224:
            i += 1
            for j in range(2):
                i += j
                if not (128 <= data[i + j] <= 191):
                    return False
        elif data[i] >= 192:
            i += 1
            if not (128 <= data[i] <= 191):
                return False
    return True
