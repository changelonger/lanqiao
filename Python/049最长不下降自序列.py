n,k = map(int,input().split())
a = [i for i in list(map(int,input().split()))]

# 子序列（Subsequence） 是指从一个序列（如字符串、数组或列表）中按顺序选取若干元素，不一定连续，但相对顺序保持不变的新序列。...........
dp = [[1]*2 for i in range(n)]

for i in range(1,n):
    dp[i][0] = dp[i-1][0]+1 if a[i]>=a[i-1] else 1
for i in range(n-2,-1,-1):
    # print(i,end=' ')
    dp[i][1] = dp[i+1][1]+1 if a[i]<=a[i+1] else 1
print(dp)
res = 0
l,r = 0,0
for i in range(0,n-k-1):
    if a[i]<a[i+k+1]:
        if res<dp[i][0]+k+dp[i+k+1][1]:
            res = dp[i][0]+k+dp[i+k+1][1]
            # l = i,r = i+k+1
    else:
        res = max(dp[i][0]+k,res)
print(res)
"""
10  3
1 2 5 4 3 9 5 8 3 4
"""
"""
10 3
3 9 9 9 2 8 2 2 4 6
"""
