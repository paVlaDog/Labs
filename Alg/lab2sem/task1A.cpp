#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <long long> vec;
long long size;
long long realSize;

void set(int pos, int num) {
    pos += size - 2;
    vec[pos] = num;
    while (pos != 0) {
        pos = (pos - 1) / 2;
        vec[pos] = vec[pos * 2 + 1] + vec[pos * 2 + 2];
    }
}

long long sum(int left, int right) {
    long long ans = 0;
    left += size - 2;
    right += size - 2;
    while (left <= right) {
        if (left % 2 == 0) {
            ans += vec[left];
        }
        left /= 2;
        if (right % 2 == 1) {
            ans += vec[right];
        }
        right /= 2;
        right--;
    }
    return ans;
}

int main() {
    cin >> realSize;
    size = 1;
    while (size < realSize) {
        size *= 2;
    }
    vec = vector <long long>(size * 2 - 1);
    for (int i = size - 1; i < size + realSize - 1; i++) {
        cin >> vec[i];
    }
    for (int i = size - 2; i >= 0; i--) {
        vec[i] = vec[2 * i + 1] + vec[2 * i + 2];
    }
    string str;
    long long pos, num;
    while (cin >> str) {
        if (str == "set") {
            cin >> pos >> num;
            set(pos, num);
        }
        if (str == "sum") {
            cin >> pos >> num;
            cout << sum(pos, num) << " ";
        }
    }
    return 0;
}