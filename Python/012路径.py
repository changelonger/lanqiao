import os
import sys
import math

# 请在此输入您的代码
# 求最大公约数用辗转相除法（欧几里得算法）
def gcd(a,b):
  if b==0:
    return a
  return gcd(b,a%b)
def gbs(a,b):  #求最小公倍数
  return a*b//(gcd(a,b))
lst = [float('inf')]*(2021+1)
lst[1] = 0 # 节点从1开始
for i in range(1, 2022):  # 节点从1开始
  for j in range(i + 1, i + 22):
    if j > 2021:   # 跳出循环
      break
    lst[j] = min(lst[j], lst[i] + gbs(i, j))
print(lst[2021])
# list[j] 是1号点到j号点的最短路径
# lst[j] = min(lst[j], lst[i] + gbs(i, j)),找到最小值