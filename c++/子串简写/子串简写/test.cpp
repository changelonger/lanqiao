#include <bits/stdc++.h> 
using namespace std;
int K;
long long ans = 0, c1_sum = 0;
string S;
char c1, c2;
int main() {
    cin >> K >> S >> c1 >> c2;
    for (int i = K - 1, j = 0; i < S.length(); i++, j++) {
        if (S[j] == c1) c1_sum++;
        if (S[i] == c2) ans += c1_sum;
    }
    /*
    i和j差的永远是k-1
    如果c1sum是零，那么就算S[i] == c2，也没有大于距离K - 1的c1和她匹配。
   
    
    妙啊

    
    */
    cout << ans;
    return 0;
}