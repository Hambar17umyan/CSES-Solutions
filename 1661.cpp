#include <iostream>
#include <map>
#include <vector>
#define ll long long
using namespace std;

map<ll, ll>mp;
int main()
{
	ll i, j, x, l, k, m, n, o, p;
	cin >> n >> x;
	ll res = 0;
	k = 0;
	for (i = 0; i < n; i++)
	{
		cin >> o;
		k += o;
		if (k == x)
		{
			res++;
		}
		l = k - x;
		res += mp[l];
		mp[k]++;
	}
	cout << res;

	return 0;
}