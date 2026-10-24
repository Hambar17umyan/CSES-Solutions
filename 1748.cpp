#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
ll arr[N];

const int MOD = 1e9 + 7;
ll t[4 * N];
ll prr[N];

void build(int l, int r, int pos) {
	int middle = (l + r) / 2;
	if (l == r)
	{
		prr[r] = pos;
		return;
	}

	build(l, middle, pos * 2);
	build(middle + 1, r, pos * 2 + 1);
}

ll query(int l, int r, int tl, int tr, int pos) {
	if (tl == l && tr == r) {
		return t[pos];
	}

	int middle = (tl + tr) / 2;

	if (r <= middle) {
		return query(l, r, tl, middle, pos * 2);
	}

	if (l > middle) {
		return query(l, r, middle + 1, tr, pos * 2 + 1);
	}

	return query(l, middle, tl, middle, pos * 2) + query(middle + 1, r, middle + 1, tr, pos * 2 + 1);
}

void update(int ind, ll val) {
	int pos = prr[ind];
	t[pos] = val;
	t[pos] %= MOD;
	pos /= 2;
	while (pos) {
		t[pos] = t[pos * 2] + t[pos * 2 + 1];
		t[pos] %= MOD;
		pos /= 2;
	}
}


int main() {
	int n;
	cin >> n;
	set<ll>st;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		st.insert(arr[i]);
	}

	map<ll, ll>mp;
	int k = 0;
	for (auto i : st) {
		mp[i] = k;
		k++;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = mp[arr[i]];
	}

	build(0, st.size() - 1, 1);

	for (int i = 0; i < n; i++) {
		ll cnt = 1 + query(0, arr[i], 0, st.size() - 1, 1);
		update(arr[i], cnt);
	}

	cout << t[1] << endl;

	return 0;
}