#include <iostream>
using namespace std;
#define ll long long
#define midd mid+1
#define poss pos*2

const int N = 200005;
ll tree[4 * N], arr[N];


void build(ll a, ll b, ll pos)
{
	if (a == b)
	{
		tree[pos] = arr[a];
		return;
	}
	ll mid = (a + b) / 2;
	build(a, mid, poss);
	build(midd, b, poss + 1);
	tree[pos] = tree[poss] ^ tree[poss + 1];
}

ll query(ll a, ll b, ll ta, ll tb, ll pos)
{
	if (a == ta && b == tb)
	{
		return tree[pos];
	}
	ll mid = (ta + tb) / 2;
	if (b <= mid)
	{
		return query(a, b, ta, mid, poss);
	}
	if (a > mid)
	{
		return query(a, b, midd, tb, poss + 1);
	}
	return (query(a, mid, ta, mid, poss) ^ query(midd, b, midd, tb, poss + 1));
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
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << query(a, b, 0, n - 1, 1) << '\n';
	}

	return 0;
}