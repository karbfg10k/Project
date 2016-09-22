#!/bin/python3

n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
arr = [int(a) for a in input().strip().split(' ')]
S = [0] * k
# get remainder
for i in arr:
    S[i%k] += 1

res = 0
for i in range(1, (k+1)//2 ):
    res += max(S[i], S[k-i])
if S[0]:
    res += 1
if S[k//2] and k % 2 ==0:
    res += 1
print("{}".format(res))

