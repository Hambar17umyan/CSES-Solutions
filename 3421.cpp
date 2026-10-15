#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
 
int main() {
	ll n;
	map<ll, ll>mp;
 
	cin >> n;
	ll k;
 
	for (int i = 0; i < n; i++) {
		cin >> k;
		mp[k]++;
	}
 
	ll res = 1;
	ll mod = 1e9 + 7;
	for (auto it : mp) {
		res = (res * (it.second + 1)) % mod;
	}
	res--;
	if (res == 0)
		cout << 1 << endl;
	else cout << res << endl;
 
	return 0;
}