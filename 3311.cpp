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

char arr[505][505];
void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			set<char>s;
			s.insert('A');
			s.insert('B');
			s.insert('C');
			s.insert('D');
			if (i > 1)
			{
				set<char>::iterator y = s.find(arr[i - 1][j]);
				if (y != s.end())
					s.erase(y);
			}
			if (j > 1)
			{
				set<char>::iterator y = s.find(arr[i][j - 1]);
				if (y != s.end())
					s.erase(y);
			}

			set<char>::iterator y = s.find(arr[i][j]);
			if (y != s.end())
				s.erase(y);

			arr[i][j] = *s.begin();
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << arr[i][j];
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
