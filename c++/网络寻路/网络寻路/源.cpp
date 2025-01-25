#include <iostream>
#include<vector>
using namespace std;
int n, m, ans;
vector <int >mp[10005];
//二维数组，包含mp的vectot
void dfs(int last, int x, int num) {
    if (num == 3) {
        ans++;
        return;
    }
    for (int i = 0; i < mp[x].size(); i++) {
        if (mp[x][i] != last) {
            dfs(x, mp[x][i], num + 1);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);//这就类似邻接链表了，这种的不是迷宫类型的比较合适；
    }
    for (int i = 1; i <= n; i++) {
        dfs(-1, i, 0);
    }
    cout << ans;
    return 0;
}