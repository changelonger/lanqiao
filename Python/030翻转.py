n = int(input())
for _ in range(n):
    t = list(input())
    s = list(input())
    res = 0
    if t[0]!=s[0] or t[-1]!=s[-1]:
        print(-1)
        continue
    else:
        for i in range(1,len(s)-1):
            if s[i]!=t[i]:
                if s[i-1]==s[i+1] and s[i]!=s[i+1]:
                    res+=1
                    s[i] = t[i]
        if s==t:
            print(res)
        else:
            print(-1)



