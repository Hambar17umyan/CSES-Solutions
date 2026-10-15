#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll dp[1002][1002];

void bfs(int n)
{
	queue<pair<pair<int, int>, int>>q;
	q.push({ {0, 0}, 0 });
	while (!q.empty())
	{
		pair<pair<int, int>, int>z = q.front();
		q.pop();
		int x = z.first.first;
		int y = z.first.second;
		int u = z.second;
		if (dp[x][y] == 0)
			dp[x][y] = u;
		else
		{
			continue;
		}

		int nx, ny;

		nx = x + 1;
		ny = y + 2;
		if (nx < n && ny < n && nx >= 0 && ny >= 0)
		{
			if (dp[nx][ny] == 0 && (nx != 0 || ny != 0))
				q.push({ {nx, ny}, u + 1 });
		}

		nx = x + 1;
		ny = y - 2;
		if (nx < n && ny < n && nx >= 0 && ny >= 0)
		{
			if (dp[nx][ny] == 0 && (nx != 0 || ny != 0))
				q.push({ {nx, ny}, u + 1 });
		}

		nx = x + 2;
		ny = y + 1;
		if (nx < n && ny < n && nx >= 0 && ny >= 0)
		{
			if (dp[nx][ny] == 0 && (nx != 0 || ny != 0))
				q.push({ {nx, ny}, u + 1 });
		}

		nx = x - 1;
		ny = y + 2;
		if (nx < n && ny < n && nx >= 0 && ny >= 0)
		{
			if (dp[nx][ny] == 0 && (nx != 0 || ny != 0))
				q.push({ {nx, ny}, u + 1 });
		}

		nx = x - 1;
		ny = y - 2;
		if (nx < n && ny < n && nx >= 0 && ny >= 0)
		{
			if (dp[nx][ny] == 0 && (nx != 0 || ny != 0))
				q.push({ {nx, ny}, u + 1 });
		}

		nx = x - 2;
		ny = y - 1;
		if (nx < n && ny < n && nx >= 0 && ny >= 0)
		{
			if (dp[nx][ny] == 0 && (nx != 0 || ny != 0))
				q.push({ {nx, ny}, u + 1 });
		}

		nx = x - 2;
		ny = y + 1;
		if (nx < n && ny < n && nx >= 0 && ny >= 0)
		{
			if (dp[nx][ny] == 0 && (nx != 0 || ny != 0))
				q.push({ {nx, ny}, u + 1 });
		}

		nx = x + 2;
		ny = y - 1;
		if (nx < n && ny < n && nx >= 0 && ny >= 0)
		{
			if (dp[nx][ny] == 0 && (nx != 0 || ny != 0))
				q.push({ {nx, ny}, u + 1 });
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	bfs(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}




int main()
{
	int t;
	speed;
	//cin >> t;

	/*while (t--)
	{
		solve();
	}*/

	solve();

	return 0;
}
