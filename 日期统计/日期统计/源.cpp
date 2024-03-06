#include <iostream>
using namespace std;
int main()
{
    int arr[100]; int count = 0;
    for (int i = 0; i < 100; i++)cin >> arr[i];
    int data[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= data[i]; j++)
        {
            int day[8] = { 2,0,2,3,i / 10,i % 10,j / 10,j % 10 };
            int k = 0;
            for (int l = 0; l < 100; l++)
            {
                if (arr[l] == day[k])
                    k++;
                if (k == 8)
                {
                    count++;
                    break;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}

