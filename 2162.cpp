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
 
struct baby {
	int next, prev;
};
 
baby arr[200005];
void solve()
{
	int i, j, k, m, n;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return;
	}
	k = 1;
	m = n;
	int nx, pv, link;
	i = k + 1;
	arr[1].prev = n;
	arr[1].next = 2;
 
	arr[n].prev = n - 1;
	arr[n].next = 1;
 
	for (i = 2; i < n; i++)
	{
		arr[i].next = i + 1;
		arr[i].prev = i - 1;
	}
	i = 2;
	while (m--)
	{
		cout << i << ' ';
		pv = arr[i].prev;
		nx = arr[i].next;
		arr[pv].next = nx;
		arr[nx].prev = pv;
 
		j = arr[arr[i].next].next;
		i = j;
	}
 
}
 
int main()
{
	speed;
 
	single;
	multi;
	return 0;
}
