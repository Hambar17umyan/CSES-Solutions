#include <iostream>
#include <algorithm>
#include <math.h>
#include <sstream>
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
 
//defines
#define ll long long
#define usg unsigned
#define kap map
#define print(x, n) for(int for_loop = 0; for_loop < n; for_loop++){cout<<x[for_loop]<<' ';}cout<<endl; 
#define read(x, n) for(int for_loop = 0; for_loop < n; for_loop++){cin>>x[for_loop];} 
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ratdig(x) cout << fixed << setprecision(x);
#define xfixdig(x) cout << setprecision(x);
#define multi int t; cin>>t; presolve(); while(t--) solve()
#define single presolve(); solve(); return 0
#define rev(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()
 
//functions
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
	for (ll i = a; i > 0; )
	{
		ll k = i % 2;
		i /= 2;
		char c = k + 48;
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
 
//body
 
void presolve()
{
 
}
 
ll arr[10005];
void solve()
{
	ll i, j, k, m, n;
	cin >> n;
	arr[0] = arr[1] = arr[2] = 0;
	cout << 0 << endl;
	if (n == 1)
		return;
	cout << 6 << endl;
	if (n == 2)
		return;
	cout << 28 << endl;
	if (n == 3)
		return;
	arr[3] = 8;
	for (i = 4; i <= n; i++)
	{
		m = binpow(i, 2);
		m *= (m - 1);
		m /= 2;
		k = 0;
		k += 2 * 2 + 2 * 3;
		k += (i - 4) * 4;
		k += 2 * 2;
		if (i == 4)
			k += 2;
		else
		{
			k += 3 * 2;
			k += (i - 5) * 4;
		}
		arr[i] = k + arr[i - 1];
		cout << m - arr[i] << endl;
	}
}
 
int main()
{
	speed;
	single;
	multi;
 
	return 0;
}