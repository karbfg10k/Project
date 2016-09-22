#!/bin/python3
import sys

x1, v1, x2, v2 = input().strip().split(' ')
x1, v1, x2, v2 = [int(x1), int(v1), int(x2), int(v2)]

res = "NO"
if x2 > x1 and v2 >= v1:
    print("{}".format(res))
    sys.exit(0)
elif x1 > x2 and v1 >= v2:
    print("{}".format(res))
    sys.exit(0)

# solve for k and see if it is a whole number, x1 +v1*k = x2 + v2*k

if (x1 - x2) % (v2-v1) == 0:
    print("YES")
else:
    print("NO")
sys.exit(0)


