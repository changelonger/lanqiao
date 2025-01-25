#include <iostream>
#include<vector>
using namespace std;
int n, m, ans;
vector <int >mp[10005];
//��ά���飬����mp��vectot
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
        mp[v].push_back(u);//��������ڽ������ˣ����ֵĲ����Թ����͵ıȽϺ��ʣ�
    }
    for (int i = 1; i <= n; i++) {
        dfs(-1, i, 0);
    }
    cout << ans;
    return 0;
}