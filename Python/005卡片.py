count = 0
i = 0
while 1:
    count+=str(i).count('1')
    if count>2021:
        break;
    i+=1
print(i-1)