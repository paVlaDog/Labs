#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    set<int> lists;
    int n, trash;
    cin >> n;
    vector <int> code(n - 2);
    vector <int> deg(n + 1);

    for (int i = 1; i < n + 1; i++) {
        lists.insert(i);
    }

    for (int i = 0; i < n - 2; i++) {
        cin >> code[i];
        deg[code[i]]++;
        if (deg[code[i]] == 1) {
            lists.erase(lists.find(code[i]));
        }
    }

    for (int i = 0; i < code.size(); i++) {
        int curEl = *lists.begin();
        lists.erase(lists.begin());
        deg[code[i]]--;
        if (deg[code[i]] == 0) {
            lists.insert(code[i]);
        }
        cout << curEl << " " << code[i] << endl;
    }
    cout << *lists.begin();
    lists.erase(lists.begin());
    cout << " " << *lists.begin();

    return 0;
}
