#include <iostream>
#include <map>
#define ll long long
using namespace std;

string arr[5002];
map<string, ll>mp;
int main()
{
	ll i, j, k, m, n;
	string s;
	cin >> s;
	cin >> k;
	for (i = 0; i < k; i++)
	{
		cin >> arr[i];
		mp[arr[i]]++;
	}
	mp[arr[0]] = 1;
	const ll mod = 1000000007;
	map<string, ll>::iterator it;
	for (i = 1; i < k; i++)
	{
		for (it = mp.begin(); it != mp.end(); it++)
		{
			if (it->first.size() + arr[i].size() <= s.size())
			{
				mp[it->first + arr[i]] += it->second;
				mp[it->first + arr[i]] %= mod;
				mp[arr[i] + it->first] += it->second;
				mp[arr[i] + it->first] %= mod;
			}
			if (arr[i].size() <= s.size())
			{
				mp[arr[i]]++;
				mp[arr[i]] %= mod;
			}
		}
	}
	cout << mp[s];

	return 0;
}