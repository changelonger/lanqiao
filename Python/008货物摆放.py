import os
import sys
# 因素+背包（求因子）+遍历
# 不到50毫秒！！！！！！！！！！
# 请在此输入您的代码
n=2021041820210418
l=[]     # ！！！！用于存因数不是因子例如：10=2*5
i=2
x=n
while i<pow(x+1,0.5):
    if x%i==0:
        l.append(i)
        x=x//i
    else:
        i+=1
l.append(x)
s=set()     # ！！！！用于存因子 如10=1*2*5*10
s.add(1)
for j in l:
    p=set()
    for k in s:
        p.add(j*k)
    for k in p:
        s.add(k)
count=0
for k1 in s:             # 遍历两层求解
    for k2 in s:
        if n%(k1*k2)==0:
            count+=1
print(count)