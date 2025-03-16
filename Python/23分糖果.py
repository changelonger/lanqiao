n,x = map(int,input().split())
s = input()
s = sorted(s)
if s[0]!=s[x-1]: # 最后一个最大，不用管
    print(s[x-1])
else:
    if s[0]==s[-1]:
        print(s[0],end = '')
        for i in range(x,n,x):
            print(s[i],end = '')
    else:# 后面并不是都一样的
        for i in s[x-1:]:
            print(i,end='')

