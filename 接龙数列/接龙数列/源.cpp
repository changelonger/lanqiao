#include <iostream>
#include <string>
using namespace std;

int dp[10];
/*
这道题其实本质就是求解出数列中最长的接龙数列，计算出最长的接龙数列长度，
数列总长度-最长接龙数列长度等于最少删除次数。这就是一个求最优解的问题，
然而看到这道题的数据量可以发现，暴力求解一定会超时，因此考虑动态规划。 
动态规划最重要的就是状态转移方程，而这个题目就可以定义状态为当前最长接龙数列长度，
则dp[i]就是以i为数字最后一位的最长接龙数列长度，
设x为当前数字的第一位(如果为接龙数列，也就是前一位数的最后一位)，
y为当前数字的最后一位，则转移方程可以写为dp[y]=max(dp[x]+1,dp[y])
*/
int main()
{
    // 请在此输入您的代码
    int n;
    cin >> n;
    string s;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int x = s[0] - '0', y = s[s.size() - 1] - '0';
        dp[y] = max(dp[x] + 1, dp[y]);
        m = max(m, dp[y]);
    }
    cout << n - m << endl;
    return 0;
}