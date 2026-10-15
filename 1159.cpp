#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

struct Book {
	ll pages;
	ll price;
	ll quantity;
};

struct BookGroup {
	ll pages;
	ll price;
};

bool operator < (const BookGroup& a, const BookGroup& b) {
	return a.pages < b.pages;
}

const int N = 105;
Book books[N];
ll dp[100010];

int main() {
	ll n;
	ll x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> books[i].price;
	}

	for (int i = 0; i < n; i++) {
		cin >> books[i].pages;
	}

	for (int i = 0; i < n; i++) {
		cin >> books[i].quantity;
	}

	vector<BookGroup>arr;
	for (int i = 0; i < n; i++) {
		ll q = books[i].quantity;
		for (ll k = 1; k <= q; k <<= 1) {
			q -= k;
			arr.push_back({books[i].pages * k, books[i].price * k});
		}

		if (q > 0) {
			arr.push_back({ books[i].pages * q, books[i].price * q});
		}
	}

	sort(arr.begin(), arr.end());

	for (int i = arr.size() - 1; i >= 0; i--) {
		if (arr[i].price > x)
			continue;
		for (ll j = x; j >= 0; j--) {
			if (arr[i].price + j > x)
				continue;

			dp[arr[i].price + j] = max(dp[arr[i].price + j], dp[j] + arr[i].pages);
		}

		dp[arr[i].price] = max(dp[arr[i].price], arr[i].pages);
	}

	ll mx = 0;
	for (int i = 0; i <= x; i++) {
		mx = max(mx, dp[i]);
	}
	cout << mx << endl;

	return 0;
}