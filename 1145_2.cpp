#include <iostream>
#include <algorithm>
using namespace std;

int arr[200005];
int dp[200005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i + 1] = 1e9 + 6;
	}
	dp[0] = -1e9 - 6;
	dp[n + 1] = 1e9 + 6;
	for (int i = 0; i < n; i++)
	{
		int j = int(upper_bound(dp, dp + n + 2, arr[i]) - dp);
		if (dp[j - 1] < arr[i] && arr[i] < dp[j])
			dp[j] = arr[i];
	}
	for (int i = 1; i <= n + 1; i++)
	{
		if (dp[i] == 1e9 + 6)
		{
			cout << i - 1;
			break;
		}
	}

	return 0;
}