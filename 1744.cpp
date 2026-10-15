#include <iostream>
using namespace std;

int arr[505];
int r = 0;
void rec(int n, int m)
{
	r++;
	int a, b;
	a = min(n, m);
	b = max(n, m);
	if (b - a != a)
	{
		rec(a, b - a);
	}
}
int main()
{
	int i, j, k, l, m, n, o, p;
	cin >> n >> m;
	if (n == m)
	{
		cout << 0 << endl;
		return 0;
	}
	r = 0;
	rec(n, m);
	cout << r;

	return 0;
}