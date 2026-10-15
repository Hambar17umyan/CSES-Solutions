#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll dp[1000006];
int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> m;
	n = 1000000;
	k = 0;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 1;
	dp[5] = 1;
	dp[6] = 1;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			if (i + j <= m)
			{
				dp[i + j] += dp[i];
				dp[i + j] %= 1000000007;
			}
		}
	}
	cout << dp[m];

	return 0;
}