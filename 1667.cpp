#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
 
long long INF = 100000000000000000;
 
vector<pair<int, int>> g[200005];
long long d[200005];
int w[200005];
int main() {
	int n, i, j, m;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		int a, b, k;
		cin >> a >> b;
		g[a].push_back({ b, 1 });
		g[b].push_back({ a, 1 });
	}
	for (i = 0; i < n; i++)
	{
		d[i + 1] = INF;
	}
	int s = 1;
	priority_queue<pair<long long, int>>q;
	d[s] = 0;
	w[s] = 0;
	q.push({ 0, s });
	while (!q.empty())
	{
		long long len = -q.top().first;
		int gag = q.top().second;
		q.pop();
		if (d[gag] < len)
			continue;
		for (i = 0; i < g[gag].size(); i++)
		{
			if (len + g[gag][i].second < d[g[gag][i].first])
			{
				q.push({ -len - g[gag][i].second,  g[gag][i].first });
				w[g[gag][i].first] = gag;
				d[g[gag][i].first] = len + g[gag][i].second;
			}
		}
	}
	if (d[n] == INF)
		cout << "IMPOSSIBLE\n";
	else
	{
		cout << d[n] + 1 << endl;
		int gag = n;
		stack<int>y;
		do {
			y.push(gag);
			gag = w[gag];
		} while (w[gag] != 0);
		cout << s << ' ';
		while (!y.empty())
		{
			cout << y.top() << ' ';
			y.pop();
		}
	}
 
	return 0;
}
