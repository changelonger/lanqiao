#include <iostream>
#include <cstring>
using namespace std;
int dp[31][100];  //dp[i][j]表示做完第i题，得分为j的方案数


/*
第i题做对：dp[i][j] = dp[i-1][j-10]
因为做对的话，j一定会-10.
所以等于上一个题对时j-10的分数对应的方案；
第i题做错（即j为0）: dp[i][0] = SUM{d[i-1][k]} 即做完第i-1题的所有方案数之和
只要这题做错，就和前面没有任何关系了所以是前面的总和；
*/


int main() {

    int res = 0;
    dp[1][0] = dp[1][10] = 1;
    for (int i = 2; i <= 30; i++)
        for (int j = 0; j <= 90; j += 10) { //这里不枚举到100的原因是，这种情况不存在，因为是以70分结束的，100分一定会结束，而80，90分不一定结束
            if (j == 0) {
                //第i题未做对，方案数为做完第i-1题所有方案数之和 
                for (int k = 0; k <= 90; k += 10)
                    dp[i][0] += dp[i - 1][k];
            }
            else {
                dp[i][j] = dp[i - 1][j - 10];  //第i题做对 
                if (j == 70) res += dp[i][j];
            }
        }
    cout << res;
    return 0;
}