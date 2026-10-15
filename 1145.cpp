#include <iostream>
#include <vector>
using namespace std;

int arr[200005];
int main()
{
	int n, i, k, inf = 1e9 + 4;;
	cin >> n;
	vector<int>v(n + 1, inf);
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		*lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
	}
	for (i = 0; i <= n; i++)
	{
		if (v[i] == inf)
		{
			cout << i;
			return 0;
		}
	}

	return 0;
}