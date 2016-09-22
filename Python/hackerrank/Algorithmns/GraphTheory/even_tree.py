#!/bin/python3
from collections import defaultdict

n, m = input().strip().split(' ')
n, m = [int(n), int(m)]
arr = []
for i in range(m):
    k = input().strip().split(' ')
    arr.append( ( int(k[0]), int(k[1]) ) )

tree = defaultdict(list)
for i, j in arr:
    tree[j].append(i)
print("{}".format(tree))

def dfs_iter(graph, root):
    visited = []
    stack = [root, ]
    
    while stack:
        node = stack.pop()
        
        if node not in visited:
            visited.append(node)
            stack.extend([x for x in graph[node] if x not in visited])
    return visited
ctr = 0
b = []
for a in tree:
    b.append(a)
for a in b:
    if len(dfs_iter(tree,a)) % 2 ==0:
        ctr += 1
print(ctr-1)
