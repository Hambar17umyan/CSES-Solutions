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
 
string to2(ll a, ll n = -1)
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
	if (n != -1)
	{
		for (int i = 0; i < n - r.size(); i++)
			r += '0';
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
 
void solve()
{
	ll i, j, k, m, n;
	cin >> n;
	ll sum = (n * (n + 1)) / 2;
	if (sum % 2)
	{
		yn(0);
		return;
	}
	yn(1);
	if (n % 2)
	{
		n--;
		cout << n / 2 + 1 << endl;
		for (i = 1; i <= n / 2; i += 2)
			cout << i << ' ';
		for (i = n; i >= n / 2; i -= 2)
			cout << i << ' ';
		cout << endl;
		cout << n - n / 2 << endl;
		for (i = 2; i <= n / 2; i += 2)
			cout << i << ' ';
		for (i = n - 1; i > n / 2; i -= 2)
			cout << i << ' ';
		cout << n + 1 << endl;
	}
	else
	{
		cout << n / 2 << endl;
		for (i = 1; i <= n / 2; i += 2)
			cout << i << ' ';
		for (i = n; i > n / 2; i -= 2)
			cout << i << ' ';
		cout << endl;
		cout << n / 2 << endl;
		for (i = 2; i <= n / 2; i += 2)
			cout << i << ' ';
		for (i = n - 1; i >= n / 2; i -= 2)
			cout << i << ' ';
		cout << endl;
	}
}
 
int main()
{
	speed;
 
	single;
	multi;
	return 0;
}
