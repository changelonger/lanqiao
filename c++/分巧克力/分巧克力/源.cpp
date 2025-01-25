#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

void lmax(int arr[2])
{
    int temp;
    if (arr[0] < arr[1])
    {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
}
bool com(int arr1[2], int arr2[2])
{
    return arr1[0] < arr2[0];
}
int main()
{
    // 请在此输入您的代码
    int n, k, i = 0, j, count = 0; cin >> n >> k;

    int arr[10][2];

    
    for (i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i][0] = a;
        arr[i][1] = b;
        lmax(arr[i]);
    }
    int max = 0;
    for (i = 0; i < n; i++)
    {
        if (max < arr[i][1])
            max = arr[i][1];
    }
    for (i = max; i >= 1; i--)
    {
        int sum = 0;
        for (j = 0; j < n; j++)
        {
            sum += arr[j][0] / i * (arr[j][1] / i);
        }
        if (sum >= k)
        {
            break;
            
        }
    }
    cout << i;
    return 0;
}