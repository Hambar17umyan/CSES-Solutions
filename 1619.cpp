#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
using namespace std;

map<int, int>v;
int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> o >> p;
		v[o]++;
		v[p + 1]--;
	}
	ll ans = 0;
	k = 0;
	for (map<int, int>::iterator it = v.begin(); it != v.end(); it++)
	{
		k += it->second;
		if (k > ans)
			ans = k;
	}
	cout << ans;

	return 0;
}