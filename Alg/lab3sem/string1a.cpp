#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    string all, sub, str;
    set<int> s;
    int count = 0;
    vector <int> ans;
    cin >> sub;
    cin >> str;
    all = sub + " " + str;
    ans = vector<int>(all.size());
    int left = 0, right = 0;
    for (int i = 0; i < all.size(); i++) {
        ans[i] = max(0, min(right - i, ans[i - left]));
        while (i + ans[i] < all.size() && all[ans[i]] == all[i + ans[i]]) {
            ans[i]++;
        }
        if (i + ans[i] > right) {
            left = i;
            right = i + ans[i];
        }
        if (i >= sub.size() && ans[i] == sub.size()) {
            count++;
            s.insert(i - sub.size());
        }
    }
    cout << count << endl;

    for (auto el : s) {
        cout << el << " ";
    }

    return 0;
}
