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
#define middle ll mid = (l + r)/2
#define midd mid + 1
#define poss pos * 2
#define posss poss + 1
 
const int N = 200005;
ll arr[N], t1[4 * N], t2[4 * N], prr[N];
void build(ll l, ll r, ll pos)
{
	middle;
	if (l == r)
	{
		prr[r] = pos;
		t1[pos] = arr[r] - r;
		t2[pos] = arr[r] + r;
		return;
	}
	build(l, mid, poss);
	build(midd, r, posss);
	t1[pos] = min(t1[poss], t1[posss]);
	t2[pos] = min(t2[poss], t2[posss]);
}
 
ll query(ll l, ll r, ll ql, ll qr, ll pos, bool b)
{
	middle;
	if (b)
	{
		if (l == ql && qr == r)
		{
			return t2[pos];
		}
	}
	else
	{
		if (l == ql && qr == r)
		{
			return t1[pos];
		}
	}
	if (qr < midd)
	{
		return query(l, mid, ql, qr, poss, b);
	}
	if (ql > mid)
	{
		return query(midd, r, ql, qr, posss, b);
	}
	return min(query(midd, r, midd, qr, posss, b), query(l, mid, ql, mid, poss, b));
}
 
void update(ll i, ll k)
{
	arr[i] = k;
	ll pos = prr[i];
	t1[pos] = k - i;
	t2[pos] = k + i;
	pos /= 2;
	while (pos)
	{
		t1[pos] = min(t1[poss], t1[posss]);
		t2[pos] = min(t2[poss], t2[posss]);
		pos /= 2;
	}
}
 
void solve()
{
	ll i, j, k, n, m;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	short op;
	build(0, n - 1, 1);
	while (m--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> i >> k;
			i--;
			update(i, k);
		}
		else
		{
			cin >> k;
			k--;
			cout << min(query(0, n - 1, 0, k, 1, 0) + k, query(0, n - 1, k, n - 1, 1, 1) - k) << endl;
		}
	}
}
 
int main()
{
	speed;
	single;
	multi;
 
	return 0;
}
