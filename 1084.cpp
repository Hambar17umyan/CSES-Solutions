#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
 
ll arr[200005];
vector<ll>ap;
int main()
{
	ll i, n, m, k;
	cin >> n >> m >> k;
	ll res = 0;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < m; i++)
	{
		ap.push_back(0);
		cin >> ap[i];
	}
	sort(arr, arr + n);
	sort(ap.begin(), ap.end());
	int j = n - 1;
	vector<ll>::iterator it1, it2, it;
	it = ap.end();
	for (i = n - 1; i >= 0; i--)
	{
		it1 = lower_bound(ap.begin(), it, arr[i] - k);
		it2 = upper_bound(ap.begin(), it, arr[i] + k);
		ll s, f;
		s = it1 - ap.begin();
		f = (it2 - ap.begin()) - 1;
		if (s <= f)
		{
			res++;
			it = it2 - 1;
		}
	}
	cout << res;
 
	return 0;
}
