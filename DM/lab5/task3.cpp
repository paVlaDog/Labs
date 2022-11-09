#include <iostream>
#include <unordered_map>
#include <set>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    ifstream fin("useless.in");
    ofstream fout("useless.out");
    int n;
    fin >> n;
    char start;
    fin >> start;

    set<char> allSymb;
    allSymb.emplace(start);
    unordered_multimap <char, string> trans;
    unordered_multimap <string, char> revTrans;
    string s1, trash, s2, s;
    getline(fin, s);
    for (int i = 0; i < n; i++) {
        getline(fin, s);
        allSymb.emplace(s[0]);
        for (int i = 5; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                allSymb.emplace(s[i]);
            }
        }
        if (s.size() >= 5) {
            trans.insert(pair<char, string>(s[0], s.substr(5, s.size() - 5)));
            revTrans.insert(pair<string, char>(s.substr(5, s.size() - 5), s[0]));
        } else {
            trans.insert(pair<char, string>(s[0], ""));
            revTrans.insert(pair<string, char>("", s[0]));
        }
    }

    set <char> born;
    bool change = 1;
    while (change) {
        change = 0;
        for (auto el : trans) {
            bool flag = 0;
            for (auto ch : el.second) {
                if (ch >= 'A' && ch <= 'Z' && !born.count(ch)) {
                    flag = 1;
                }
            }
            if (!flag && !born.count(el.first)) {
                born.emplace(el.first);
                change = 1;
            }
        }
    }
    for (auto ch : born) {
        cout << ch << " ";
    }

    set<char> achievable;
    int sz = achievable.size();
    if (born.count(start)) {
        achievable.insert(start);
    }
    while (sz != achievable.size()) {
        sz = achievable.size();
        for (auto el : trans) {
            if (achievable.count(el.first)) {
                cout << '\n';
                cout << el.first << " -> " << el.second << '\n';
                bool flag = 1;
                for (auto ch : el.second) {
                    cout << ch << " " << (ch <= 'Z' && !born.count(ch)) << '\n';
                    if (ch <= 'Z' && !born.count(ch)) {
                        flag = 0;
                    }
                }
                if (flag) {
                    for (auto ch: el.second) {
                        if (ch >= 'A' && ch <= 'Z') {
                            achievable.insert(ch);
                            change = 1;
                        }
                    }
                }
            }
        }
    }
    cout << '\n';
    for (auto ch : achievable) {
        cout << ch << " ";
    }

//        queue <char> k;
//        k.push(start);
//        while (!k.empty()) {
//            char now = k.front();
//            k.pop();
//            achievable.emplace(now);
//            for (auto it = trans.find(now); it != trans.end() && it->first == now; ++it) {
//                bool flag = 1;
//                for (auto symb: it->second) {
//                    if (!born.count(symb)) {
//                        flag = 0;
//                    }
//                }
//                if (flag) {
//                    for (auto symb: it->second) {
//                        if (!achievable.count(symb)) {
//                            k.push(symb);
//                        }
//                    }
//                }
//            }
//        }


    for (auto el: allSymb) {
        if (!born.count(el) || !achievable.count(el)) {
            fout << el << " ";
        }
    }
    return 0;
}

//8 S
//        S -> AB
//        S -> CD
//        A -> EF
//        G -> AD
//        C -> c
//        B -> b
//        E -> e
//        F -> f

