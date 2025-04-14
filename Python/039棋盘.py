
# 二维数组前缀和和差分
n,m = list(map(int,input().split()))
d = [[0]*(n+2) for _ in range(n+1)]  # 差分数组
for i in range(m):
    x1,y1,x2,y2 = list(map(int,input().split()))
    d[x1][y1] += 1
    d[x1][y2+1] -= 1 # 防止超出y2
    d[x2+1][y1] -= 1 # 防止超出x2
    d[x2+1][y2+1] += 1 # 重叠部分
for i in range(1,n+1):
    for j in range(1,n+1):
        d[i][j] = (d[i][j]+d[i-1][j]+d[i][j-1]-d[i-1][j-1])%2
        print(d[i][j],end = '')
    print('\n',end = '')
