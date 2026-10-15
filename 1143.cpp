#include <iostream>
#include <algorithm>
#define ll long long
#define poss pos*2
#define midd mid+1
using namespace std;

const int N = 200005;
ll pr[N], h[N], t[4 * N];
void build(ll l, ll r, ll pos)
{
	if (l == r)
	{
		pr[l] = pos;
		t[pos] = h[l];
		return;
	}
	ll mid = (l + r) / 2;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos] = max(t[poss], t[poss + 1]);
}
ll query(ll l, ll r, ll u, ll pos)
{
	ll mid = (l + r) / 2;
	if (l == r)
	{
		t[pos] -= u;
		if (t[pos] >= 0)
		{
			return l;
		}
		else
		{
			t[pos] += u;
			return -1;
		}
	}
	if (t[poss] >= u)
	{
		ll o = query(l, mid, u, poss);
		t[pos] = max(t[poss], t[poss + 1]);
		return o;
	}
	else if (t[poss + 1] >= u)
	{
		ll o = query(midd, r, u, poss + 1);
		t[pos] = max(t[poss], t[poss + 1]);
		return o;
	}
	else
	{
		return -1;
	}
}
int main()
{
	ll i, j, k, l, n, m, o, p;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	build(0, n - 1, 1);
	while (m--)
	{
		ll u;
		cin >> u;
		k = query(0, n - 1, u, 1);
		cout << k + 1 << ' ';
	}

	return  0;
}