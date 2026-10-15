#include <iostream>
using namespace std;
#define ll long long
#define poss pos * 2
#define midd mid+1

const int N = 200005;
ll tree[4 * N], arr[N], parr[N];
void build(ll l, ll r, ll pos)
{
	if (l == r)
	{
		tree[pos] = arr[l];
		parr[l] = pos;
		return;
	}
	ll mid = (l + r) / 2;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	tree[pos] = min(tree[poss], tree[poss + 1]);
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
		return query(l, r, tl, mid, poss);
	}
	if (l > mid)
	{
		return query(l, r, midd, tr, poss + 1);
	}
	return min(query(l, mid, tl, mid, poss), query(midd, r, midd, tr, poss + 1));
}

void change(ll ind, ll val)
{
	ll p = parr[ind];
	tree[p] = val;
	p /= 2;
	while (p)
	{
		tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
		p /= 2;
	}
}

int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build(0, n - 1, 1);
	while (m--)
	{
		short u;
		ll a, b;
		cin >> u >> a >> b;
		a--;
		if (u - 1)
		{
			b--;
			cout << query(a, b, 0, n - 1, 1) << endl;
		}
		else
		{
			change(a, b);
		}
	}

	return 0;
}