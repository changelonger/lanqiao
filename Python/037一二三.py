maxn = 2000000 # 最大只需要10的6次方多，开二倍
a = [0]*maxn
s = [0]*maxn

t = int(input())
def pre_sum(i):  # 注意！我们要查找的是满足小于等于的！
    l,r = 0,maxn  # 因为又l-1所以初始项包括0
    while l<r:
        mid = (l+r+1)//2
        # print(l,r,mid,a[mid],i)
        if a[mid]>i:
            r = mid-1
        else:
            l = mid # 左对齐，那就偏右更新
    # 现在l和r是相等的
    # print(l,s[l],a[i-a[l]])
    # print(s[l]+a[i-a[l]])
    return s[l]+a[i-a[l]]
for i in range(1,maxn):
    a[i] = a[i-1]+i
    s[i]=s[i-1]+a[i]
# print(a)
for i in range(t):
    l,r = map(int,input().split())
    print(pre_sum(r)-pre_sum(l-1))    # pre_sum是求到第i个数的和 ,第L个数，所以是从l-1到r,l-1算不到


# i     1   1 2   1 2 3   1 2 3 4   1 2 3 4 5   1 2 3 4 5 6   1 2 3 4 5 6 7
# a[i]  1   3     6       10        15          21            28
# s[i]  1   4     10      20        35          56            84

# 假如，给我一个12，一个19，然我找这些的和
# 我可以先找到前12个数的和，在找前19个数的和
# 可以发现，10的12次方，只能二分法求解，现在的问题是怎么用二分法去求前n个数的和
# 观察发现，a[i]的值表示到i一共有多少项求和，比如a[1]表示1项，a2表示3项，a[3]表示6项，a[4]表示10项
# 所以要找到max i, a[i]<=12,这个i对应的就是到12前面那一组有多少项
# 特殊值，a[i]==12，这时候怎么处理，直接返回s[i]就可以了
# 所以用二分从0,到maxn中查a[i]<=12的最大值 # 从1开始
# 所以前缀和是  s[i]+a[12-a[i]]