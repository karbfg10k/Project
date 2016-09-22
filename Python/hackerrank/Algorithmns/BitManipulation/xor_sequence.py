#!/bin/python3


"""
def xor_seq(num):
    if num % 4 == 0:
        return num 
    if num % 1 == 0:
        return 1 
    if num % 2 == 0:
        return num + 1 
    if num % 3 == 0:
        return 0
    return 0


def generate(beg, end):
    out = []
    if end - beg > 8:
        beg = out - 8
        while beg % 8 == 0:
            beg
    return out
"""
def xor(num):
    res = 0	
    for i in range(0, ((num+1)%8), 2):
        res ^= num - i
    print("num:{}, res:{}".format((num+1)%8,res))
    return res

Q = int(input())
for i in range(Q):
    L,R = input().strip().split(' ')
    L,R = [int(L),int(R)]
    print("{}".format(xor(L-1) ^ xor(R) ))
