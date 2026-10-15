#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;
int a[N], b[N];
int d[N][N];
bool color[N][N];

bool temp[N][N];

vector<int> rec(int x, int y, int k, int n, int m) {
	vector<int>v;
	if (k == 0) {
		return v;
	}

	for (int i = n - 1; i >= x; i--) {
		temp[i][y] = true;
		if (d[i][y] == k && color[i][y]) {
			v = rec(i + 1, y + 1, k - 1, n, m);
			v.push_back(a[i]);
			return v;
		}
	}

	for (int j = m - 1; j >= y; j--) {
		temp[x][j] = true;
		if (d[x][j] == k && color[x][j]) {
			v = rec(x + 1, j + 1, k - 1, n, m);
			v.push_back(b[j]);
			return v;
		}
	}

	return rec(x + 1, y + 1, k, n, m);
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				d[i][j] = 1;
				color[i][j] = true;
			}
		}
	}

	for (int j = m - 1; j >= 0; j--) {
		for (int i = n - 1; i >= 0; i--) {
			d[i][j] = max(max(d[i + 1][j], d[i][j + 1]), d[i][j] + d[i + 1][j + 1]);
		}
	}

	int res = d[0][0];
	cout << res << endl;
	auto v = rec(0, 0, res, n, m);
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << ' ';
	}

	return 0;
}