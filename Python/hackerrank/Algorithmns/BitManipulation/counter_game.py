#!/bin/python3

import math
def play_game(n):
    i = 0
    while n>1:
        if n == 2**int(math.log(n,2)):
            n =int(n/2)
        else:
            for j in range(int(n)) :
                if 2**j > n:
                    n = n - 2**(j-1)
                    break
        i += 1
    if i % 2 == 0:
        print("Richard")
    else:
        print("Louise")


T = int( input() )
for i in range(T):
    n = int( input() )
    play_game(n)
                

