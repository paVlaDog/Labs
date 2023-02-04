#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <pair<int, int>>> graph;
vector <bool> use;
priority_queue<pair<int, int>> k;
vector <int> weight;

void deikstra(int start) {
    k.push({0, start});
    while (!k.empty()) {
        if (use[k.top().second]) continue;
        int curVert = k.top().second;
        int curWeight = k.top().first;
        k.pop();
        weight[curVert] = curWeight;
        use[curVert] = true;
        for (int i = 0; i < graph[curVert].size(); i++) {
            if (!use[graph[curVert][i].second]) {
                k.push({graph[curVert][i].first, graph[curVert][i].second});
            }
        }
    }

}

int main() {
    int n, m, s, t, a, b, c;
    cin >> n >> m >> s >> t;
    use = vector<bool>(n, false);
    weight = vector<int>(n, INT32_MAX);
    graph = vector <vector <pair<int, int>>>(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a - 1].push_back({c, b - 1});
    }
    deikstra(s - 1);
    if (weight[t - 1] == INT32_MAX) {
        cout << "Unreachable";
    } else {
        cout << weight[t - 1];
    }

//    for (int i = 0; i < n; i++) {
//        cout << weight[i] << " ";
//    }


    return 0;
}
