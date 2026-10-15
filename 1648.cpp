#include <iostream>
using namespace std;
#define ll long long

ll n;
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
	build(l, mid, pos*2);
	build(mid + 1, r, pos * 2 + 1);
	tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
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

void change(ll ind, ll val)
{
	ll p = parr[ind];
	ll y = tree[p] - val;
	while (p)
	{
		tree[p] -= y;
		p /= 2;
	}
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
		short u;
		cin >> u;
		ll a, b;
		cin >> a >> b;
		if (u == 1)
		{
			a--;
			change(a, b);
		}
		else
		{
			a--;
			b--;
			cout << query(a, b, 0, n - 1, 1) << endl;
		}
	}

	return 0;
}