#include <iostream>
using namespace std;
#include<string>
int arr1[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
int arr2[13] = { 0, 31,29,31,30,31,30,31,31,30,31,30,31 };
int * is_data(int a, int b, int c)
{
    int* m = (int *)malloc(3 * sizeof(int));
    if (a < 60)
        a = 2000 + a;
    else
        a = 1900 + a;
    int flag = a % 4;
    if (flag != 0)
    {
        if (b <= 12 && b >= 1 && c <= arr1[b] && c >= 1)
        {
            m[0] = a;
            m[1] = b;
            m[2] = c;

        }
        else 
            m= NULL;
    }
    else 
    {
        if (b <= 12 && b >= 1 && c <= arr2[b] && c >= 1)
        {
            m[0] = a;
            m[1] = b;
            m[2] = c;

        }
        else
            m = NULL;
    }

    return m;
   
    
}
void mprintf(int* arr)
{
    if (arr == NULL)
        return;
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    if (b < 10)
    {
        if (c < 10)
            cout << a << "-0" << b << "-0" << c << endl;
        else
            cout << a << "-0" << b << "-" << c << endl;
    }
    else
    {
        if (c < 10)
            cout << a << "-" << b << "-0" << c << endl;
        else
            cout << a << "-" << b << "-" << c << endl;
    }
}
int main()
{
    // 请在此输入您的代码
    string s;
    cin >> s;
    int *arr[3];
    int a = (s[0] - '0') * 10 + s[1] - '0';
    int b = (s[3] - '0') * 10 + s[4] - '0';
    int c = (s[6] - '0') * 10 + s[7] - '0';
    arr[0]=is_data(a, b, c);
    arr[1]=is_data(b, c, a);
    arr[2]=is_data(c, b, a);
    for (int i = 0; i < 2; i++)
    {
        for (int j = i; j <2-i ; j++)
        {
            if (arr[i] && arr[j])
            {
                if (arr[i][0] > arr[j][0])
                {
                    swap(arr[i][0], arr[j][0]);
                    swap(arr[i][1], arr[j][1]);
                    swap(arr[i][2], arr[j][2]);
                }
                else if (arr[i][0] == arr[j][0] && arr[i][1] > arr[j][1])
                {
                    swap(arr[i][1], arr[j][1]);
                    swap(arr[i][2], arr[j][2]);
                }
                else if (arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1] && arr[i][2] > arr[j][2])
                {
                    swap(arr[i][2], arr[j][2]);
                }
            }
    
        }
    }
    for (int i = 0; i < 3; i++)
    {
        mprintf(arr[i]);
    }
    return 0;
}