#include <iostream>
#define ll long long
using namespace std;
//segment tree

ll arr[200005], tree[800005];
ll n;
void build(ll l, ll r, ll pos)
{
	if (l == r)
	{
		tree[pos] = arr[l];
		return;
	}
	else
	{
		ll mid = (l + r) / 2;
		build(l, mid, pos * 2);
		build(mid+ 1, r, pos * 2 + 1);
		tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	}
}
ll query(ll l, ll r, ll tl, ll tr, ll pos)
{
	if (l == tl && r == tr)
	{
		return tree[pos];
	}
	ll mid = (tl + tr) / 2;
	if (r <= mid)
	{
		return query(l, r, tl, mid, pos * 2);
	}
	if (l > mid)
	{
		return query(l, r, mid + 1, tr, pos * 2 + 1);
	}
	return query(l, mid, tl, mid, pos * 2) + query(mid + 1, r, mid + 1, tr, pos * 2 + 1);
}

int main()
{
	ll i, j, k, l, m, o, p;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build(0, n - 1, 1);
	while (m--)
	{
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << query(a, b, 0, n - 1, 1) << '\n';
	}

	return 0;
}