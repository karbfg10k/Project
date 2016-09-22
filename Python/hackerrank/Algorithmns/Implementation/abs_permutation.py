#!/bin/python3

t = int(input().strip())
for i in range(t):
    n, k = input().strip().split(' ')
    n,k = [int(n), int(k)]
    arr = [i for i in range(1, n+1)]
    if k == 0:
        print(" ".join(str(i) for i in arr))
    else:
        if n % (2*k) == 0:
            for i in range(0, int(n/(2*k)) ):
                for j in range(1, k+1):
                    arr[i*2*k+j-1], arr[i*2*k+j+k-1] = arr[i*2*k+j+k-1], arr[i*2*k+j-1]
            print(" ".join(str(i) for i in arr))
        else:
            print("-1")

