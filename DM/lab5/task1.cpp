#include <iostream>
#include <unordered_map>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ifstream fin("automaton.in");
    ofstream fout("automaton.out");
    int n;
    fin >> n;
    string start;
    fin >> start;

    unordered_multimap <char, string> transAB;
    unordered_multimap <char, string> transA;
    string s1, trash, s2, s;
    getline(fin, s);
    for (int i = 0; i < n; i++) {
        getline(fin, s);
        if (s.size() >= 7) {
            transAB.insert(pair<char, string>(s[0], s.substr(5, s.size() - 5)));
        } else if (s.size() >= 5) {
            transA.insert(pair<char, string>(s[0], s.substr(5, s.size() - 5)));
        } else {
            transA.insert(pair<char, string>(s[0], ""));
        }
    }


    vector <set <char>> nonterm(10002);
    vector <set <char>> termWithNext(10002);
    vector <set <char>> termWithoutNext(10002);

    nonterm[0].emplace(start[0]);

    for (int i = 0; i < 10001; i++) {
        for (auto ch : nonterm[i]) {
            for (auto it = transAB.find(ch); it != transAB.end() && it->first == ch; ++it) {
                termWithNext[i].emplace(it->second[0]);
                nonterm[i + 1].emplace(it->second[1]);
            }
            for (auto it = transA.find(ch); it != transA.end() && it->first == ch; ++it) {
                termWithoutNext[i].emplace(it->second[0]);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << i << " ";
        for (auto ch : nonterm[i]) {
            cout << ch << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
        for (auto ch : termWithNext[i]) {
            cout << ch << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
        for (auto ch : termWithoutNext[i]) {
            cout << ch << " ";
        }
        cout << '\n';
    }

    string quest;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> quest;
        bool flagLose = 0;
        for (int j = 0; j < quest.size() - 1; j++) {
            if (!termWithNext[j].count(quest[j])) {
                flagLose = 1;
            }
        }
        if (!termWithoutNext[quest.size() - 1].count(quest[quest.size() - 1])) {
            flagLose = 1;
        }
        if (flagLose) {
            fout << "no" << '\n';
            cout << quest << " no" << '\n';
        } else {
            fout << "yes" << '\n';
            cout << quest << " yes" << '\n';
        }
    }



    return 0;
}


