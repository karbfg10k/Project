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


n = int( input() )
for i in range(n):
    arr = [int(i) for i in input().split() ]
    print("{}".format(and_prod(arr)));

