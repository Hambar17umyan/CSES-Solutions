#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int arr[N];
char op[N];
int a[N], b[N];
map<int, int> subs;
int cnt[3 * N];

int tree[4 * 3 * N];
int prr[3 * N];

void build(int l, int r, int pos) {
	if (l == r) {
		tree[pos] = cnt[l];
		prr[l] = pos;
		return;
	}

	int mid = (l + r) / 2;
	build(l, mid, 2 * pos);
	build(mid + 1, r, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
}

int query(int l, int r, int tl, int tr, int pos) {
	if (tl == l && r == tr) {
		return tree[pos];
	}

	int middle = (tl + tr) / 2;

	if (r < middle + 1) {
		return query(l, r, tl, middle, 2 * pos);
	}
	if (l > middle) {
		return query(l, r, middle + 1, tr, 2 * pos + 1);
	}

	return query(l, middle, tl, middle, 2 * pos) + query(middle + 1, r, middle + 1, tr, 2 * pos + 1);
}

void update(int idx, int val) {
	int pos = prr[idx];
	tree[pos] = val;
	pos /= 2;
	while (pos > 0) {
		tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
		pos /= 2;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> all;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		all.push_back(arr[i]);
	}

	for (int i = 0; i < m; i++) {
		cin >> op[i];
		cin >> a[i] >> b[i];
		if (op[i] == '!') {
			all.push_back(b[i]);
		}
		else {
			all.push_back(a[i]);
			all.push_back(b[i]);
		}
	}

	sort(all.begin(), all.end());
	for (int i = 1; i <= all.size(); i++) {
		subs[all[i - 1]] = i;
	}

	for (int i = 0; i < n; i++) {
		cnt[subs[arr[i]]]++;
	}

	build(1, all.size(), 1);

	for (int i = 0; i < m; i++) {
		if (op[i] == '!') {
			int old_val = subs[arr[a[i] - 1]];
			int new_val = subs[b[i]];

			cnt[old_val]--;
			cnt[new_val]++;
			update(old_val, cnt[old_val]);
			update(new_val, cnt[new_val]);
			arr[a[i] - 1] = b[i];
		}
		else {
			cout << query(subs[a[i]], subs[b[i]], 1, all.size(), 1) << "\n";
		}
	}
}