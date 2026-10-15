#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
pair<ll, ll> arr[N];
int main() {
	int n;
	cin >> n;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		res += arr[i].second;
	}

	sort(arr, arr + n, greater<pair<ll, ll>>());
	ll k = 1;
	for (int i = 0; i < n; i++) {
		res -= arr[i].first * k;
		k++;
	}

	cout << res;

	return 0;
}