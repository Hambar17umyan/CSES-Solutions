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
 
void f5(ll last)
{
	ll first = last - 4;
	cout << first << ' ' << first + 2 << ' ' << first + 4 << ' ' << first + 1 << ' ' << first + 3;
}
 
void f4(ll last)
{
	ll first = last - 3;
	cout << first + 1 << ' ' << first + 3 << ' ' << first << ' ' << first + 2;
}
 
void f6(ll last)
{
	ll first = last - 5;
	cout << first << ' ' << first + 2 << ' ' << first + 4 << ' ' << first + 1 << ' ' << first + 3 << ' ' << last;
}
 
void f7(ll last)
{
	ll first = last - 6;
	cout << first << ' ' << first + 2 << ' ' << first + 4 << ' ' << first + 1 << ' ' << first + 5 << ' ' << first + 3 << ' ' << first + 6;
}
 
void f8(ll last)
{
	ll first = last - 7;
	cout << first << ' ' << first + 2 << ' ' << first + 4 << ' ' << first + 1 << ' ' << first + 5 << ' ' << first + 7 << ' ' << first + 3 << ' ' << last - 1;
}
 
void solve()
{
	ll n;
	cin >> n;
	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}
	if (n == 2 || n == 3)
	{
		cout << "NO SOLUTION\n";
		return;
	}
 
	if (n == 4)
	{
		f4(4);
		return;
	}
 
	if (n == 5)
	{
		f5(5);
		return;
	}
 
	if (n == 6)
	{
		f6(6);
		return;
	}
 
	if (n == 7)
	{
		f7(7);
		return;
	}
 
	if (n == 8)
	{
		f8(8);
		return;
	}
 
	for (ll i = 5; i <= n - 5; i += 5)
	{
		f5(i);
		cout << ' ';
	}
 
	if (n % 5 == 0)
	{
		f5(n);
	}
	else if (n % 5 == 1)
	{
		f6(n);
	}
	else if (n % 5 == 2)
	{
		f7(n);
	}
	else if (n % 5 == 3)
	{
		f8(n);
	}
	else if (n % 5 == 4)
	{
		f5(n - 4);
		cout << ' ';
		f4(n);
	}
}
 
 
 
 
int main()
{
	int t;
	speed;
	//cin >> t;
	/*
	while (t--)
	{
		solve();
	}*/
 
	solve();
 
	return 0;
}