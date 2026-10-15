#include <iostream>
#include <vector>
using namespace std;
 
const int N = 200005;
vector<int>children[N], g[N];
int parent[N];
bool color[N], baxt[N];
void dfs(int a)
{
	color[a] = true;
	for (int i = 0; i < g[a].size(); i++)
	{
		if (!color[g[a][i]])
		{
			parent[g[a][i]] = a;
			children[a].push_back(g[a][i]);
			dfs(g[a][i]);
		}
	}
}
 
int r = 0;
void auslander(int a)
{
	if (children[a].size() == 0)
	{
		return;
	}
	bool u = false;
	for (int i = 0; i < children[a].size(); i++)
	{
		auslander(children[a][i]);
		if (baxt[children[a][i]] == false)
		{
			u = true;
		}
	}
	if (u)
		r++;
	baxt[a] = u;
}
 
int main()
{
	int i, j, n, m, k;
	cin >> n;
	int a, b;
	for (i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	/*for (i = 0; i < n; i++)
	{
		for (j = 0; j < children[i].size(); j++)
			cout << children[i][j] << ' ';
		cout << endl;
	}*/
	auslander(0);
	/*for (i = 0; i < n; i++)
		cout << baxt[i] << ' ';
	cout << endl;*/
	cout << r;
 
 
	return 0;
}
