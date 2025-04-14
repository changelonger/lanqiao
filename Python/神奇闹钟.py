import os
import sys
from datetime import datetime, timedelta
t = int(input())

for _ in range(t):
    s = input()
    year,mon,day,h,m,s,x = int(s[0:4]),int(s[5:7]),int(s[8:10]),int(s[11:13]),int(s[14:16]),int(s[17:19]),int(s[20:])
    # print(year,mon,day,h,m,s,x)
    d1 = datetime(year=year,month=mon,day=day,hour=h,minute=m,second=s)
    d0 = datetime(year=1970,month=1,day=1)
    d = timedelta(minutes=x)
    # print(x,d)
    n = (d1-d0)//d
    d0+=d*n
    print(d0)


"""
2
2016-09-07 18:24:33 10
2037-01-05 01:40:43 30
"""
