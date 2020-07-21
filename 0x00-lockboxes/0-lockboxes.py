#!/usr/bin/python3
""" contains a function that returns whether all boxes can be opened or not"""


def canUnlockAll(boxes):
    """ checks if there is an empty list in the middle
    or the beginning of the list"""
    if type(boxes) is not list:
        return False
    if len(boxes) == 0:
        return False
    try:
        for item in boxes:
            if type(item) is not list:
                return False
        if type(boxes[0][0]) is not int:
            return False

    except IndexError:
        pass
    
    opened = [i for i in boxes[0]]
    if not opened:
        return False

    closed = [i for i in range(1, len(boxes)) if i not in opened]
    if len(boxes) == 1:
        return True


    for index in opened:
        if (index == 0):
            continue
        test_opened = opened[:]
        print("opened = " + str(opened))
        print("closed = " + str(closed))
        try:
            print("boxes[indx] = " + str(boxes[index]))
            for i in boxes[index]:
                print(i)
                if (i not in opened):
                    opened.append(i)
                try:
                    closed.remove(i)
                except ValueError:
                    pass
        except IndexError:
            pass

        if closed == []:
            print("5ater closed msakra")
            return True
        if test_opened == opened:
            print("test opened =" + str(test_opened))
            print("5ater test = opened")
            return False
