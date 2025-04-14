import math
m = [[0]*22 for _ in range(22)]
for i in range(1,22):
    for j in range(1,22):
        if math.gcd(i,j) ==1:
            m[i][j]=1
# 所有的都和1互质 所以都可以到达1，可以试一下dfs
v = [0]*22
res = 0
def dfs(i,n):
    global res
    if n==21:
        res+=1
        if res%1000000==0:
            print(res)
    v[i] = 1
    for j in range(1,22):
        if v[j]==0 and m[i][j]==1:
            dfs(j,n+1)
    v[i] = 0
dfs(1,1)
print(res)
# 待会去写，这道题暴力不通过，只能dp
