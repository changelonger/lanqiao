import os
import sys

t = int(input())

for _ in range(t):
    # 第k个结点的子节点范围为[k*m-m+2,k*m+1]
    n,m,k = map(int,input().split())
    l=k   # 表示子节点的左端点 
    r=k   # 表示子节点的右端点
    ans = 1   # 记录总的结点的数量
    res = 1   # 记录每一层子结点的数量
    while r*m+1 <=n:  # 如果子节点最右端小于n  说明没到尽头
        res *= m      # 计算出这一层的所有子节点数目
        l = l*m-m+2   # 更新左端点
        r = r*m+1     # 更新右端点
        ans +=res     # 更新总端点数目
    l=l*m-m+2 # 最后一层最左端点
    ans+=max(0,n-l+1)  # 最后一层最右端点就是n，直接用n-l+1计算出这层的结点数量
    print(ans)
 