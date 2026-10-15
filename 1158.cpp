#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long


pair<ll, ll>arr[1002];
ll dp[100005];
int main()
{
	int i, j, k, l, m, n, o, p;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].first;
	}
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].second;
	}
	sort(arr, arr + n);
	for (i = 0; i <= m; i++)
	{
		dp[i] = 0;
	}
	for (i = n - 1; i >= 0; i--)
	{
		for (j = m; j >= arr[i].first; j--)
		{
			if (dp[j] > 0)
			{
				if (j + arr[i].first <= m)
				{
					dp[j + arr[i].first] = max(dp[j] + arr[i].second, dp[j + arr[i].first]);
				}
			}
		}
		if (arr[i].first <= m)
			dp[arr[i].first] = max(arr[i].second, dp[arr[i].first]);
	}
	ll res = 0;
	for (i = m; i >= 0; i--)
	{
		res = max(res, dp[i]);
	}
	cout << res;

	return 0;
}