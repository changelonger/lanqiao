n = int(input())
a = 1
b = 2
for i in range(3,n+1):
    a = a*i+i*(i-1)//2*b
    b*=i
print(a%998244353)