import os
import sys
from datetime import datetime,timedelta
# 请在此输入您的代码
# 存储时间的列表
time_list=[]
# 这个模板代码要记住 很简单并不是很复杂
with open(r"D:\CODE\lanqiao\Python\018工作时长") as f:
    for time in f.readlines():
        time_list.append(time.strip())

# 将字符串 转换为时间格式 的 datetime
trans_time=[]
for time in time_list:
    # 对于每一个字符串进行一个转换
    trans_time.append(datetime.strptime(time,"%Y-%m-%d %H:%M:%S"))
    
# 再进行一个转换，全部转换成秒
s_list=[]
for time in trans_time:
    s_list.append(time.timestamp())
# 然后进行一个排序

s_list.sort()
sums=0

#然后进行累计统计
for i in range(1,521,2):
    sums+=(s_list[i]-s_list[i-1])
print(int(sums))