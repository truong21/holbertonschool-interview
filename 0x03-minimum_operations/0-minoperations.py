#!/usr/bin/python3
"""
Function: calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    oper = []
    i = 2
    while n > 1:
        while n % i == 0:
            oper.append(i)
            n = n / i
        i += 1
    return sum(oper)
