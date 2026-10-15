#include <iostream>
#include <utility>
using namespace std;
 
int indexes[200005];
int arr[200005];
 
int updateRes(int res, int inda, int indb, bool check1 = true, bool check2 = true, bool check3 = true, bool check4 = true) {
	int a, b;
	a = arr[inda];
	b = arr[indb];
 
	if (check1) {
		if (inda < indexes[a + 1] && indexes[a + 1] < indb) {
			res++;
		}
	}
	
	if (check2) {
		if (indb > indexes[b + 1] && indexes[b + 1] > inda) {
			res--;
		}
	}
	
	if (check3) {
		if (inda < indexes[a - 1] && indexes[a - 1] < indb) {
			res--;
		}
	}
	
	if (check4) {
		if (indb > indexes[b - 1] && indexes[b - 1] > inda) {
			res++;
		}
	}
 
	return res;
}
 
int main() {
	int n, m, k;
	cin >> n >> m;
 
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		indexes[arr[i]] = i;
	}
 
	int res = 1;
	for (int i = 2; i <= n; i++) {
		if (indexes[i] < indexes[i - 1]) {
			res++;
		}
	}
 
	indexes[n + 1] = n + 1;
	arr[n + 1] = n + 1;
 
	indexes[0] = 0;
	arr[0] = 0;
 
	while (m--) {
		int a, b, inda, indb;
		cin >> inda >> indb;
		if (inda == indb)
		{
			cout << res << endl;
			continue;
		}
 
		if (inda > indb)
			swap(inda, indb);
 
		a = arr[inda];
		b = arr[indb];
 
		if (a == b - 1) {
			res++;
			res = updateRes(res, inda, indb, false, true, true, false);
		}
		else if (a == b + 1) {
			res--;
			res = updateRes(res, inda, indb, true, false, false, true);
		}
		else {
			res = updateRes(res, inda, indb);
		}
 
		swap(arr[inda], arr[indb]);
		indexes[a] = indb;
		indexes[b] = inda;
		cout << res << endl;
	}
 
	return 0;
}