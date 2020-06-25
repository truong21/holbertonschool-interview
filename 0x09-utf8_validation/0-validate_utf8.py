#!/usr/bin/python3


def validUTF8(data):
    num = 0
    for n in data:
        mask = 1 << 7
        if not num:
            while mask & n:
                num += 1
                mask >>= 1
        if not num:
            continue
        if num == 1 or num > 4:
            return False
        else:
            if n >> 6 != 0b10:
                return False
        num -= 1
    return num == 0
