#include <iostream>
using namespace std;

pair<long long, long long>dp[1000006];
void solve()
{
	int n;
	cin >> n;
	cout << dp[n - 1].second << endl;
}

int main()
{
	long long mod = 1000000007;
	long long n, i;
	n = 1000002;
	dp[0] = make_pair(1, 2);
	for (i = 1; i < n; i++)
	{
		dp[i].first = dp[i - 1].first;
		dp[i].first %= mod;
		dp[i].first += dp[i - 1].second;
		dp[i].first %= mod;

		dp[i].second = dp[i - 1].second - dp[i - 1].first + mod;
		dp[i].second %= mod;
		dp[i].second += dp[i - 1].second - dp[i - 1].first + mod;
		dp[i].second %= mod;
		dp[i].second += dp[i - 1].second - dp[i - 1].first + mod;
		dp[i].second %= mod;
		dp[i].second += dp[i - 1].second;
		dp[i].second %= mod;
		dp[i].second += dp[i].first;
		dp[i].second %= mod;
	}
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}