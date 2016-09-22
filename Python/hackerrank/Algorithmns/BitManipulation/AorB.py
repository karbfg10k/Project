#!/bin/python3

def bitsoncount(x): 
    b=0
    while(x > 0):
        x &= x - 1   
        b+=1
    return b

def mask_calc(A, B, C, K):
    (amask, bmask) = (A & ~C, B & ~C)

    if bitsoncount(amask) + bitsoncount(bmask) > K:
        print("{}".format(-1))
        return

    temp_mask = C & ( (A ^ amask) | (B ^ bmask) ) 
   
    if bitsoncount(temp_mask) > K:
        print("{}".format(-1))
        return

    amask = amask | temp_mask
    
    temp_mask = (A ^ amask) | (~ (B ^ bmask))
    
    (amask, bmask) = (amask ^ temp_mask, bmask ^ temp_mask )
    print("A':{}, B':{}".format(amask,bmask))

n = int(input())
for i in range(n):
    K = int(input())
    A = int(input(), 16)
    B = int(input(), 16)
    C = int(input(), 16)
    mask_calc(A, B, C, K)

