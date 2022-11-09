#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

set<char> alphabet;

pair<char, string> parse(string str) {
    char f;
    f = str[0];
    str.erase(str.begin());
    while (str.size() && str[0] == ' ') {
        str.erase(str.begin());
    }
    str.erase(str.begin());
    str.erase(str.begin());
    while (str.size() && str[0] == ' ') {
        str.erase(str.begin());
    }
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != tolower(str[i])) {
            alphabet.insert(str[i]);
        }
    }
    if (f != tolower(f)) {
        alphabet.insert(f);
    }

    return {f, str};
}

int main() {
    ifstream in("useless.in");
    ofstream out("useless.out");

    int n;
    char s;
    string x;
    in >> n >> s;
    set<char> born;
    alphabet.insert(s);
    vector<pair<char, string>> v;
    getline(in, x);
    for (int i = 0; i < n; ++i) {
        string str;
        getline(in, str);
        v.emplace_back(parse(str));
    }

    size_t sz = 0;
    do {
        sz = born.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (auto c: v[i].second) {
                if (c >= 'a' || born.find(c) != born.end()) {
                    cnt++;
                }
            }
            if (cnt == v[i].second.size()) {
                born.insert(v[i].first);
            }
        }
    } while (sz != born.size());
    for (auto ch : born) {
        cout << ch << " ";
    }


    set<char> reachable;
    if (born.find(s) != born.end()) {
        reachable.insert(s);
    }

    do {
        sz = reachable.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            if (reachable.find(v[i].first) == reachable.end()) {
                continue;
            }
            cout << '\n';
            cout << v[i].first << " -> " << v[i].second << '\n';
            for (auto c: v[i].second) {
                cout << c << " " << (c >= 'a' || born.find(c) != born.end()) << '\n';
                if (c >= 'a' || born.find(c) != born.end()) {
                    cnt++;
                }
            }
            if (cnt == v[i].second.size()) {
                for (auto c: v[i].second) {
                    if (tolower(c) != c) {
                        reachable.insert(c);
                    }
                }
            }
        }
    } while (sz != reachable.size());
    cout << '\n';
    for (auto ch : reachable) {
        cout << ch << " ";
    }

    for (auto i : alphabet) {
        if (reachable.find(i) == reachable.end()) {
            out << i << ' ';
        }
    }

}