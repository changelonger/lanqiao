# 方法1 调用库函数
from datetime import datetime, timedelta
start = datetime(year=1900,month = 1,day = 1)
end = datetime(year=9999,month =12,day = 13)
day = timedelta(days=1)
# print(start)

def get_sum(a):
    sum = 0
    while(a):
        sum+=a%10
        a = a//10
    return sum
sum = 0
while True:
    a = get_sum(start.year)
    b = get_sum(start.month)
    c = get_sum(start.day)
    if a==b+c:
        # print(start)
        sum+=1
    start+=day
    if start==end:
        break
print(sum)
