#include <iostream>
#include <vector>
#include <queue>

using namespace std;

deque<int> k;

void swapSubQueue(int start, int end) {
    int j = 0;
    while (start + j < end - j) {
        swap(k[start + j], k[end - j]);
        j++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    k = deque<int>();
    string inp;
    vector <vector <int>> edges = vector<vector<int>>(n, vector<int>(n, 0));
    getline(cin, inp);
    for (int i = 0; i < n; i++) {
        getline(cin, inp);
        k.push_back(i);
        for (int j = 0; j < inp.size(); j++) {
            edges[i][j] = inp[j] - '0';
            edges[j][i] = inp[j] - '0';
        }
    }

    int j;
    for (int i = 0; i < n * (n - 1); i++) {
        if (!edges[k[0]][k[1]]) {
            for (j = 2; j < n - 1; j++) {
                if (edges[k[0]][k[j]] && edges[k[1]][k[j + 1]]) {
                    swapSubQueue(1, j);
                    break;
                }
            }
            if (j == n - 1) {
                for (j = 2; j < n; j++) {
                    if (edges[k[0]][k[j]]) {
                        swapSubQueue(1, j);
                        break;
                    }
                }
            }
        }
        k.push_back(k.front());
        k.pop_front();
    }
    for (int i = 0; i < n; i++) {
        cout << k.front() + 1 << " ";
        k.pop_front();
    }
    return 0;
}
