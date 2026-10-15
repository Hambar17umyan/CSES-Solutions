#define ll long long
#define midd mid + 1
#define poss pos*2
#include <iostream>
#include <queue>
using namespace std;

const int N = 200005;
ll arr[N], t[4 * N], prr[N];
void build(ll l, ll r, ll pos)
{
	if (l == r)
	{
		prr[l] = pos;
		t[pos] = 1;
		return;
	}
	ll mid = (l + r) / 2;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos] = t[poss] + t[poss + 1];
}
ll rr;
void del(int l, int r, int k, int pos)
{
	if (l == r)
	{
		rr = l;
		t[pos] = 0;
		return;
	}
	ll mid = (l + r) / 2;
	if (t[poss] >= k)
	{
		del(l, mid, k, poss);
		t[pos]--;
		return;
	}
	else
	{
		del(midd, r, k - t[poss], poss + 1);
		t[pos]--;
		return;
	}
}
int main()
{
	ll i, j, k, l, m, n, o, p;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build(0, n - 1, 1);
	m = n;
	while (m--)
	{
		cin >> k;
		del(0, n - 1, k, 1);
		cout << arr[rr] << ' ';
	}

	return 0;
}