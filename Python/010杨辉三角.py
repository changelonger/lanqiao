# 杨辉三角对称，只需看左半边
# 每行最大的数为 C(n, n // 2)，当n取33时有C(n, n // 2) > 1000000000
# 因此只需考虑0到33行
# 斜着看，会发现是递增序列，横着看，是严格递增序列
# 因此，如果在越里面的斜行中出现，则不会在外面的斜行中出现
# 需要从内向外搜索
def C(n, m):
  up = 1; down = 1
  t = n
  for i in range(1, min(m, n - m) + 1):
    up *= t; t -= 1
    down *= i
  return up // down

n = int(input())

def search(i):
  l = i; r = max(n, l); k = i // 2
  while l < r:
    mid = l + r >> 1
    if C(mid, k) < n: l = mid + 1
    else: r = mid
  return l

for i in range(34, -1, -2):
  t = search(i)
  if C(t, i // 2) == n:
    print(t * (t + 1) // 2 + i // 2 + 1)
    break