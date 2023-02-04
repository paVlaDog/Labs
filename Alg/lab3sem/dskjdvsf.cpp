#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int kv, n, isPalindrom = 1;
    for (int i=1; i<100; i++){
        isPalindrom = 1;
        kv= i*i;
        cout << kv << endl;
        for (int j = 0; j < 6; i++) {
            int powij = 1;
            for (int ij = 0; ij < j; ij++) {
                powij = powij * 10;
            }
            if (kv / powij == 0) {
                n = j;
                break;
            }
        }
        cout << endl;
        for (int l = 0; l < n; l++) {
            cout << "i inside!";
            int powi = 1, powni = 1;
            for (int j = 0; j < l; j++) {
                powi = powi * 10;
            }
            for (int j = 0; j < n - 1 - l; j++) {
                powni = powni * 10;
            }
            if (kv / powi % 10 != kv / powni % 10){
                isPalindrom = 0;
            }
        }
        if (isPalindrom == 1){
            cout << i << " ";
        }
    }
}


