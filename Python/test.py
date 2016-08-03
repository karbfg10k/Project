#!/bin/python3

import sys


n = int(input().strip())
a = []
for a_i in range(n):
    a_t = [int(a_temp) for a_temp in input().strip().split(' ')]
    a.append(a_t)
sum = 0
for i in range(n):
    sum = sum + a[i][i] - a[i][n-i-1]
print("{}".format( abs(sum)))
