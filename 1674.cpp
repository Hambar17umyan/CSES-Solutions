#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;
int p[N];
vector<int>c[N];
int res[N];

int lynx(int ind)
{
	int r = 0;
	for (int i = 0; i < c[ind].size(); i++)
	{
		res[c[ind][i]] = lynx(c[ind][i]);
		r += res[c[ind][i]] + 1;
	}
	return r;
}
int main()
{
	int n;
	cin >> n;
	int i;
	for (i = 1; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
		c[p[i]].push_back(i);
	}
	res[0] = lynx(0);
	for (i = 0; i < n; i++)
		cout << res[i] << ' ';

	return 0;
}
