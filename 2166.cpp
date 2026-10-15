#include <iostream>
using namespace std;
typedef long long ll;

#define midd mid + 1
#define middle int mid = (l + r) / 2
#define poss pos * 2

struct seg {
	ll pref, sum;
};

const int N = 200005;
seg t[4 * N];
ll arr[N], prr[N];
ll zer = 0;

void build(int l, int r, int pos)
{
	if (l == r)
	{
		t[pos].pref = max(zer, arr[r]);
		t[pos].sum = arr[r];
		prr[l] = pos;
		return;
	}
	middle;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos].pref = max(t[poss].pref, t[poss].sum + t[poss + 1].pref);
	t[pos].sum = t[poss].sum + t[poss + 1].sum;
}

seg query(int l, int r, int ql, int qr, int pos)
{
	if (l == ql && r == qr)
	{
		return t[pos];
	}
	middle;
	if (qr < midd)
	{
		return query(l, mid, ql, qr, poss);
	}
	if (ql > mid)
	{
		return query(midd, r, ql, qr, poss + 1);
	}
	seg s1, s2;
	s1 = query(l, mid, ql, mid, poss);
	s2 = query(midd, r, midd, qr, poss + 1);
	seg res;
	res.sum = s1.sum + s2.sum;
	res.pref = max(s1.pref, s1.sum + s2.pref);
	return res;
}

void update(int k, ll u)
{
	k--;
	arr[k] = u;
	int pos = prr[k];
	t[pos].sum = u;
	t[pos].pref = max(zer, u);
	pos /= 2;
	while (pos)
	{
		t[pos].pref = max(t[poss].pref, t[poss].sum + t[poss + 1].pref);
		t[pos].sum = t[poss].sum + t[poss + 1].sum;
		pos /= 2;
	}
}

int main()
{
	int n, q, i;
	cin >> n >> q;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	build(0, n - 1, 1);
	while (q--)
	{
		int a, b;
		short op;
		cin >> op;
		cin >> a >> b;
		if (op == 1)
		{
			update(a, b);
		}
		else
		{
			a--;
			b--;
			cout << query(0, n - 1, a, b, 1).pref << endl;
		}
	}

	return 0;
}
