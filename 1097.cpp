#include <iostream>
using namespace std;
typedef long long ll;

const int N = 5005;
ll arr[N];
ll dp[N][N];
ll pref[N];

const ll MININF = -1e15;

ll find_sum(int l, int r) {
	if (l == 0)
		return pref[r];
	else
		return pref[r] - pref[l - 1];
}

void play(int l, int r) {
	if (dp[l][r] != MININF)
		return;

	ll a, b;
	if (l == r) {
		dp[l][r] = arr[l];
		return;
	}

	a = dp[l + 1][r];
	b = dp[l][r - 1];

	if (a == MININF) {
		play(l + 1, r);
		a = dp[l + 1][r];
	}

	if (b == MININF) {
		play(l, r - 1);
		b = dp[l][r - 1];
	}

	dp[l][r] = max(-a + find_sum(l + 1, r) + arr[l], -b + find_sum(l, r - 1) + arr[r]);
}

int main() {
	int n;
	cin >> n;
	ll k = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		pref[i] = k + arr[i];
		k = pref[i];

		for (int j = 0; j < n; j++) {
			dp[i][j] = MININF;
		}
	}

	play(0, n - 1);
	cout << dp[0][n - 1] << endl;

}