#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
	int n, n1, lBound, rBound, l, r, mid;
	cin >> n;
	vector <int> mas(n);
	for (int i = 0; i < n; i++) {
		cin >> mas[i];
	}
	sort(mas.begin(), mas.end());
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> lBound;
		cin >> rBound;
		l = -1;
		r = n;
		while (r - l != 1) {
			mid = (r + l) / 2;
			if (mas[mid] >= lBound) {
				r = mid;
			} else {
				l = mid;
			}
		}
		lBound = r;
		l = -1;
		r = n;
		while (r - l != 1) {
			mid = (r + l) / 2;
			if (mas[mid] > rBound) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		rBound = l;
		cout << rBound - lBound + 1 << " ";
	}
 
 
 
 
 
	return 0;
}