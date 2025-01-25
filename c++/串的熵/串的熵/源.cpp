#include <iostream>
using namespace std;
#include<math.h>
int main()
{
    // 请在此输入您的代码
    int n = 23333333;
    double a;
    for (a = 0; a < n; a++)
    {
        double b = 1 - a / n;
        double aa = a / n;
        double H = -(a * aa * log2(aa) + (n - a) * b * log2(b));
        if (fabs(H - 11625907.5798) < 0.0001)
            break;
    }
    cout << (int)(a);
    return 0;

}