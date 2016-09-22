#!/bin/python3



Q = int(input())
for i in range(Q):
    num = int(input().strip())
    print("{}".format(~num + 2**32))
