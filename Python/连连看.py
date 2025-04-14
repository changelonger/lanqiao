n,m = map(int,input().split())
from collections import Counter
# a = [[i for i in list(map(int,input().split()))] for _ in range(n)]
mm = max(m,n)
a = [[0]*mm for i in range(mm)]
for i in range(n):
    l = list(map(int,input().split()))
    for j in range(m):
        a[i][j] = l[j]
# print(a)
res = 0
# 主对角线,分上下
for i in range(mm):
    x = Counter()
    y = Counter()
    for j in range(0,mm-i):
        if a[i+j][j]:
            x[a[i+j][j]]+=1
        if a[j][j+i]:
            y[a[j][j+i]]+=1
    # print(x,y)
    for v1 in x.values():
        res+=v1*(v1-1)
    for v2 in y.values():
        res+=v2*(v2-1)

# 负对角线
for i in range(mm):
    x = Counter()
    y = Counter()
    j = mm-1
    while j>=i:
        if a[mm-1-j+i][j]:
            x[a[mm-1-j+i][j]]+=1
        if a[mm-1-j][j-i]:
            y[a[mm-1-j][j-i]]+=1
        j-=1
    # print(x,y)
    if x==y:
        for v1 in x.values():
            res+=v1*(v1-1)
        continue
    for v1 in x.values():
        res+=v1*(v1-1)
    for v2 in y.values():
        res+=v2*(v2-1)
print(res)

