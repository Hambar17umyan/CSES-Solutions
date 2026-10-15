#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#define ll long long
using namespace std;

map<ll, ll>mp;
ll mod(ll a, ll b)
{
	ll k = a % b;
	if (k < 0)
		k = b + k;
	return k;
}
int main()
{
	ll i, j, x, l, k, m, n, o, p;
	//ifstream cin("test_input (2).txt");
	cin >> n;
	ll res = 0;
	ll g = 0;
	bool b = false;
	//cout << -6 % 5;
	//cout << mod(-5, 5);
	for (i = 0; i < n; i++)
	{
		cin >> o;
		//if (o == 0)
			//cout << 0;
		g += o;
		g = mod(g, n);
		k = -1000000;
		if (g == 0)
		{
			res++;
		}
		//if (mod(o, n) == 0 && o != 0)
			//res++;
		res += mp[g];
		mp[g]++;
	}
	cout << res;

	return 0;
}