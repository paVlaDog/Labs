#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> deep;
vector <vector <pair<int, int>>> edge;
vector <vector <pair<int, int>>> revEdge;
vector <vector <pair<int, int>>> binUp;

void dfs (int vert, int deepVert) {
    deep[vert] = deepVert;
    for (int i = 0, t = 1; t <= deepVert; t *= 2, i++) {
        if (i == 0) {
            binUp[vert].push_back(revEdge[vert][0]);
        } else {
            binUp[vert].push_back(make_pair(
                                          binUp[binUp[vert][i - 1].first][i - 1].first,
                                          min(
                                                  binUp[vert][i - 1].second,
                                                  binUp[binUp[vert][i - 1].first][i - 1].second
                                          )
                                  )
            );
        }
    }
    for (int i = 0; i < edge[vert].size(); i++) {
        dfs(edge[vert][i].first, deepVert + 1);
    }
}

int main() {
    int n, m, vert1, vert2, vert, cost, mini;
    cin >> n;
    edge = vector <vector <pair<int, int>>>(n);
    revEdge = vector <vector <pair<int, int>>>(n);
    binUp = vector <vector <pair<int, int>>>(n);
    deep = vector <int>(n);
    deep[0] = 0;
    for (int i = 1; i < n; i++) {
        cin >> vert >> cost;
        edge[vert - 1].push_back(make_pair(i, cost));
        revEdge[i].push_back(make_pair(vert - 1, cost));
    }
    dfs(0, 0);
//    for (int i = 0; i < binUp.size(); i++) {
//        cout << i << '\n';
//        for (auto elem : binUp[i]) {
//            cout << elem << " ";
//        }
//        cout << '\n' << '\n';
//    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> vert1 >> vert2;
        vert1--;vert2--;
        mini = 10000000;
        if (deep[vert1] < deep[vert2]) {
            swap(vert1, vert2);
        }
        while (deep[vert1] != deep[vert2]) {
            int diff = deep[vert1] - deep[vert2];
            mini = min(mini, binUp[vert1][floor(log2(diff))].second);
            vert1 = binUp[vert1][floor(log2(diff))].first;
        }
        if (vert1 == vert2) {
            cout << mini << '\n';
        } else {
            while (binUp[vert1][0].first != binUp[vert2][0].first) {
                int diff = min(deep[vert1], deep[vert2]);
                for (int i = floor(log2(diff)); i >= 0; i--) {
                    //cout << vert1 << " " << vert2 << '\n';
                    int newVert1 = binUp[vert1][i].first;
                    int newVert2 = binUp[vert2][i].first;
                    if (newVert1 != newVert2) {
                        mini = min(mini, min(binUp[vert1][i].second, binUp[vert2][i].second));
                        vert1 = newVert1;
                        vert2 = newVert2;
                        break;
                    }
                }
            }
            cout << min(mini, min(binUp[vert1][0].second, binUp[vert2][0].second)) << '\n';
        }

    }
    return 0;
}


