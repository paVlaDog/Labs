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
    for (int i = 1; i < all.size(); i++) {
        if (i <= right) {
            ans[i] = min(right - i + 1, ans[i - left]);
        }
        while (i + ans[i] < all.size() && all[ans[i]] == all[i + ans[i]]) {
            ans[i]++;
        }
        if (i + ans[i] - 1 > right) {
            left = i;
            right = i + ans[i] - 1;
        }
    }

    for (int i = sub.size(); i < all.size(); i++) {
        if (ans[i] >= sub.size()) {
            s.emplace(i - sub.size());
            count++;
        }
    }

//    for (auto el : ans) {
//        cout << el << " ";
//    }

    cout << count << endl;

    for (auto el : s) {
        cout << el << " ";
    }

    return 0;
}
