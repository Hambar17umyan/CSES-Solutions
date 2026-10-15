#include <iostream>
#define ll long long
#define poss pos * 2
#define midd mid + 1
#define middle ll mid = (l + r) / 2
using namespace std;

struct segment
{
	ll seg, suf, pref, sum;
};

ll arr[200005];
ll prr[200005];
segment t[800005];
void build(ll l, ll r, ll pos)
{
	if (l == r)
	{
		prr[r] = pos;

		ll zero = 0;
		t[pos].seg = max(arr[r], zero);
		t[pos].pref = max(zero, arr[l]);
		t[pos].suf = max(zero, arr[l]);
		t[pos].sum = arr[r];

		return;
	}
	middle;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos].seg = max(max(t[poss].seg, t[poss + 1].seg), t[poss].suf + t[poss + 1].pref);
	t[pos].pref = max(t[poss].pref, t[poss].sum + t[poss + 1].pref);
	t[pos].suf = max(t[poss + 1].suf, t[poss].suf + t[poss + 1].sum);
	t[pos].sum = t[poss].sum + t[poss + 1].sum;
}

void rebuild(ll k, ll pos)
{
	ll zero = 0;
	t[pos].seg = max(arr[k], zero);
	t[pos].pref = max(zero, arr[k]);
	t[pos].suf = max(zero, arr[k]);
	t[pos].sum = arr[k];
	pos /= 2;
	while (pos)
	{
		t[pos].seg = max(max(t[poss].seg, t[poss + 1].seg), t[poss].suf + t[poss + 1].pref);
		t[pos].pref = max(t[poss].pref, t[poss].sum + t[poss + 1].pref);
		t[pos].suf = max(t[poss + 1].suf, t[poss].suf + t[poss + 1].sum);
		t[pos].sum = t[poss].sum + t[poss + 1].sum;
		pos /= 2;
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

	//cout << t[1].seg << endl;
	while (m--)
	{
		cin >> o >> p;
		o--;
		arr[o] = p;
		rebuild(o, prr[o]);
		cout << t[1].seg << endl;
	}

	return 0;
}