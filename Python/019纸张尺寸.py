s = input()
a = 1189
b = 841
l =[]
for i in range(10):
    l.append([a,b]) if a>b else l.append([b,a])
    if a>b:
        a= a//2
    else:
        b = b//2

print(l[int(s[1])][0])
print(l[int(s[1])][1])