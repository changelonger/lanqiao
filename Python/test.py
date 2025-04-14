# n = int(input().split())
# a = list(map(int,input.split()))
# sa = sorted(a)
# df = 0
# for i in range(len(a)):
#     if a[i]!=sa[i]:
#         df+=1
# print(df-1)

# 'lqb、lbq、qlb、qbl、blq、bql。'
a = ['lqb','lbq','qbl','blq','qlb','bql']
s = input()
i,j = 0,3
res = 0
while j<=len(s):
    # print(s[i:j])
    if s[i:j] in a:
        i+=3
        j+=3
        res+=1
    else:
        i+=1
        j+=1
print(res)
