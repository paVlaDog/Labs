#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    long long size;
    cin >> size;
    vector <long long> vec(size * 2 - 1);
    for (int i = size - 1; i < vec.size(); i++) {
        cin >> vec[i];
    }
    for (int i = size - 2; i >= 0; i--) {
        vec[i] = min(vec[2 * i + 1], vec[2 * i + 2]);
    }

    string str;
    long long pos, num;
    while (cin >> str) {
        if (str == "set") {
            cin >> pos >> num;
            pos += size - 2;
            vec[pos] = num;
            while (pos != 0) {
                pos = (pos - 1) / 2;
                vec[pos] = min(vec[pos * 2 + 1], vec[pos * 2 + 2]);
            }
        }
        if (str == "min") {
            long long ans = LONG_LONG_MAX;
            cin >> pos >> num;
            pos += size - 2;
            num += size - 2;
            while (pos <= num) {
                if (pos % 2 == 0) {
                    ans = min(vec[pos], ans);
                }
                pos /= 2;
                if (num % 2 == 1) {
                    ans = min(vec[num], ans);
                }
                num /= 2;
                num--;
            }
            cout << ans << " ";
        }
    }
    return 0;
}