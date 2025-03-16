

# 这个题的意思是，事情回全部发生，但是，顺序不固定
# 所以先计算出某个事件中三个国家差值，然后按照递减排序排序
# 进行循环，同一个i对应三个国家顺序事件不一样
# 所以知道三个国家中有任意一个符合条件即可，注意事件从1开始
n = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))
newA = sorted([A[i]-B[i]-C[i] for i in range(n)],reverse = True)
newB = sorted([B[i]-A[i]-C[i] for i in range(n)],reverse = True)
newC = sorted([C[i]-B[i]-A[i] for i in range(n)],reverse = True)
a,b,c ,res= 0,0,0,-1
for i in range(n):
    a+=newA[i]
    b+=newB[i]
    c+=newC[i]
    if a>0 or b>0 or c>0:
        res = i+1
print(res)
