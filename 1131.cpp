#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
const int N = 200005;
vector<int>g[N], child[N];
bool color[N];
int arr[N];
 
void dfs(int a)
{
	color[a] = true;
	for (int i = 0; i < g[a].size(); i++)
	{
		if (!color[g[a][i]])
		{
			child[a].push_back(g[a][i]);
			dfs(g[a][i]);
		}
	}
}
int r = 0;
void auslander(int a)
{
	if (child[a].size() == 0)
	{
		arr[a] = 0;
		return;
	}
	int i;
	for (i = 0; i < child[a].size(); i++)
	{
		auslander(child[a][i]);
		arr[a] = max(arr[a], arr[child[a][i]] + 1);
	}
	priority_queue<int>p;
	for (i = 0; i < child[a].size(); i++)
	{
		p.push(arr[child[a][i]]);
	}
	if (p.size() == 1)
	{
		r = max(r, p.top() + 1);
	}
	else
	{
		int j = p.top();
		p.pop();
		j += p.top() + 2;
		r = max(j, r);
	}
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
	auslander(0);
	cout << r;
 
	return 0;
}
