#include<iostream>
using namespace std;
int n;
int arr[10];
int res[10];
int v[10];
void dfs(int sum)
{
	if (sum == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << res[i]<<" ";
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0)
		{
			v[i] = 1;
			res[sum] = arr[i];
			dfs(sum + 1);
			v[i] = 0;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dfs(0);
	return 0;
}