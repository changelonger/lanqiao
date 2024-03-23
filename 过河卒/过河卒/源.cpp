#include<iostream>
using namespace std;
int dp[20][20];
int Next[8][2] = { {-2,-1},{-2,1},{-1,2},{-1,-2},{2,1},{2,-1},{1,-2},{1,2} };
int a, b;
int m, n;
int check(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int xx = a + Next[i][0];
		int yy = b + Next[i][1];
		if (x == xx && y == yy)
			return 0;
	}
	return 1;
}
int main()
{


	cin >> m >> n >> a >> b;
	m += 2;
	n += 2;
	a += 2;
	b += 2;
	for (int i = 2; i <= n; i++) {
		if (check(2, i)) {
			dp[2][i] = 1;
		}
		if (check(i, 2)) {
			dp[i][2] = 1;
		}
	}
	for (int i = 3; i <= m; i++) {
		for (int j = 3; j <= n; j++) {
			if (i == a && j == b) {
				dp[i][j] = 0;
			}
			else if (check(i, j)) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	cout << dp[m][n];
	return 0;
}