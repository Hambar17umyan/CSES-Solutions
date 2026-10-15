#include <iostream>
#include <set>
typedef long long ll;
using namespace std;
 
int main() {
	int n, m;
	ll k;
	cin >> n >> m;
	multiset<ll>st;
	for (int i = 0; i < n; i++) {
		cin >> k;
		st.insert(-k);
	}
 
	for (int i = 0; i < m; i++) {
		cin >> k;
		auto it = st.lower_bound(-k);
		if (it != st.end()) {
			cout << -*it << endl;
			st.erase(it);
		}
		else {
			cout << -1 << endl;
		}
	}
}