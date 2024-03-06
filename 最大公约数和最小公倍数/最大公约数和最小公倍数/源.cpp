#include <iostream>
#include<math.h>
#include<vector>
using namespace std;
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
int isprim(int n)
{
    int flag = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            flag == 0;
    }
    return flag;
}
int main()
{
    // 请在此输入您的代码
    int T = 0; cin >> T;
   
    while (T--)
    {
        vector<int>v;
        int i = 2;
        int n, num; cin >> n >> num;
        int m = n;
        while (i <= n)
        {
            if (n % i == 0)
            {
                if (isprim(i) == 1)
                {
                    v.push_back(i);
                    n /= i;
                    i = 1;
                }
            }
            i++;
        }
        int x = 0;
        for (auto p = v.begin(); p != v.end(); p++)
        {
            x += (*p);
        }
        int lcm = x * m / gcd(m, x);
        if (lcm == num)
            cout << "Yes" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}