#include <iostream>
#include <set>
typedef long long ll;
using namespace std;
 
int arr[200005];
 
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
 
	set<int>st;
	ll start = 0;
	st.insert(arr[0]);
	ll res = 0;
	ll i;
 
	for (i = 1; i < n; i++) {
		if (st.find(arr[i]) != st.end()) {
			for (; start < i; start++) {
				res += i - start;
				st.erase(arr[start]);
 
				if (arr[start] == arr[i]) {
					start++;
					break;
				}
			}
		}
		st.insert(arr[i]);
 
	}
 
	ll w = n - start;
	res += w + (w * (w - 1)) / 2;
 
	cout << res << endl;
 
	return 0;
}