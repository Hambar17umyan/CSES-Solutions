#include <iostream>
using namespace std;
#include <set>

int main()
{
	int n;
	set<int>s;
	cin >> n;
	while (n--)
	{
		int y;
		cin >> y;
		s.insert(y);
	}
	cout << s.size();

	return 0;
}