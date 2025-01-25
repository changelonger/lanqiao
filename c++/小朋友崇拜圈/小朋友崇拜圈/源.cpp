#include <iostream>
using namespace std;
const int N = 9;
int adm[N];
int n;
int Max;
int parent[N];
bool flag;
bool over=false;
void dfs(int num, int sum, int root)
{
    if (root > n) {
        
        over = true;
        return;

    }
    if (num != root)
        flag = true;
    if (sum > n) {
        flag = false;
        dfs(root+1, 0, root + 1);
        if (over == true)
            return;
    }
    if (num == root && flag) {
        if (sum > Max) {
            Max = sum;
            flag = false;
            dfs(root+1, 0, root + 1);
            if (over == true)
                return;
        }
        else {
            flag = false;
            dfs(root + 1, 0, root + 1);
            if (over == true)
                return;
        }
    }
    else {
        dfs(adm[num], sum + 1, root);
    }
}
int main()
{
    // 请在此输入您的代码
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> adm[i];
    }
    dfs(1, 0, 1);
    cout << Max;
    return 0;
}