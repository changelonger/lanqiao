n = int(input())
score = [0]*n
c_pass,c_good = 0,0
for i in range(n):
    score[i] = int(input())
    if score[i]>=60:
        c_pass+=1
    if score[i]>=85:
        c_good+=1
x1 = 100*c_pass/n
x2 = 100*c_good/n
print(x2)
x1 = int(x1) if x1-int(x1)<0.5 else int(x1)+1
x2 = int(x2) if x2-int(x2)<0.5 else int(x2)+1
print(str(x1)+'%')
print(str(x2)+'%')
