#include <iostream>
using namespace std;
int n, m;
#define Y(a,b) (a)*m+b
int pre[100000]; int arr[100000];
/*
注意我设置的是一维数组，想要的到二维数组，就需要转换
这个宏定义可以满足我的需求

*/
int find(int x)
{
    while (x != pre[x])
        x = pre[x];
    return x;
}
//并查集中的find函数，目的是找到根
int main()
{
    cin >> n >> m;
    //初始化并查集并且出入数据
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            pre[Y(a, b)] = Y(a, b);
            cin >> arr[Y(a, b)];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (find(Y(i, j)) == Y(i, j))//如果(i,j)对应的pre数组是他本身，就代表这个元素没有找到它的根
            {
                int x = Y(i, j);//得到在一位数组中的坐标

                for (int a = -1; a <= 1; a++)
                {
                    for (int b = -1; b <= 1; b++)
                        //找到周围的8个元素
                    {
                        if (i + a < 0 || i + a >= n || j + b < 0 || j + b >= m)
                            continue;
                        //在边上
                        if (arr[x] > arr[Y(i + a, j + b)])
                            x = Y(i + a, j + b);
                        //找到最小的等级对应的下标
                    }
                }
                pre[Y(i, j)] = find(pre[x]);//此时，把这个点的pre数组对应值设置为x点的pre数组的根
            }
        }
    }
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n * m; i++)
        arr[find(i)]++;
    //一直找到最深处，并且这个数++
    for (int i = 0; i < n * m; i++) {
        cout << arr[i] << ((i + 1) % m == 0 ? '\n' : ' ');
    }
    return 0;
}
