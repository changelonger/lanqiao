#include <iostream>
using namespace std;
const int N = 15;
int plan[N][3];
//����ʱ�䣬����ʱ�䣬��������Ҫ��ʱ��
bool flag = false;
int vis[N];
int n = 0;
void dfs(int num, int last, int count) {
    if (count == n) {
        flag = true;
        return;
    }
    if (!flag) {
        for (int i = 0; i < n; i++) {
            if (flag == true)
                return;
            /*
            ������ʱ���� max(�����ʱ��,��һ���Ľ���ʱ��)+��������Ҫ��ʱ��
            */
            if (vis[i] == 0 && last <= plan[i][0]+plan[i][1]) {
                vis[i] = 1;
                int end = max(last, plan[i][0]) + plan[i][2];
                dfs(i, end, count+1);
                vis[i] = 0;
            }
        }
    }
}
int main()
{
    // ���ڴ��������Ĵ���
    int T;
    cin >> T;
    while (T--) {
        flag = false;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                cin >> plan[i][j];
        dfs(0, 0, 0);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
/*
2
3
0 100 10
10 10 10
0 2 20
3
0 10 20
10 10 20
20 10 20

2
3
0 10 20
10 10 20
20 10 20
*/