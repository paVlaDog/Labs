#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector <vector<int>> graph;
vector <vector<int>> graphReverse;
vector <bool> use;
vector <int> topSortVert;
vector <vector <int>> components;
vector <int> componentsNumber;
vector <bool> existsWay;
vector <string> indexToName;
map <string, int> nameToIndex;
vector <vector<int>> newGraph;
vector <vector<int>> newGraphReverse;
vector <bool> newUse;
vector <string> ans;

void topsort (int vertex) {
    use[vertex] = true;
    for (int i = 0; i < graph[vertex].size(); i++) {
        if (!use[graph[vertex][i]]) {
            topsort(graph[vertex][i]);
        }
    }
    topSortVert.push_back(vertex);
}

void fullTopsort(int n) {
    for (int i = 0; i < n; i++) {
        if (!use[i]) {
            topsort(i);
        }
    }
    reverse(topSortVert.begin(), topSortVert.end());
    use = vector <bool>(n, false);
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

void newDfsReverse(int vertex) {
    newUse[vertex] = true;
    for (auto j : newGraphReverse[vertex]) {
        newDfsReverse(j);
    }
}

int main() {
    int n, m, a, b;
    cin >> n;
    cin >> m;

    indexToName = vector <string>(n);
    nameToIndex = map<string, int>();
    for (int i = 0; i < n; i++) {
        cin >> indexToName[i];
        nameToIndex.emplace(indexToName[i], i);
    }

    string s1, trash, s2;
    n = n * 2;

    graph = vector <vector<int>> (n);
    graphReverse = vector <vector<int>> (n);
    use = vector <bool> (n, false);
    componentsNumber = vector <int> (n);
    for (int i = 0; i < m; i++) {
        cin >> s1 >> trash >> s2;
        a = nameToIndex.at(s1.substr(1, s1.size()));
        b = nameToIndex.at(s2.substr(1, s2.size()));
        if (s1[0] == '-') a+=n/2;
        if (s2[0] == '-') b+=n/2;
        graph[a].push_back(b);
        graph[(b + n/2) % n].push_back((a + n/2) % n);
        graphReverse[b].push_back(a);
        graphReverse[(a + n/2) % n].push_back((b + n/2) % n);
    }

    fullTopsort(n);

    int numOfComp = 0;
    for (int i = 0; i < n; i++) {
        int curVert = topSortVert[i];
        components.emplace_back(vector<int>());
        if (!use[curVert]) {
            condensation(curVert, numOfComp);
            numOfComp++;
        }
    }

    newGraph = vector<vector<int>>(n);
    newGraphReverse = vector<vector<int>>(n);

    for (int i = 0; i < n; i++) {
        for (auto j : graph[i]) {
            if (componentsNumber[i] != componentsNumber[j]) {
                newGraph[componentsNumber[i]].push_back(componentsNumber[j]);
                newGraphReverse[componentsNumber[j]].push_back(componentsNumber[i]);
            }
        }
    }

    newUse = vector <bool>(numOfComp, false);
    int count = 0;
    for (int i = numOfComp - 1; i >= 0; i--) {
        if (newUse[i]) continue;
        int negateComp = componentsNumber[(components[i][0] + n/2) % n];
        if (i == negateComp) {
            cout << -1;
            return 0;
        }
        newUse[i] = true;
        count++;
        for (auto el : components[i]) {
            if (el < n/2) {
                ans.push_back(indexToName[el]);
            }
        }
        newDfsReverse(negateComp);
    }

    if (count < numOfComp / 2) {
        cout << -1;
        return 0;
    }

    cout << ans.size() << endl;
    for (auto el : ans) {
        cout << el << endl;
    }
    return 0;
}


