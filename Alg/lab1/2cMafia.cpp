#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
 
using namespace std;
 
int main() {
	int n, leng;
	cin >> n >> leng;
	vector <int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	long double l = 0, r = leng, mid, curPos;
	
	while (r - l > 0.0000005) {
		mid = (r + l) / 2;
		curPos = 0;
		
		//cout << mid << endl;
		for (int i = 0; i < n; i++) {
			if (curPos + mid < num[i]) {
				l = mid;
				break;
			}
			if (i < n - 1) {
				if (curPos + mid > num[i + 1]) {
					curPos = num[i + 1];
				}
				else {
					curPos = curPos + mid;
				}
			}
			else {
				if (curPos + mid <= leng) {
					l = mid;
				}
				else {
					r = mid;
				}
			}
		}
	}
	cout << setprecision(6) << fixed;
	cout << l;
 
	return 0;
}