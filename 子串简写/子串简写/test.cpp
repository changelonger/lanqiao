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
    i��j�����Զ��k-1
    ���c1sum���㣬��ô����S[i] == c2��Ҳû�д��ھ���K - 1��c1����ƥ�䡣
   
    
    �

    
    */
    cout << ans;
    return 0;
}