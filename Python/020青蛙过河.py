n,x  = map(int,input().split())
h = list(map(int,input().split()))

# 青蛙能跳n+1个石头,就不跳n个石头。为什么呢?
# 首先,河岸 1 2 3 4 5 6 7 8 9 河岸
# 首先，坑定是先跳尽量少的石头，因为后面还需要继续跳,所以需要跳大点
# 换一个说法，在我跳跃的范围之内，石头的高度大于等于2*x,这不就代表我可以跳一个来回吗
# 因此需要先求前缀和
h_sum = [0]*n
for i in range(1,n):
    h_sum[i] = h_sum[i-1]+h[i-1]
left = 1
right = n
def check(y):
    # 这里的y就是Mid也就是步长
    # 遍历过程是，从第0个石头开始，最后一个石头是什么呢？ 末尾的石头是n-1,所以我们直接调到岸上就是n-1+y，从这里可以直接调到岸上
    for i in range(n-y):
        if h_sum[i+y]-h_sum[i]<2*x:
            return False
    return True

res = 0
while left<=right:
    mid = left+(right-left)//2
    if check(mid):
        res = mid
        right = mid-1
    else:
        left = mid+1
    # print(left,right)
print(res)
