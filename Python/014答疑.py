
"""
假设同学 i 进入办公室的时间于解答时间的和为 Ai , 离开办公室的时间为 Bi
对于同学 1 与同学 2 而言，所用时间为：
A1, B1
A2, B2
若同学 1 先进教室，则答案为 ans1 = (A1) + (A1 + B1 + A2)
若同学 2 先进教室，则答案为 ans2 = (A2) + (A2 + B2 + A1)
可以发现 ans1 与 ans2 的关系等同于 (A1 + B1) 与 (A2 + B2) 的关系
所以：每名同学进入教室的优先级只与其所消耗的时间和有关，和越小，优先级越高
"""
n = int(input())
data = []
s= []
for i in range(n):
    data.append(list(map(int,input().split())))
    s.append([sum(data[i]),data[i][0]+data[i][1]])
ans = 0
start = 0
for x in sorted(s):
    ans+=start+x[1]
    start+=x[0]
print(ans)
