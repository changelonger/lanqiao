import os
import sys
# 请在此输入您的代码
res = 0
for i in range(1,2025):
    two = 0
    four = 0
    x ,y= i,i
    while x:
        two += x%2
        x//=2
    while y:
        four+=y%4
        y//=4
    if two==four:
        res+=1
        print(i,two,four)
print(res)
# 注意，python整除是//，以后提交代码前，看看和自己想的一样吗


