#!/bin/python3

def sort_ret(arr):
    ctr = 0
    S = False
    for i in range(len(arr)-1):
        for j in range(len(arr)-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                ctr += 1
                s = True
        if s:
            s = False
        else:
            break
    return ctr
            

t = int(input().strip())
for l in range(t):
    x = int(input().strip())
    arr = [int(a) for a in input().strip().split(' ')]
    flag = False
    sort = 0
    for i, val in enumerate(arr):
        if (val - 1 - i )  > 2:
            #print("val:{}, i:{}, calc: {}".format(val, i,((val - 2 - i) % 2) ))
            print("Too chaotic")
            flag = True
            break
    if flag:
        continue
    else:
        print("{}".format(sort_ret(arr)))
