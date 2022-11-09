#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("problem1.in");
    ofstream fout("problem1.out");
    string str;
    getline(fin, str);
    int m, n, k;
    int _1, _2;
    char _3;
    fin >> n >> m >> k;
    unordered_set <int> winCondition;
    for (int i = 0; i < k; i++) {
        fin >> _1;
        winCondition.emplace(_1);
    }
    unordered_map <char, unordered_map<int, int>> transitions;
    for (int i = 0; i < m; i++) {
        fin >> _1 >> _2 >> _3;
        transitions[_3][_1] = _2;
    }

    int currentState = 1;
    bool flagLose = 0;
    for (int i = 0; i < str.size(); i++) {
        //cout << currentState << " " << str[i] << " " << transitions[str[i]].first << " " << transitions[str[i]].second << " " << '\n';
        if (transitions[str[i]].count(currentState)) {
            currentState = transitions[str[i]][currentState];
        } else {
            flagLose = 1;
        }
    }

    if (flagLose || !winCondition.count(currentState)) {
        fout << "Rejects";
    } else {
        fout << "Accepts";
    }

}

