#include <iostream>
using namespace std;

#define SIZE 4

int n;
int map[SIZE][SIZE];//map是网格
int row[SIZE];//横着箭
int cel[SIZE];//竖着箭
int r[SIZE];//记录横着的箭
int c[SIZE];//记录竖着的箭
int arr[SIZE * SIZE];//记录做过的点
int v[SIZE][SIZE];//标记有没有走过
int res = 0;//总共的箭 
int Next[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };//上下左右
int flag = 0;//标记有没有加入这个点
void df(int x, int y, int sum)
{
    

    if (sum== res/2&&x>=n&&y==n-1)
    {
        //如果走过的点数等于箭数，并且x>=n（因为是首先向下），y==n-1
        for (int i = 0; i < res/2; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl; // 输出完整路径后换行
        return;
    }

    if (x < 0 || x >= n || y < 0 || y >= n)
    {
        flag = 0;//标记没有走过
        return;
    }

    if (v[x][y] == 0)
    {
        flag = 1;
        v[x][y] = 1;
        arr[sum] = map[x][y];
        r[y]++;
        c[x]++;//操作
        if (r[y] > row[y] || c[x] > cel[x])
        {
            flag = 1;//不符合箭数

            return;
        }
        else
        {
            for (int k = 0; k < 4; k++)
            {
                df(x + Next[k][0], y + Next[k][1], sum + 1);//上下左右
                if (flag)//如果加入了这个点
                {
                    r[y + Next[k][1]]--;
                    c[x + Next[k][0]]--;
                    v[x + Next[k][0]][y + Next[k][1]] = 0;
                    arr[sum + 1] = 0;//回溯
                }
            }
            flag = 1;
            return;
           
        }
    }
    flag = 0;
    return;
}

int main()
{
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            map[i][j] = count++;
    if (n == 0)
        cout << 0;
    else if (n == 1)
        cout << 1;
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> row[i];
            res += row[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> cel[i];
            res += cel[i]; // 应该累加cel数组的值，而不是row数组
        }
        df(0, 0, 0);
    }
    return 0;
}
