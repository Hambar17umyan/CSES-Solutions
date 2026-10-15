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
ll arr[200005];
void solve()
{
	set<ll>st;
	ll i, j, k, m, n;
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}
	i = j = 0;
	st.insert(arr[0]);
	mp[arr[0]]++;
	j = 1;
	ll res = 0;
	st.insert(arr[j]);
	mp[arr[1]]++;
	while (true)
	{
		if (st.size() > k)
		{
			res += j - i;
			mp[arr[i]]--;
			if (mp[arr[i]] == 0)
			{
				st.erase(arr[i]);
			}
			i++;
			continue;
		}
		if (j < n - 1)
		{
			mp[arr[j + 1]]++;
			st.insert(arr[j + 1]);
			j++;
		}
		else
		{
			res += j - i + 1;
			if (i == j)
				break;
			i++;
		}
	}
	cout << res << endl;
}
 
int main()
{
	speed;
 
	single;
	multi;
	return 0;
}
