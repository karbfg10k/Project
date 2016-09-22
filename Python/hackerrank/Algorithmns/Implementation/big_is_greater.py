#!/bin/python3

t = int(input().strip())
for a0 in range(t):
    str_list = list(input().strip())    

    #reverse
    i = len(str_list) - 1
    while i > 0 and str_list[i - 1] >= str_list[i]:
        i -= 1
    if i <= 0:
        print("no answer")
        continue
    # Find successor to pivot
    j = len(str_list) - 1
    while str_list[j] <= str_list[i - 1]:
        j -= 1
    str_list[i - 1], str_list[j] = str_list[j], str_list[i - 1]
     
    # Reverse suffix
    str_list[i : ] = str_list[len(str_list) - 1 : i - 1 : -1]
    print("{}".format("".join(str_list)))
