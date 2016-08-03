#!/bin/python3

import sys
var, out_arr = [], []
inp = input().strip()

for i in inp.split():
    var.append(int (i) )

in_arr = input().strip();

for i in in_arr.split():
    out_arr.append(i)

n, k, q = var[0], var[1], var[2]
k = k%n
for i in range(q):
    temp = input().strip()
    temp = int(temp)
    index = 0
    if temp >= k:
        index = temp - k
    else:
        index = temp - k + n
    print("{}".format(out_arr[index]) )


