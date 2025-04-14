import os
import sys

# 请在此输入您的代码
# t = 1    1
# t = 2    1,2 10
# t = 3    1,2,3,9,10
# t = 4    1,2 3 4 8 9 10
# t = 5    1 2 3 4 5 6 7 8 9 10

# 9次方，只能2分查找
n, L = list(map(int,input().split()))
ll = [0]*n  # 改为n长度
s = [0]*n
for i in range(n):  # 从0开始
    ll[i], s[i] = list(map(int,input().split()))


# 二分查找方法，因为是找最小值，所以可以查出来的话
def check(t): 
    # 可以的情况是什么？
    # 所有的水管都已经检测到了
    # 又因为len的级数是10的9次方
    # 所以检查不可能一个一个的查
    # 考虑二分？但是是无序的，所以不能二分
    # 现在怎么办
    # 先把每一个阀门对应的区间给存起来
    # 然后按照第一个排序，
    # 这样得到了一个n*2的二维列表，然后进行迭代，如果新的列表第一个元素<=最远距离+1，代表又重叠，取最大部分就可以了
    a = []
    for i in range(n):  # 从0开始
        a.append([ll[i]-(t-s[i]), ll[i]+(t-s[i])])
    a.sort()
    if a[0][0]>1:
        return False
    r = a[0][1]
    for i in range(n):
        if a[i][0]<=r+1:  # 举例，比如1，2，3  4，5.三是最远，4是端点再大就不行了
            r = max(r,a[i][1])
        else:
            break
    return r>=L

        
l,r = 0,10**11
while l<r:
    mid = l+(r-l)//2
    if check(mid):   # 可以
        r = mid
    else:
        l = mid+1
print(l)