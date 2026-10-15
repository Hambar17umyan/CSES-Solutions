#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int>st;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		st.insert(i);
	for (int i = 0; i < n - 1; i++)
	{
		int y;
		cin >> y;
		st.erase(y);
	}
	cout << *st.begin();

	return 0;
}