#!/bin/python3

def sansa_xor(arr):
    out = 0
    for i, val in enumerate(arr):
       #print("{}: {}".format(i, arr.count(i)))
        if (i + 1) % 2 == 1 and ( len(arr) - i ) % 2 == 1:
            out ^= int(val)
    return out

n = int( input() )
for i in range(n):
    s = int(input())
    arr = input().split()
    print("{}".format(sansa_xor(arr)))
