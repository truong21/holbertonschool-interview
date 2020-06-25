#!/usr/bin/python3
def validUTF8(data):
    count = 0
    for num in data:
        mask = 0b10000000
        if not count:
            while (mask & num):
                count += 1
                mask >>= 1
            if count > 4:
                return False
            if count:
                count -= 1
                if count == 0:
                    return False
        elif count > 0:
            if num >> 6 != 2:
                return False
            count -= 1
    return not count
