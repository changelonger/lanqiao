from collections import defaultdict
n, m = [int(x) for x in input().split()]  # 读取n和m
sq = [[0] * m for _ in range(n)]
hs = defaultdict(list)
res = 0
for i in range(n):
    x = input().split()  # 读取每一行的输入
    for j in range(m):
        sq[i][j] = int(x[j])  # 将每个字符转换成整数并赋值到二维列表中
        hs[sq[i][j]].append((i, j))
# for v in hs.values():
#     hs2 = defaultdict(int)
#     for (x,y) in v:
print(hs)