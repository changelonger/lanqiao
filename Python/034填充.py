import os
import sys

s=input()
n=len(s)
judge=['00','11','0?','1?','?0','?1','??']
ans=0
i=1
while i<n:
  if s[i-1:i+1] in judge:
    ans+=1
    i+=2
  else:
    i+=1
print(ans)