import os
import sys
# 放弃

MOD = 10 ** 9 + 7

# 定义 dp[i][j] 为 前 i 个 右括号 填入了 j 个 左括号   j 的范围为 补全前 i 个右括号需要的左括号数 ~ 总共需要的左括号数
# dp[i][j] = dp[i-1][k]   k 的范围为 补全前 i - 1 个右括号需要的左括号数 ~ j


def slove(s: str):

  nums = [0] * (len(s) + 1)  # 记录每个右括号需要多少个左括号
  left_cnt, right_cnt, cnt = 0, 0, 0

  for v in s:
    if v == '(':
      left_cnt += 1
    else:
      right_cnt += 1
      if left_cnt:
        left_cnt -= 1
        right_cnt -= 1
      cnt += 1
      nums[cnt] = right_cnt
  
  dp = [[0] * (right_cnt + 1) for _ in range(cnt + 1)]
  dp[0][0] = 1  

  for i in range(1, cnt + 1):
    total = 0
    for j in range(nums[i - 1], nums[i]):
      total += dp[i-1][j]
      total %= MOD
    for j in range(nums[i], right_cnt + 1):
      total += dp[i-1][j]
      total %= MOD
      dp[i][j] = total
  
  return dp[-1][-1]


def reverse(s: str):
  return "".join([')' if v == '(' else "(" for v in s[::-1]])


s = input()
res1 = slove(s)
res2 = slove(reverse(s))
print(res1 * res2 % MOD)