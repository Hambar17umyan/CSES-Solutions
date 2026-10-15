#include <iostream>
using namespace std;
#define ll long long
#define poss pos*2
#define midd mid+1

const int N = 200005;
ll t[4 * N], arr[N], prr[N];
void build(ll l, ll r, ll pos)
{
	if (l == r)
	{
		t[pos] = arr[l];
		prr[l] = pos;
		return;
	}
	ll mid = (l + r) / 2;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos] = 0;
}
ll query(ll pos)
{
	ll k = 0;
	while (pos)
	{
		k += t[pos];
		pos /= 2;
	}
	return k;
}
void update(ll l, ll r, ll tl, ll tr, ll u, ll pos)
{
	ll mid = (tl + tr) / 2;
	if (l == tl && r == tr)
	{
		t[pos] += u;
		return;
	}
	if (r <= mid)
	{
		update(l, r, tl, mid, u, poss);
		return;
	}
	if (l > mid)
	{
		update(l, r, midd, tr, u, poss + 1);
		return;
	}
	update(l, mid, tl, mid, u, poss);
	update(midd, r, midd, tr, u, poss + 1);
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
		cin >> k;
		if (k == 2)
		{
			cin >> l;
			l--;
			cout << query(prr[l]) << endl;
		}
		else
		{
			cin >> o >> p >> l;
			o--;
			p--;
			update(o, p, 0, n - 1, l, 1);
		}
	}

	return 0;
}