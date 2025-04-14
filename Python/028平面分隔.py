# 1000个线 ，平方6次可以
# 地推公式是区域= 1+直线数+交点数
from collections import Counter
n = int(input())
line = [list(map(int,input().split())) for _ in range(n)]
point = Counter()
cnt = 0
for i in range(n-1):
    for j in range(i+1,n):
        a1,b1 = line[i]
        a2,b2 = line[j]
        if a1==a2:
            continue
        else:
            x = -(b1-b2)/(a1-a2)
            y = a1*x+b1
            point[(x,y)] +=1
            if point[(x,y)]==2:
                res+=1
print(len(point)+n+1+res)