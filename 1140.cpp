#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

pair<pair<ll, ll>, ll>arr[200005];
ll dp[200005];
vector<ll>v;
int main()
{
	ll n, m, i, j = 4;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].first.second >> arr[i].first.first >> arr[i].second;
	}
	sort(arr, arr + n);
	dp[0] = arr[0].second;
	ll r = dp[0]; 
	v.push_back(arr[0].first.first);

	for (i = 1; i < n; i++)
	{
		dp[i] = arr[i].second;
		j = lower_bound(v.begin(), v.end(), arr[i].first.second) - v.begin();
		//cout << j << endl;
		if (j > 0)
		{
			dp[i] += dp[j - 1];
		}
		dp[i] = max(dp[i - 1], dp[i]);
		v.push_back(arr[i].first.first);
	}
	//for (i = 0; i < n; i++)
		//cout << dp[i] << endl;
	cout << dp[n - 1] << endl;

	return 0;
}
