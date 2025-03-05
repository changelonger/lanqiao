# from datetime import datetime, timedelta

# start = datetime(year=1970, month=1, day=1)
# dela = timedelta(milliseconds=1)
# now = int(input())

# now = start + now * dela
# print('%02d:%02d:%02d' % (now.hour, now.minute, now.second))


n = int(input())
n/=1000 #总共的秒
s = n%60 # 剩的秒
n/=60
m = n%60
n/=60
h = n%24
print("%02d:%02d:%02d" % (h, m, s))