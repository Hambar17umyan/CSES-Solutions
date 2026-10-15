
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
 
bool attack(int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
		return true;
	if (y1 == y2)
		return true;
	if (abs(y1 - y2) == abs(x1 - x2))
		return true;
	return false;
}
 
bool arr[10][10];
set<pair<int, int>>queens;
ll res = 0;
 
void btrack(int x)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		if (arr[x][i])
		{
			bool canstand = true;
			for (set<pair<int, int>>::iterator it = queens.begin(); it != queens.end(); it++)
			{
				if (attack((*it).first, (*it).second, x, i))
				{
					canstand = false;
					break;
				}
			}
			if (canstand)
			{
				queens.insert(make_pair(x, i));
				
				if (x < 7)
				{
					btrack(x + 1);
				}
				else
				{
					res++;
				}
				queens.erase(make_pair(x, i));
			}
		}
	}
}
 
void solve()
{
	int i, j, n;
	n = 8;
	char c;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> c;
			if (c == '.')
				arr[i][j] = true;
		}
	}
	btrack(0);
	cout << res;
}
 
int main()
{
	speed;
 
	single;
	multi;
	return 0;
}
