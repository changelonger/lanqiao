#include <iostream>
using namespace std;

int main()
{
    // 请在此输入您的代码
    int n = 0; cin >> n;
    int arr[20][4];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == arr[i][2] && arr[i][1] == arr[i][3])
        {
            cout << "0" << endl;
            continue;
        }
        int a = 1; int b = 1;
        if ((arr[i][0] + arr[i][1]) % 2 == 0)
            a = 0;
        if ((arr[i][2] + arr[i][3]) % 2 == 0)
            b = 0;
        if (a == b)
            cout << "2" << endl;
        else
            cout << "1" << endl;

    }
    return 0;
}