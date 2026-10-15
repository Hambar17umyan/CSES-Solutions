#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <iterator>
using namespace std;
 
typedef long long ll;
typedef unsigned usg;
 
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define multi int t; cin>>t; while(t--) solve()
#define single solve(); return 0
#define ratdig(x) cout << fixed << setprecision(x);
#define xfixdig(x) cout << setprecision(x);
#define rev(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()
 
void yn(bool b)
{
	if (b)
	{
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}
 
ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return gcd(b % a, a);
}
 
ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}
 
string to2(ll a)
{
	string r = "";
	for (ll i = 0; (1 << i) <= a; i++)
	{
		char c = (((1 << i) & a) != 0) + '0';
		r += c;
	}
	if (a == 0)
	{
		r = "0";
	}
	rev(r);
 
	return r;
}
 
ll binpow(ll a, ll b, ll mod = -1)
{
	ll ans = 1;
	while (b)
	{
		if ((b & 1) == 1)
		{
			ans *= a;
			if (mod != -1)
				ans %= mod;
		}
		b >>= 1;
		a *= a;
		if (mod != -1)
			a %= mod;
	}
	return ans;
}
 
map<ll, ll>mp;
void solve()
{
	ll i, j, k, m, n;
	cin >> n >> m;
	mp[0] = 1;
	k = 0;
	cin >> k;
	j = 0;
	if (k == m)
		j++;
	mp[k]++;
	for (i = 1; i < n; i++)
	{
		ll w;
		cin >> w;
		k += w;
		mp[k]++;
		if (w > m)
			continue;
		if (k < m)
			continue;
		j += mp[k - m];
	}
	cout << j;
}
 
int main()
{
	speed;
 
	single;
	multi;
	return 0;
}
