from collections import Counter
n  = 100
a = Counter()
b = []
b.append(2)
b.append(3)
for i in range(4,n+1):
    flag = True
    for j in range(2,int(i**0.5)+1):
        if i%j==0:
            flag = False
            break
    if flag:
        b.append(i)

# print(b)
for i in range(2,n+1):
    temp = i
    # print(temp)
    j = 0
    while temp>=2 and j<len(b):
        # print(b[j])
        if temp%b[j]==0:
            temp/=b[j]
            a[b[j]]+=1
            j = 0
        else:
            j+=1
# print(a.items())
res = 1
for i in a.values():
    res*=i+1
print(res)