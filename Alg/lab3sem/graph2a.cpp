#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector<int>> graph;
vector <vector<int>> graphReverse;
vector <bool> use;
vector <int> topSortVert;
vector <vector <int>> components;
vector <int> componentsNumber;
vector <bool> existsWay;

void topsort (int vertex) {
    use[vertex] = true;
    for (int i = 0; i < graph[vertex].size(); i++) {
        if (!use[graph[vertex][i]]) {
            topsort(graph[vertex][i]);
        }
    }
    topSortVert.push_back(vertex);
}

void condensation (int vertex, int numOfComp) {
    use[vertex] = true;
    components[numOfComp].push_back(vertex);
    componentsNumber[vertex] = numOfComp;
    for (int i = 0; i < graphReverse[vertex].size(); i++) {
        if (!use[graphReverse[vertex][i]]) {
            condensation(graphReverse[vertex][i], numOfComp);
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n;
    cin >> m;
    graph = vector <vector<int>> (n);
    graphReverse = vector <vector<int>> (n);
    use = vector <bool> (n, false);
    componentsNumber = vector <int> (n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graphReverse[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!use[i]) {
            topsort(i);
        }
    }
    reverse(topSortVert.begin(), topSortVert.end());
    use = vector <bool>(n, false);

    int numOfComp = 0;
    for (int i = 0; i < n; i++) {
        int curVert = topSortVert[i];
        components.emplace_back(vector<int>());
        if (!use[curVert]) {
            condensation(curVert, numOfComp);
            numOfComp++;
        }
    }

    existsWay = vector<bool>(numOfComp, false);

    int count = existsWay.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (componentsNumber[i] != componentsNumber[graph[i][j]] && !existsWay[componentsNumber[i]]) {
                existsWay[componentsNumber[i]] = true;
                count--;
            }
        }
    }

    cout << count << endl;

    for (int i = 0; i < n; i++) {
        if (!existsWay[componentsNumber[i]]) {
            cout << i + 1 << " ";
            existsWay[componentsNumber[i]] = true;
        }
    }

    // Отладка

//    for (int i = 0; i < topSortVert.size(); i++) {
//        cout << topSortVert[i] << " ";
//    }
//    cout << endl << endl;
//
//    for (auto el : components) {
//        for (auto elel : el) {
//            cout << elel << " ";
//        }
//        cout << endl;
//    }






    return 0;
}
