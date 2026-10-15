#include <iostream>
using namespace std;

int main()
{
	int n, i;
	cin >> n;
	long long k;
	long long res = 0;
	cin >> k;
	for (i = 1; i < n; i++)
	{
		long long y;
		cin >> y;
		if (y < k)
		{
			res += k - y;
			y = k;
		}
		k = y;
	}
	cout << res;

	return 0;
}