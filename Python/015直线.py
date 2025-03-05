hs = set()
xy = []
for i in range(20):
    for j in range(21):
        xy.append([i,j])
for i in xy:
    x1,y1 = i[0],i[1]
    for j in xy:
        x2,y2 = j[0],j[1]
        if x1==x2:
            continue
        k = (y1-y2)/(x1-x2)
        b = (x1*y2-x2*y1)/(x1-x2)
        hs.add((k,b))
print(len(hs)+20)
#直线
# points=[[x,y] for x in range(20) for y in range(21)] #创建二维列表：代表xy坐标系
# docker=set()                            #创建集合属性的容器：因为集合里的元素不会重复
# for i in points:                        #二重循环遍历每个坐标
#     x1,y1=i[0],i[1]                     #注意书写格式：a,b=c,d
#     for j in points:
#       x2,y2=j[0],j[1]
#       if x1==x2:                        #特殊情况：直线垂直时斜率不存在，先跳过最后计算
#           continue
#       k=(y2-y1)/(x2-x1)                 #斜率公式
#       b=(x2*y1-x1*y2)/(x2-x1)           #截距公式
#           #存入容器里没有的（斜率，截距）对
#       docker.add((k,b))
# print(len(docker)+20)                   #输出结果：容器的长度40237+斜率不存在的20种情况=40257