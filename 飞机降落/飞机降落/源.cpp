#include <iostream>
using namespace std;
int v[10];
int n = 0; int sum = 0; int flag = 0;
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void dfs(int arr[][3], int last)
{
    if (sum == n)
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!v[i] && arr[i][0] + arr[i][1] >= last)
        {
            v[i] = 1;
            sum++;
            int m = max(last, arr[i][0]);
            dfs(arr, m + arr[i][2]);
            v[i] = 0;
            sum--;
        }
    }
    

}
int main()
{
    // 请在此输入您的代码
    int T = 0; cin >> T;
    while (T--)
    {
        cin >> n;
        int arr[3][3];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                cin >> arr[i][j];

        dfs(arr, 0);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        flag = 0;
        sum = 0;
    }
    return 0;
}