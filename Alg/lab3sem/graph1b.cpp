#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <bool> use;
vector <vector <pair<long long, long long>>> graph;
vector<int> topsort;
vector<long long> minWeight;

void dfs (int vert) {
    use[vert] = true;
    for (int i = 0; i < graph[vert].size(); i++) {
        if (!use[graph[vert][i].first]) {
            dfs(graph[vert][i].first);
        }
    }
    topsort.push_back(vert);
}

void seqMin () {
    for (int j = 0; j < topsort.size(); j++) {
        int vert = topsort[j];
        for (int i = 0; i < graph[vert].size(); i++) {
            minWeight[graph[vert][i].first] = min(minWeight[vert] + graph[vert][i].second, minWeight[graph[vert][i].first]);
        }
    }
}

int main() {
    int n, m, s, t, a, b, c;
    cin >> n >> m >> s >> t;
    graph = vector <vector <pair<long long, long long>>>(n);
    use = vector <bool>(n, false);
    minWeight = vector <long long>(n, INT64_MAX);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a - 1].push_back({ b - 1, c});
    }
    minWeight[s - 1] = 0;
    dfs(s - 1);
    reverse(topsort.begin(), topsort.end());
//    for (auto el : topsort) {
//        cout << el << " ";
//    }

    seqMin();
    if (minWeight[t - 1] == INT64_MAX) {
        cout << "Unreachable";
    } else {
        cout << minWeight[t - 1];
    }
    return 0;
}


//5 7 2 4
//2 3 2
//2 1 8
//2 5 18
//3 1 3
//1 5 20
//1 4 30
//5 4 1