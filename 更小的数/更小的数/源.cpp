#include<iostream>
#include<string>
using namespace std;
int check(string s, int i, int j) {
    while (s[i] > s[j] && i < j) {
        i++;
        j--;
    }
    if (i >= j)
        return 0;
    else
        return 1;
}
int main() {
    string s; int res = 0;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (check(s, i, j)) {
                res++;
            }
        }
    }
    cout << res;
    return 0;
}