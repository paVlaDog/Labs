#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector <vector <int>> vec;

int get (int l, int r) {
    l--;
    r--;
    if (l == r) {
        return vec[l][0];
    }
    if (l > r) {
        swap(l, r);
    }
    int deg = floor(log2(abs(r - l)));
    int num = pow(2, deg);
    return min(vec[l][deg], vec[r - num + 1][deg]);
}

int main() {
    int n, m;
    cin >> n >> m;
    int logn = ceil(log2(n + 1));
    vec = vector <vector <int>>(n, vector <int> (logn));
    cin >> vec[0][0];
    for (int i = 1; i < n; i++) {
        vec[i][0] = (vec[i - 1][0] * 23 + 21563) % 16714589;
    }
    for (int i = 1; i < logn; i++) {
        int num = pow(2, i - 1);
        for (int j = 0; j <= n - num * 2 ; j++) {
            vec[j][i] = min(vec[j][i - 1], vec[j + num][i - 1]);
        }
    }
    long long u, v;
    cin >> u >> v;
    long long ans;
    for (int i = 1; i <= m; i++) {
        ans = get(u, v);
        if (i != m) {
            u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
            v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
        }
    }
    cout << u << " " << v << " " << ans;
    return 0;
}