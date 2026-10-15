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
 
void solve()
{
 
	ll a, b, n;
	cin >> n >> a >> b;
	bool bs = false;
	if (a > b)
	{
		bs = true;
		swap(a, b);
	}
 
	if (a + b > n)
	{
		cout << "NO\n";
		return;
	}
 
	if (a == 0 && b!=0)
	{
		cout << "NO\n";
		return;
	}
 
	cout << "YES\n";
 
	if (bs)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << i << ' ';
		}
		cout << endl;
 
 
		int k = n - a - b;
 
		for (int i = 1; i <= k; i++)
		{
			cout << i << ' ';
		}
 
		for (int i = 0; i < a; i++)
		{
			cout << n - i << ' ';
		}
 
		for (int i = k + 1; i <= n - a; i++)
		{
			cout << i << ' ';
		}
 
		cout << endl;
	}
	else
	{
		int k = n - a - b;
 
		for (int i = 1; i <= k; i++)
		{
			cout << i << ' ';
		}
 
		for (int i = 0; i < a; i++)
		{
			cout << n - i << ' ';
		}
 
		for (int i = k + 1; i <= n - a; i++)
		{
			cout << i << ' ';
		}
 
		cout << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << i << ' ';
		}
		cout << endl;
	}
 
 
}
 
 
 
 
int main()
{
	int t;
	speed;
	cin >> t;
 
	while (t--)
	{
		solve();
	}
 
	return 0;
}