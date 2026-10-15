#include <iostream>
using namespace std;

int dp[1000001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
		dp[i] = 1e9;

	for (int i = 1; i <= 9; i++)
		dp[i] = 1;

	for (int i = 10; i <= n; i++) {
		for (int j = 1; j <= i; j *= 10) {
			int dig = (i / j) % 10;
			dp[i] = min(dp[i], dp[i - dig] + 1);
		}
	}

	cout << dp[n];

	return 0;
}