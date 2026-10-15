#include <iostream>
using namespace std;
typedef long long ll;

const int N = 505;
ll dp[N][N];
const ll INF = 1e18;

void init(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) 
				dp[i][j] = 0;
			else dp[i][j] = INF;
		}
	}
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	init(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		dp[a][b] = min(dp[a][b], w);
		dp[b][a] = min(dp[b][a], w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] < INF && dp[k][j] < INF) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		if (dp[a][b] == INF) {
			cout << -1 << endl;
		}
		else {
			cout << dp[a][b] << endl;
		}
	}

	return 0;
}