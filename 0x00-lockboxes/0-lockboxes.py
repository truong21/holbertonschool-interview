#!/usr/bin/python3
"""
Lockboxes - determine if all the boxes from 0 to n-1
can be opened
@boxes - list of boxes
Return: True if all boxes can be unlocked; False otherwise
"""


def canUnlockAll(boxes):
    if len(boxes) == 0:
        return True
    if not isinstance(boxes, list):
        return False

    key_stack = [0]
    unlocked = [1] + [0] * (len(boxes) - 1)
    while key_stack:
        p = stack.pop()
        for key in boxes[p]:
            if key > 0 and key < len(boxes) and unlocked[key] == 0:
                unlocked[key] = 1
                key_stack.append(key)

    if 0 in unlocked:
        return False
    else:
        return True
