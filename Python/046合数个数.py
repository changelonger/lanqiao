import math
res = 0
for i in range(4,2021):
    flag = False
    for j in range(2,int(math.sqrt(i))+1):
        if i%j==0:
            flag = True
    if flag:
        # print(i,end=' ')
        res+=1
print(res)



count=0
for i in range(1,2021):

    for j in range(2,i):
        if i%j==0:
            count+=1
            break
        

print(count)