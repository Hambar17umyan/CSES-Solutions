#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int k, res;
	k = res = 1;
	for(int i=1; i<s.size(); i++)
	{
		if (s[i] == s[i - 1])
			k++;
		else
		{
			res = max(res, k);
			k = 1;
		}
	}
	res = max(res, k);
	cout << res;
	return 0;
}