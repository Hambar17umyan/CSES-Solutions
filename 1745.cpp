#include <iostream>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int arr[105];
map<int, bool> dp;
int main()
{
	int i, j, n;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = n - 1; i >= 0; i--)
	{
		queue<int>q;
		for (map<int, bool>::iterator it = dp.begin(); it != dp.end(); it++)
		{
			q.push(-(it->first));
		}
		while (!q.empty())
		{
			dp[-arr[i] - q.front()] = 1;
			q.pop();
		}
		dp[-arr[i]] = 1;
	}
	cout << dp.size();
	cout << endl;
	stack<int>q;
	for (map<int, bool>::iterator it = dp.begin(); it != dp.end(); it++)
	{
		q.push(-(it->first));
	}
	while (!q.empty())
	{
		cout << q.top() << ' ';
		q.pop();
	}

	return 0;
}