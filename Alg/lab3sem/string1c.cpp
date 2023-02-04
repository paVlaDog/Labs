#include <iostream>
#include <vector>

using namespace std;

int main() {
    string all, sub, str;
    int minPer = 0;
    vector <int> ans;
    cin >> all;
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

//    for (auto el : ans) {
//        cout << el << " ";
//    }

    for (int i = 0; i <= ans.size()/2; i++) {
        if (ans[i] == ans.size() - i) {
            cout << i;
            break;
        }
        if (i == ans.size()/2) {
            cout << ans.size();
        }
    }

//    cout << minPer + 1;

    return 0;
}
