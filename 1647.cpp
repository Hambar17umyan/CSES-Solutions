#include <iostream>
using namespace std;
#define ll long long

ll n, tree[800002], arr[200002];

void build(ll l, ll r, ll pos)
{
	if (l == r)
	{
		tree[pos] = arr[l];
		return;
	}
	ll mid = (l + r) / 2;
	build(l, mid, pos * 2);
	build(mid + 1, r, pos * 2 + 1);
	tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
}

ll query(ll l, ll r, ll tl, ll tr, ll pos)
{
	if (l == tl && r == tr)
	{
		return tree[pos];
	}
	ll mid = (tr + tl) / 2;
	if (r <= mid)
	{
		return query(l, r, tl, mid, pos * 2);
	}
	if (l > mid)
	{
		return query(l, r, mid + 1, tr, pos * 2 + 1);
	}
	return min(query(l, mid, tl, mid, pos * 2), query(mid + 1, r, mid + 1, tr, pos * 2 + 1));

}

int main()
{
	ll m, i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build(0, n - 1, 1);
	while (m--)
	{
		ll o, p;
		cin >> o >> p;
		o--;
		p--;
		cout << query(o, p, 0, n - 1, 1) << endl;
	}

	return 0;
}