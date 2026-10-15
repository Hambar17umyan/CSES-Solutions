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
 
ll arr[1004][1004];
 
void solve()
{
	int m, n, i, j, k;
	cin >> n >> m;
	char c;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> c;
			if (c == '*')
			{
				arr[i][j] = 1;
			}
			if (i == 0)
			{
				if (j > 0)
				{
					arr[i][j] += arr[i][j - 1];
				}
			}
			else
			{
				if (j == 0)
				{
					arr[i][j] += arr[i - 1][j];
				}
				else
				{
					arr[i][j] += arr[i - 1][j];
					arr[i][j] += arr[i][j - 1];
					arr[i][j] -= arr[i - 1][j - 1];
				}
			}
		}
	}
	ll x1, x2, y1, y2;
	while (m--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;
		k = arr[x2][y2];
		if (x1 > 0)
		{
			if (y1 > 0)
			{
				k -= arr[x1 - 1][y2] + arr[x2][y1 - 1];
				k += arr[x1 - 1][y1 - 1];
			}
			else
			{
				k -= arr[x1 - 1][y2];
			}
		}
		else
		{
			if (y1 > 0)
			{
				k -= arr[x2][y1 - 1];
			}
		}
		cout << k << endl;
	}
 }
 
int main()
{
	speed;
	single;
	multi;
	return 0;
} 
