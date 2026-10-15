#include <iostream>
#include <vector>
using namespace std;
 
vector<int>g[200005];
short res[200005];
 
bool dfs(int k, int x)
{
	int i;
	res[k] = x;
	int n = g[k].size();
	for (i = 0; i < n; i++)
	{
		if (res[g[k][i]] == 0)
		{
			bool p = dfs(g[k][i], 2 - x + 1);
			if (!p)
				return false;
		}
		else if (res[g[k][i]] == x)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int m, i, j, n, k;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (i = 0; i < n; i++)
	{
		if (res[i] == 0)
		{
			if (dfs(i, 1) == 0)
			{
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}
	for (i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << endl;
 
	return 0;
}
