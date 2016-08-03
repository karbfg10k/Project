#!/bin/python3

import sys

n = int( input() )
arr = [int(i) for i in input().split() ]
for i in arr:
    if arr.count(i) == 1:
        print("{}".format(i))
        sys.exit(0)


