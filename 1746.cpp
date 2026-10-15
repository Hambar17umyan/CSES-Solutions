#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <math.h>
#include <ctime>
#include <algorithm>
#include <deque>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define ll long long
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define commadig(x) cout << fixed << setprecision(x);
#define kap map
#define _2 second
#define _1 first
#define rev(x) reverse(x.begin(), x.end())
#define mpr make_pair
#define multi int t; cin>>t; presolve(); while(t--) solve()
#define single presolve(); solve(); return 0
#define endl '\n'

//////////////////////////////////////////////////////////////////////////////////////
ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}
string to2(ll a)
{
	string r = "";
	for (ll i = a; i > 0; )
	{
		ll k = i % 2;
		i /= 2;
		char c = k + 48;
		r += c;
	}
	if (a == 0)
	{
		r = "0";
	}
	rev(r);

	return r;
}
void yn(bool b)
{
	if (b)
		cout << "YES\n";
	else cout << "NO\n";
}
/////////////////////////////////////////////////////////////////////////////////////

void presolve()
{

}

ll arr[100005];
ll dp[105][100005];
void solve()
{
	ll i, j, k, m, n, o, p, l;
	string s;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (j = 0; j < n; j++)
	{
		if (arr[j] == 0)
		{
			if (j > 0)
			{
				for (i = 1; i <= m; i++)
				{
					dp[i][j] = dp[i - 1][j - 1];
					dp[i][j] += dp[i][j - 1];
					dp[i][j] += dp[i + 1][j - 1];
					dp[i][j] %= 1000000007;
				}
			}
			else
			{
				for (i = 1; i <= m; i++)
				{
					dp[i][j] = 1;
				}
			}
		}
		else
		{
			for (i = 1; i <= m; i++)
			{
				dp[i][j] = 0;
			}
			ll a = 0;
			if (j > 0)
			{
				a = dp[arr[j] - 1][j - 1];
				dp[arr[j]][j] = a + dp[arr[j] + 1][j - 1] + dp[arr[j]][j - 1];
				dp[arr[j]][j] %= 1000000007;
			}0 
			else
			{
				dp[arr[j]][j] = 1;
			}
		}
	}
	k = 0;
	for (i = 1; i <= m; i++)
	{
		k += dp[i][n - 1];
		k %= 1000000007;
	}
	cout << k << endl;
}

int main()
{
	speed;
	single;
	multi;

	return 0;
}