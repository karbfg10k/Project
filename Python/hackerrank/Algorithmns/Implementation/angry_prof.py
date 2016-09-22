#!/bin/python3

def on_time(num):
    return 0 >= num

t = int(input().strip())
for a0 in range(t):
    n,k = input().strip().split(' ')
    n,k = [int(n),int(k)]
    a = [int(a_temp) for a_temp in input().strip().split(' ')]
    b = list(filter(on_time, a))
    if len(b) < k:
        print("YES")
    else:
        print("NO")
