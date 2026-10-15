#include <iostream>
using namespace std;
typedef long long ll;

bool color[10][10];
string s;

ll rec(int x, int y, int ind) {
	if ((color[x - 1][y] && color[x + 1][y]) &&
		(!color[x][y - 1] && !color[x][y + 1]))
		return 0;

	if ((color[x][y - 1] && color[x][y + 1]) &&
		(!color[x - 1][y] && !color[x + 1][y]))
		return 0;

	if (x == 7 && y == 1)
		return ind == s.size() ? 1 : 0;

	if (ind == s.size())
		return 0;

	color[x][y] = true;

	ll res = 0;

	if (s[ind] == 'U') {
		if (!color[x - 1][y])
			res += rec(x - 1, y, ind + 1);
	}
	else if (s[ind] == 'D') {
		if (!color[x + 1][y])
			res += rec(x + 1, y, ind + 1);
	}
	else if (s[ind] == 'L') {
		if (!color[x][y - 1])
			res += rec(x, y - 1, ind + 1);
	}
	else if (s[ind] == 'R') {
		if (!color[x][y + 1])
			res += rec(x, y + 1, ind + 1);
	}
	else {
		if (!color[x - 1][y])
			res += rec(x - 1, y, ind + 1);

		if (!color[x + 1][y])
			res += rec(x + 1, y, ind + 1);

		if (!color[x][y - 1])
			res += rec(x, y - 1, ind + 1);

		if (!color[x][y + 1])
			res += rec(x, y + 1, ind + 1);
	}

	color[x][y] = false;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	for (int i = 0; i <= 8; i++) {
		color[0][i] = true;
		color[8][i] = true;
		color[i][0] = true;
		color[i][8] = true;
	}

	color[1][1] = true;

	cout << rec(1, 1, 0);

	return 0;
}