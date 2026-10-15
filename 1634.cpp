#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll dp[1000006];
ll arr[102];
int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n >> m;
	k = 0;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[arr[i]] = 1;
	}
	ll res = -1;
	for (i = n - 1; i >= 0; i--)
	{
		for (j = 0; j <= m; j++)
		{
			if (arr[i] + j <= m)
			{
				if (dp[j] == 0)
					continue;
				dp[arr[i] + j] += dp[j];
			}

		}
	}
	cout << dp[m];

	return 0;
}