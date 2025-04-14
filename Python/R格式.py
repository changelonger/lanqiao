n,d = map(float,input().split())
n = int(n)
d = str(d)
a = 1
for i in range(n):
    a*=2
s = str(a)
l = 0
for i in range(0,len(d)):
    if d[i]=='.':
        l = len(d)-i-1
        break   # 获得小数点的位数
res = 0
print(s,d)
for i in range(len(s)-1,-1,-1):
    flag = 0
    for j in range(len(d)-1,-1,-1):
        # print(s[i],d[j])
        if d[j]=='.':
            flag = 1
            continue
        print(int(s[i]),int(d[j]),10**(len(s)-i-1),(10**(len(d)-j-flag-1)))
        res+=int(s[i])*int(d[j])*(10**(len(s)-i-1))*(10**(len(d)-j-flag-1))
res/=10**l
res = int(res) if res-int(res)<0.5 else int(res)+1
print(res)