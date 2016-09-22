#!/bin/python3
n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
arr = [int(a) for a in input().strip().split(' ')]

pair = 0
for i, val in enumerate(arr):
    for j, j_val in enumerate(arr):
        if j > i:
            if ( j_val + val ) % k == 0:
                pair += 1
        else:
            continue

print("{}".format(pair))

