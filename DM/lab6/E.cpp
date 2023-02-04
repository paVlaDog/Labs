#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    int a, b;
    set <int> s;
    cin >> n;
    vector <set<int>> edges(n + 1);
    vector <int> deg(n + 1);
    vector <int> ans;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
        deg[a]++;
        deg[b]++;
    }

    set<int> lists;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            lists.insert(i);
        }
    }

    while (!lists.empty()) {
        int curEl = *lists.begin();
        lists.erase(lists.begin());
        int parent = *edges[curEl].begin();
        edges[parent].erase(edges[parent].find(curEl));
        deg[parent]--;
        if (deg[parent] == 1) {
            lists.insert(parent);
        }
        ans.push_back(parent);
        if (ans.size() == n - 2) break;
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    return 0;
}
