#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int arr[105][105];

int mex(int x, int y)
{
	map<int, int>mp;
	for (int i = 1; i < y; i++)
	{
		mp[arr[x][i]]++;
	}

	for (int i = 1; i < x; i++)
	{
		mp[arr[i][y]]++;
	}

	for (int i = 0; ; i++)
	{
		if (mp[i] == 0)
		{
			return i;
		}
	}
}

void solve()
{
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		arr[i][1] = arr[1][i] = i - 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			arr[i][j] = mex(i, j);
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}




int main()
{
	int t;
	speed;
	//cin >> t;

	/*while (t--)
	{
		solve();
	}*/

	solve();

	return 0;
}
