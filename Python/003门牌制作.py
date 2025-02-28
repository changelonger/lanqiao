n = 2020
cnt = 0
for i in range(1,n+1):
    x = i
    while(x):
        if x%10 ==2:
           cnt+=1
        x = x//10 # x/=10会变成浮点数
print(cnt)