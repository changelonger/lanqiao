n = 16
res = 0
m = [[0]*4 for i in range(4)]
direction = [[1, 0], [0, 1], [-1, 0], [0, -1]]  # 4 个方向
def dfs(x,y,num):
    m[x][y]=1
    global res
    if num==n:
        res+=1
        m[x][y]=0
        return
    for i in range(4):
        dx = x+direction[i][0]
        dy = y+direction[i][1]
        if dx>=0 and dy>=0 and dx<4 and dy<4 and m[dx][dy]==0:
            dfs(dx,dy,num+1)
    m[x][y]=0
for i in range(4):
    for j in range(4):
        dfs(i,j,1)
print(res)