#include <iostream>
using namespace std;
#define ll long long

char arr[1002][1002];
ll dp[1002][1002];
int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		if (arr[0][i] == '*')
			break;
		dp[0][i] = 1;
	}
	for (i = 0; i < n; i++)
	{
		if (arr[i][0] == '*')
			break;
		dp[i][0] = 1;
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (arr[i][j] == '.')
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				dp[i][j] %= 1000000007;
			}
		}
	}
	/*for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}*/
	cout << dp[n - 1][n - 1];

	return 0;
}