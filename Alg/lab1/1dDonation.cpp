#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
 
using namespace std;
 
int main() {
	long long n, Ai = 0, Bi = 0, maxi = 0, inMax = 0, whereAns;
	long long sumBefA = 0, countBetAB = 0, sumAftB = 0;
	cin >> n;
	vector <int> A(n);
	vector <int> B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
		sumAftB += A[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	while (Ai < n || Bi < n) {
		if (Ai < n && (Bi >= n || A[Ai] < B[Bi])) {
			sumAftB -= A[Ai];
			Ai++;
			countBetAB++;
		}
		if (Ai >= n || A[Ai] >= B[Bi]) {
			if (maxi < sumAftB + countBetAB * B[Bi]) {
				inMax = Bi;
				maxi = sumAftB + countBetAB * B[Bi];
			}
			Bi++;
			countBetAB--;
		}
	}
	cout << B[inMax] << " " << maxi;
 
	return 0;
}