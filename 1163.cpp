#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, n;
	cin >> x >> n;
	set<pair<int, pair<int, int>>>st;
	st.insert({ -x, {0, x} });
 
	set<int>spots, minspots;
	spots.insert(0);
	spots.insert(x);
	minspots.insert(0);
	minspots.insert(-x);
 
	while (n--) {
		int a;
		cin >> a;
		
		auto leftit = minspots.upper_bound(-a);
		auto rightit = spots.upper_bound(a);
		pair<int, int>seg = { -*leftit, *rightit };
 
		st.erase({ -seg.second + seg.first ,seg });
		st.insert({ -a + seg.first, { seg.first, a } });
		st.insert({ -seg.second + a, { a, seg.second } });
 
		auto tp = *st.begin();
 
		cout << -tp.first << " ";
 
		spots.insert(a);
		minspots.insert(-a);
	}
 
	return 0;
}