# 题目要找n的最大值，其实如果m不满足，那么m+1也不满足
from collections import defaultdict
M = defaultdict(int)
n=int(input())
A = list(map(int,input().split()))
A = sorted(A)
for i in A:
    M[i]+=1
m = A[0]
while True:
    x = M[m]
    if x%(m+1)==0:
        M[m+1] += x//(m+1)
        m+=1
    else:
        break
print(m)
"""
sum = a!*x+(a+1)!*y
显然,(a+1)!y // a!*x == 0
if s//(a+1)!==0
then (a!*x+(a+1)!*y) //(a+1)!=0
then a!*x//(a+1)!==0
then x//(a+1)==0   
else  x = m
"""