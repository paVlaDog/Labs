#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> deep;
vector <vector <int>> edge;
vector <vector <int>> revEdge;
vector <vector <int>> binUp;

void dfs (int vert, int deepVert) {
    deep[vert] = deepVert;
    for (int i = 0, t = 1; t <= deepVert; t *= 2, i++) {
        if (i == 0) {
            binUp[vert].push_back(revEdge[vert][0]);
        } else {
            binUp[vert].push_back(binUp[binUp[vert][i - 1]][i - 1]);
        }
    }
    for (int i = 0; i < edge[vert].size(); i++) {
        dfs(edge[vert][i], deepVert + 1);
    }
}

int main() {
    int n, m, trash, vert1, vert2;
    cin >> n;
    edge = vector <vector <int>>(n);
    revEdge = vector <vector <int>>(n);
    binUp = vector <vector <int>>(n);
    deep = vector <int>(n);
    deep[0] = 0;
    for (int i = 1; i < n; i++) {
        cin >> trash;
        edge[trash - 1].push_back(i);
        revEdge[i].push_back(trash - 1);
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
        if (deep[vert1] < deep[vert2]) {
            swap(vert1, vert2);
        }
        while (deep[vert1] != deep[vert2]) {
            int diff = deep[vert1] - deep[vert2];
            vert1 = binUp[vert1][floor(log2(diff))];
        }
        //cout << vert1 << " " << vert2 << '\n';
        if (vert1 == vert2) {
            cout << vert1 + 1 << '\n';
        } else {
            while (binUp[vert1][0] != binUp[vert2][0]) {
                //cout << vert1 << " " << vert2;
                int diff = min(deep[vert1], deep[vert2]);
                for (int i = floor(log2(diff)); i >= 0; i--) {
                    //cout << vert1 << " " << vert2 << '\n';
                    int newVert1 = binUp[vert1][i];
                    int newVert2 = binUp[vert2][i];
                    if (newVert1 != newVert2) {
                        vert1 = newVert1;
                        vert2 = newVert2;
                        break;
                    }
                }
            }
            cout << binUp[vert1][0] + 1 << '\n';
        }

    }

    return 0;
}




