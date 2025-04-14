from collections import defaultdict
n = int(input())
d = defaultdict(list)
l = {}
for i in range(n):
    a,b = map(int,input().split())
    d[a].append(b)
for i in d.keys():
    d[i].sort()
    l[i] = len(d[i])
res = 0
for i in d.keys():
    if l[i]>n//10:
        res+=sum(d[i][0:l[i]-n//10])

print(res)
"""
10
1 1
1 3
1 2
2 4
2 5
2 6
3 7
3 8
3 9
4 10
"""