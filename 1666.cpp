#include <iostream>
#include <vector>
using namespace std;

vector<int>g[100005];
bool color[100005];

void rec(int ind)
{
	int i;
	color[ind] = true;
	for (i = 0; i < g[ind].size(); i++)
	{
		if (!color[g[ind][i]])
			rec(g[ind][i]);
	}
}

int main()
{
	int i, j, n, m;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int>comp;
	
	for (i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			comp.push_back(i);
			rec(i);
		}
	}
	cout << comp.size() - 1 << endl;
	for (i = 1; i < comp.size(); i++)
	{
		cout << comp[i] << ' ' << comp[i - 1] << endl;
	}

	return 0;
}
