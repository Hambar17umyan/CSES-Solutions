#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1005;
char arr[N][N];
int aliq[N][N];
int n, m;
string res = "";
queue<pair<pair<int, int>, int>>q;
void rec(int i, int j, int k)
{
	aliq[i][j] = k;
	bool a, b, c, d;
	a = b = c = d = false;
	if (i > 0)
	{
		if (aliq[i - 1][j] > k + 1)
		{
			//aliq[i - 1][j] = k + 1;
			a = 1;
		}
	}
	if (i < n - 1)
	{
		if (aliq[i + 1][j] > k + 1)
		{
			//aliq[i + 1][j] = k + 1;
			b = 1;
		}
	}
	if (j > 0)
	{
		if (aliq[i][j - 1] > k + 1)
		{
			//aliq[i][j - 1] = k + 1;
			c = 1;
		}
	}
	if (j < m - 1)
	{
		if (aliq[i][j + 1] > k + 1)
		{
			//aliq[i][j + 1] = k + 1;
			d = 1;
		}
	}

	if (a)
	{
		q.push({ {i - 1, j}, k + 1 });
		//rec(i - 1, j, k + 1);

	}
	if (b)
	{
		//rec(i + 1, j, k + 1);
		q.push({ {i + 1, j}, k + 1 });
	}
	if (c)
	{
		//rec(i, j - 1, k + 1);
		q.push({ {i, j - 1}, k + 1 });
	}
	if (d)
	{
		//rec(i, j + 1, k + 1);
		q.push({ {i, j + 1}, k + 1 });
	}
	while (!q.empty() && aliq[q.front().first.first][q.front().first.second] <= q.front().second)
	{
		q.pop();
	}
	if (q.empty())
		return;
	rec(q.front().first.first, q.front().first.second, q.front().second);
}

void fpath(int i, int j)
{
	if (i > 0)
	{
		if (aliq[i - 1][j] == aliq[i][j] - 1)
		{
			res += 'D';
			fpath(i - 1, j);
			return;
		}
	}
	if (i < n - 1)
	{
		if (aliq[i + 1][j] == aliq[i][j] - 1)
		{
			res += 'U';
			fpath(i + 1, j);
			return;
		}
	}
	if (j > 0)
	{
		if (aliq[i][j - 1] == aliq[i][j] - 1)
		{
			res += 'R';
			fpath(i, j - 1);
			return;
		}
	}
	if (j < m - 1)
	{
		if (aliq[i][j + 1] == aliq[i][j] - 1)
		{
			res += 'L';
			fpath(i, j + 1);
			return;
		}
	}
}

int main()
{
	int i, j;
	pair<int, int>s, f;
	cin >> n >> m;
	s = f = { 0 , 0};
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			aliq[i][j] = n * m + 1;
			if (arr[i][j] == 'A')
			{
				aliq[i][j] = 0;
				s = { i, j };
			}
			else if (arr[i][j] == 'B')
			{
				f = { i, j };
			}
			else if (arr[i][j] == '#')
				aliq[i][j] = -2;
		}
	}
	//cout << s.first << ' ' << s.second << endl;
	//cout << f.first << ' ' << f.second << endl;
	rec(s.first, s.second, 0);
	if (aliq[f.first][f.second] == n * m + 1)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		fpath(f.first, f.second);
		reverse(res.begin(), res.end());
		cout << res.size() << endl;
		cout << res << endl;
	}


	return 0;
}
