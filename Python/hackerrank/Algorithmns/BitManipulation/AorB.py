#!/bin/python3

def and_prod(inp):
    beg, end = inp[0], inp[1]
    out = beg & end
    i, k = beg + 1, 1
    while i < end:
        out &= i
        k *= 2
        i += k
    return out


Q = int(input())
for i in range(n):
    K = int(input())
    A = int(input(), 16)
    B = int(input(), 16)
    C = int(input(), 16)

