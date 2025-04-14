n, m, a, b = map(int, input().split())
w = [list(map(int, input().split())) for _ in range(n)]
mod = 998244353

def get_max(arr, l):
    if l <= 0 or l > len(arr):
        return []
    q = []
    res = []
    for i in range(len(arr)):
        if q and q[0] <= i - l:
            q.pop(0)
        while q and arr[q[-1]] <= arr[i]:
            q.pop()
        q.append(i)
        if i >= l - 1:
            res.append(arr[q[0]])
    return res

def get_min(arr, l):
    if l <= 0 or l > len(arr):
        return []
    q = []
    res = []
    for i in range(len(arr)):
        if q and q[0] <= i - l:
            q.pop(0)
        while q and arr[q[-1]] >= arr[i]:
            q.pop()
        q.append(i)
        if i >= l - 1:  # 修正条件：i >= l-1
            res.append(arr[q[0]])
    return res

# 计算每行的滑动窗口最大值和最小值
b_max = [get_max(row, b) for row in w]  # 每行的窗口最大值
b_min = [get_min(row, b) for row in w]  # 每行的窗口最小值

# 检查所有行的结果长度是否一致
if any(len(row) != len(b_max[0]) for row in b_max + b_min):
    print("Error: 各行滑动窗口结果长度不一致，无法转置")
    exit()

# 转置行列
tb_max = list(zip(*b_max))  # 转置为列方向
tb_min = list(zip(*b_min))

# 对转置后的每列计算滑动窗口最大值和最小值
res_max = [get_max(col, a) for col in tb_max]  # 每列的窗口最大值
res_min = [get_min(col, a) for col in tb_min]  # 每列的窗口最小值

# 计算最终结果
res = 0
for i in range(len(res_max)):
    for j in range(len(res_max[i])):
        res = (res + res_max[i][j] * res_min[i][j]) % mod
print(res)