#!/bin/python3

import sys

fr = int( input() )
to = int( input() )
max_xor = 0
out = []
for i in range(fr, to+1):
    for j in range(fr, to+1):
        print("i: {}, j: {}".format(i, j))
        if i == j:
            continue
        else:
            if max_xor  < i^j:
                max_xor = i^j
print("{}".format(max_xor))
                

