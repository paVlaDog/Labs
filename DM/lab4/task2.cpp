#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("problem1.in");
    ofstream fout("problem1.out");
    string str;
    fin >> str;
    int m, n, k;
    int _1, _2;
    char _3;
    fin >> n >> m >> k;
    unordered_set <int> winCondition;
    for (int i = 0; i < k; i++) {
        fin >> _1;
        winCondition.emplace(_1);
    }
    unordered_map <char, vector <pair<int, int>>> transitions;
    for (int i = 0; i < m; i++) {
        fin >> _1 >> _2 >> _3;
        transitions[_3].push_back(make_pair(_1, _2));
    }
    unordered_set <int> currentState{1};
    unordered_set <int> currentStateNew;
    bool flagLose = 0;
    bool flagTrueThisMove = 0;

    for (int i = 0; i < str.size(); i++) {
        //cout << "currentState";
//        for (auto el : currentState) {
//            cout << el << " ";
//        }
        //cout << '\n' << '\n';
        for (int j = 0; j < transitions[str[i]].size(); j++) {
            //cout << currentState.size() << " " << str[i] << " " << transitions[str[i]][j].first << " " << transitions[str[i]][j].second << " " << '\n';
            if (currentState.count(transitions[str[i]][j].first)) {
                currentStateNew.emplace(transitions[str[i]][j].second);
                flagTrueThisMove = 1;
            }
        }
        if (!flagTrueThisMove) {
            flagLose = 1;
        }
        flagTrueThisMove = 0;
        currentState = currentStateNew;
        currentStateNew.clear();
    }

    bool flagWin = 0;
    for (auto el : currentState) {
        if (winCondition.count(el)) {
            flagWin = 1;
        }
    }

    if (flagLose || !flagWin) {
        fout << "Rejects";
    } else {
        fout << "Accepts";
    }

}

