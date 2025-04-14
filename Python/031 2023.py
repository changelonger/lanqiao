res = 0
for i in range(12345678, 98765433):
    s = str(i)
    cnt = 0
    for j in s:
        if j =='2' and cnt == 0:
            cnt+=1
        elif j=='0' and cnt == 1:
            cnt+=1
        elif j=='2' and cnt == 2:
            cnt+=1
        elif j=='3' and cnt == 3:
            cnt+=1
            break
    if i%1000000==0:
        print(i) 
    if cnt!=4:
        res+=1


# print(98765432-1234578+460725)
print(res)
