# 二叉树，只有一个左节点，一个右节点，其中左节点表示他的孩子，右节点表示他的兄弟
# dp[i] 是第i个节点的最大高度
# dp[i] = max(dp[j])+lenc(child[i])

# 最大的情况是，遍历每一个子节点，找出子节点最大的那一个，然后放到左孩子的右兄弟的最先面
n = int(input())
dp = [0]*(n+1)
child = [[] for _ in range(n+1)]
for i in range(2,n+1):
    child[int(input())].append(i)
for i in range(n,0,-1):
    max_dp = 0
    for j in child[i]:
        max_dp = max(max_dp,dp[j])
    dp[i] = max_dp+len(child[i])
print(dp[1])

