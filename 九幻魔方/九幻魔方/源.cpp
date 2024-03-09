#include<iostream>
using namespace std;
int vis[10], a[5][5], ans[5][5];
int n, cnt;
pair<int, int>p[10];
/*
    这一段，
    a是3x3的矩阵，p用来储存为0的坐标对，vis是代表哪些数字已经在矩阵中出现了
    n是代表有几个空没有被填，cnt 是目标矩阵
    */
bool check()
{
    int sum = a[1][1] + a[2][2] + a[3][3];
    if (sum != a[1][3] + a[2][2] + a[3][1]) return false;
    for (int i = 1; i <= 3; i++) {
        int tmp1 = 0, tmp2 = 0;
        for (int j = 1; j <= 3; j++)tmp1 += a[i][j], tmp2 += a[j][i];//行和列的和相等 
        if (tmp1 != sum || tmp2 != sum) return false;
    }
    return true;
}
void dfs(int now)
{
    //now是用来计算已经填补的个数，它和n比较
    if (now > n) 
    {
        //此时矩阵中的全部元素已经被填满了；
        if (check()) 
        {
            cnt++;
            for (int i = 1; i <= 3; i++)
                for (int j = 1; j <= 3; j++)
                    ans[i][j] = a[i][j];
            //ans是目的矩阵
        }
        return;
    }
    int x = p[now].first, y = p[now].second;
    //得到还没有被填的第一个横纵坐标
    for (int k = 1; k <= 9; k++)
    {
        if (vis[k])continue;//这个数如果已经有了，就下一个数
        a[x][y] = k;//把值赋过去
        vis[k] = 1;//代表这个数字已经用过了
        dfs(now + 1);//继续，但是now要增加
        a[x][y] = 0;//这一步是后面已经复制完成了的操作，把赋的值全部清零
        vis[k] = 0;//并把用的数字清零
    }
}
int main()
{
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) 
        {
            cin >> a[i][j];
            if (!a[i][j])p[++n] = make_pair(i, j);
            vis[a[i][j]] = 1;
        }
    
    dfs(1);//划重点。
    if (cnt == 1) 
    {
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                cout << ans[i][j] << " \n"[j == 3];
    }
    else cout << "Too Many\n";
    return 0;
}