#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

const int N = 105;
ll arr[N];
ll dp[1000006];

int main() {
	ll n, x;
	cin >> n >> x;

	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[arr[i]]++;
	}

	sort(arr, arr + n);
	ll mod = 1e9 + 7;
	for (ll j = 0; j <= x; j++) {
		for (ll i = 0; i < n; i++) {
			if (arr[i] + j > x)
				break;

			dp[arr[i] + j] += dp[j];
			dp[arr[i] + j] %= mod;
		}
	}

	cout << dp[x] << endl;

	return 0;
}