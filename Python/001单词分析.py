from collections import Counter
hs = Counter()
max ,str = 0,''
s = input()
for i in s:
    hs[i]+=1
    if hs[i]>max:
        max = hs[i]
        str = i
    elif hs[i]==max and str>i:
        str = i            
print(str)
print(max)

