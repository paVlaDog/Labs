#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("problem1.in");
    ofstream fout("problem1.out");
    int m, n, k;
    int _1, _2;
    char _3;
    fin >> n >> m >> k;
    unordered_set <int> winCondition;
    for (int i = 0; i < k; i++) {
        fin >> _1;
        winCondition.emplace(_1);
    }
    vector <vector <int>> transitions(n + 2);
    for (int i = 0; i < m; i++) {
        fin >> _1 >> _2 >> _3;
        transitions[_1].push_back(_2);
    }

    vector <int> sequence{1};
    queue <int> st;
    st.push(1);

    while (!st.empty()) {
        int el = st.front();
        st.pop();
        for (int i = 0; i < transitions[el].size(); i++) {

        }
    }

}



