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
 
const int N = 200005;
vector<int>g[N], child[N];
bool color[N];
ll dz[N], dp[N], par[N];
ll dfs(int a, int k)
{
	color[a] = true;
	ll w = 1;
	for (int i = 0; i < g[a].size(); i++)
	{
		if (!color[g[a][i]])
		{
			child[a].push_back(g[a][i]);
			par[g[a][i]] = a;
			w += dfs(g[a][i], k + 1);
		}
	}
	dz[a] = w - 1;
	dp[0] += k;
	return w;
}
void auslander(int a, int k)
{
	dp[a] = dp[par[a]] + k - dz[a];
	k++;
	for (ll i = 0; i < child[a].size(); i++)
	{
		auslander(child[a][i], k + dz[a] - dz[child[a][i]] - 1);
	}
}
 
void solve()
{
	ll n, m, i, j, k, r;
	cin >> n;
	ll a, b;
	for (i = 0; i < n - 1; i++)
	{
		//d[i] = d[i + 1] = -1;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, 0);
	k = 0;
	a = 0;
	for (ll i = 0; i < child[a].size(); i++)
	{
		auslander(child[a][i], k + dz[a] - dz[child[a][i]] - 1);
	}
	/*for (i = 0; i < n; i++)
		cout << dz[i] << ' ';
	cout << endl;*/
	for (i = 0; i < n; i++)
		cout << dp[i] << ' ';
}
 
int main()
{
	speed;
	single;
	multi;
 
	return 0;
}
