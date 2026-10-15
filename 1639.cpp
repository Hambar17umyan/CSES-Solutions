#include <iostream>
using namespace std;

int arr[5002][5002]; 
string a;
string b;
void lcs()
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				arr[i + 1][j + 1] = arr[i][j] + 1;
			}
			else
			{
				arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
			}
		}
	}
}

string s = "";
void com(int i, int j)
{
	if (i == -1 || j == -1)
	{
		return;
	}
	if (arr[i + 1][j + 1] == arr[i][j] + 1)
	{
		s += a[i];
		com(i - 1, j - 1);
		return;
	}
	if (arr[i][j + 1] > arr[i + 1][j])
		com(i - 1, j);
	else com(i, j - 1);
}

int main()
{
	cin >> a >> b;
	lcs();
	com(a.size() - 1, b.size() - 1);
	int s1, f1, s2, f2;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == s[0])
		{
			s1 = i;
			break;
		}
	}

	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == s[0])
		{
			s2 = i;
			break;
		}
	}

	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] == s[s.size() - 1])
		{
			f1 = i;
			break;
		}
	}

	for (int i = b.size() - 1; i >= 0; i--)
	{
		if (b[i] == s[s.size() - 1])
		{
			f2 = i;
			break;
		}
	}

	cout << s1 + s2 + (a.size() - f1 - 1) + (b.size() - f2 - 1) + max((f1 - s1 + 1 - s.size()), (f2 - s2 - s.size()));

	return 0;
}