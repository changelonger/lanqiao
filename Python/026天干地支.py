tian = ['jia','yi','bing','ding','wu','ji','geng','xin','ren','gui']
di = ['zi','chou','yan','mao','cheng','si','wu','wei','shen','you','xu','hai']
i,j,k= 0,0,0
s = ['']*60
while k<60:
    s[k] = tian[i]+di[j]
    i = 0 if i==9 else i+1
    j = 0 if j==11 else j+1
    k+=1

n = int(input())
a = (n-2020)%60
print(s[(36+a)%60])

