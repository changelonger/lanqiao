
#include<iostream>
using namespace std;
const int N = 7;
char Map[N][N];
int n;
int sum = 0;//总共的岛屿；
int res = 0;//剩下的岛屿
int Next[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool flag;
void dfs(int x, int y)
{
    if (flag == false) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int xx = x + Next[i][0];
            int yy = y + Next[i][1];
            if (Map[xx][yy] != '.')
                cnt++;
        }
        if (cnt == 4) {
            flag = true;
            res++;
        }
    }
    Map[x][y] = '*';
    for (int i = 0; i < 4; i++) {
        int xx = x + Next[i][0];
        int yy = y + Next[i][1];
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && Map[xx][yy] == '#')
            dfs(xx, yy);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Map[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if (Map[i][j] == '#') {//没有被访问过并且不是海
                sum++;
                flag = false;
                dfs(i, j);
            }
        }
    }
    cout << sum - res;
    return 0;
}