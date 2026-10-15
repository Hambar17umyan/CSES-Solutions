#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
 
char arr[1005][1005];
int aliq[1005][1005];
int alo[1005][1005];
int main()
{
	int i, j, n, m, k;
	cin >> n >> m;
	pair<int, int>start;
	queue<pair<pair<int, int>, int>>q;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'A')
				start = { i, j };
			aliq[i][j] = 100000000;
			alo[i][j] = 100000000;
			if (arr[i][j] == 'M')
				q.push(make_pair(make_pair(i, j), 0));
 
		}
	}
	while (!q.empty())
	{
		pair<int, int>cell;
		int y;
		cell = q.front().first;
		y = q.front().second;
		q.pop();
		if (aliq[cell.first][cell.second] <= y)
		{
			continue;
		}
		i = cell.first;
		j = cell.second;
		aliq[i][j] = y;
		if (i < n - 1)
		{
			if (arr[i + 1][j] != '#' && aliq[i + 1][j] > aliq[i][j] + 1)
			{
				q.push({ make_pair(i + 1, j), y + 1 });
			}
		}
 
		if (j < m - 1)
		{
			if (arr[i][j + 1] != '#' && aliq[i][j + 1] > aliq[i][j] + 1)
			{
				q.push({ make_pair(i,  j + 1), y + 1 });
			}
		}
 
		if (i > 0)
		{
			if (arr[i - 1][j] != '#' && aliq[i - 1][j] > aliq[i][j] + 1)
			{
				q.push({ make_pair(i - 1, j), y + 1 });
			}
		}
 
		if (j > 0)
		{
			if (arr[i][j - 1] != '#' && aliq[i][j - 1] > aliq[i][j] + 1)
			{
				q.push({ make_pair(i,  j - 1), y + 1 });
			}
		}
	}
	q.push(make_pair(start, 0));
	while (!q.empty())
	{
		pair<int, int>cell;
		int y;
		cell = q.front().first;
		y = q.front().second;
		q.pop();
		if (alo[cell.first][cell.second] <= y)
		{
			continue;
		}
		i = cell.first;
		j = cell.second;
		alo[i][j] = y;
		if (i < n - 1)
		{
			if (arr[i + 1][j] != '#' && alo[i + 1][j] > alo[i][j] + 1 && alo[i][j] + 1 < aliq[i + 1][j])
			{
				q.push({ make_pair(i + 1, j), y + 1 });
			}
		}
 
		if (j < m - 1)
		{
			if (arr[i][j + 1] != '#' && alo[i][j + 1] > alo[i][j] + 1 && alo[i][j] + 1 < aliq[i][j + 1])
			{
				q.push({ make_pair(i,  j + 1), y + 1 });
			}
		}
 
		if (i > 0)
		{
			if (arr[i - 1][j] != '#' && alo[i - 1][j] > alo[i][j] + 1 && alo[i][j] + 1 < aliq[i - 1][j])
			{
				q.push({ make_pair(i - 1, j), y + 1 });
			}
		}
 
		if (j > 0)
		{
			if (arr[i][j - 1] != '#' && alo[i][j - 1] > alo[i][j] + 1 && alo[i][j] + 1 < aliq[i][j - 1])
			{
				q.push({ make_pair(i,  j - 1), y + 1 });
			}
		}
	}
	pair<int, int>o = start;
	start = { -1, -1 };
	for (i = 0; i < n; i++)
	{
		if (alo[i][0] != 100000000)
		{
			start = { i, 0 };
			break;
		}
		if (alo[i][m - 1] != 100000000)
		{
			start = { i, m - 1 };
			break;
		}
	}
	for (i = 0; i < m; i++)
	{
		if (alo[0][i] != 100000000)
		{
			start = { 0, i };
			break;
		}
		if (alo[n - 1][i] != 100000000)
		{
			start = { n - 1, i };
			break;
		}
	}
	if (start == make_pair(-1, -1))
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		cout << alo[start.first][start.second] << endl;
		pair<int, int>u;
		u = start;
		string s = "";
		while (u != o)
		{
			i = u.first;
			j = u.second;
			if (i < n - 1 && alo[i + 1][j] == alo[u.first][u.second] - 1)
			{
				s += 'U';
				u.first++;
			}
 
			else if (j < m - 1 && alo[i][j + 1] == alo[u.first][u.second] - 1)
			{
				s += 'L';
				u.second++;
			}
 
			else if (i > 0 && alo[i - 1][j] == alo[u.first][u.second] - 1)
			{
				s += 'D';
				u.first--;
			}
 
			else if (j > 0 && alo[i][j - 1] == alo[u.first][u.second] - 1)
			{
				s += 'R';
				u.second--;
			}
		}
		reverse(s.begin(), s.end());
		cout << s;
	}
	cout << endl;
	/*for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << aliq[i][j] << ' ';
		}
		cout << endl;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << alo[i][j] << ' ';
		}
		cout << endl;
	}*/
 
	return 0;
}
