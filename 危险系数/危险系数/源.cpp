#include<iostream>
#include<vector>
using namespace std;
int n, m;
#define N 2020
vector<int>mp[N];
int lefts, rights;
int sum = 0;
int arr[N];
int vis[N];
void dfs(int num) {
    if (num == rights) {
        sum++;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 1)
                arr[i]++;
        }
        return;
    }
    vis[num] = 1;
    for (int i = 0; i < mp[num].size(); i++)
    {
        if (vis[mp[num][i]] == 0) {
            dfs(mp[num][i]);
            vis[mp[num][i]] = 0;
        }
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    cin >> lefts >> rights;
    dfs(lefts);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == sum && i != lefts && i != rights)
            count++;
    }
    cout << count;
    return 0;
}
