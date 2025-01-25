#include <iostream>
using namespace std;
int arr0[1000];
int a = 0;
int MAX(int max,int arr[])
{
    
    if (arr[max] == 0)
    {
        while (1)
        {
            max--;
            if (arr[max] != 0)
                break;
        }
    }
    return max;
}
int find(int i, int n)
{
    int arr[150];
    for (int k = 0; k <= n; k++)
    {
        arr[k] = arr0[k];
    }
    int a = 0;
    int count = 1;
    int sum = 0;
    int num = 0;
    int max = n;
    while (1)
    {
        if (count > n || sum == n)
            break;
        if (arr[i] == 0)
            i++;
        else
        {
            max = MAX(max,arr);
            if (arr[i] == count)
            {
                count = 1;
                a += arr[i];
                sum++;
                arr[i] = 0;
            }
            else
            {
                count++;
            }
            i++;
            if (i == max + 1)
                i -= max;
        }
    }
    return a;
}
int main()
{
    // 请在此输入您的代码
    int n = 0; cin >> n;
    arr0[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr0[i];
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = find(i, n);
        if (num > max)
            max = num;
    }
    cout << max;
    return 0;
}