#!/usr/bin/python3

n = int(input().strip())
str_list = []
for i in range(n):
    inp = input().strip()
    str_list.append(inp)

q = int(input().strip())
for i in range(q):
    inp = input().strip()
    print("{}".format(str_list.count(inp)))

