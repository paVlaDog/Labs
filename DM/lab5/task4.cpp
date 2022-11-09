#include <iostream>
#include <unordered_map>
#include <set>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    ifstream fin("nfc.in");
    ofstream fout("nfc.out");
    int n;
    fin >> n;
    string start;
    fin >> start;

    set<char> allSymb;
    for (int i = 0; i < 26; i++) {
        allSymb.emplace((char)(i + (int)'A'));
    }

    unordered_multimap <char, string> trans;
    string s1, trash, s2, s;
    getline(fin, s);
    for (int i = 0; i < n; i++) {
        getline(fin, s);
        allSymb.emplace(s[0]);
        if (s.size() >= 5) {
            trans.insert(pair<char, string>(s[0], s.substr(5, s.size() - 5)));
        } else {
            trans.insert(pair<char, string>(s[0], ""));
        }
    }

    string quest;
    fin >> quest;
    vector<vector<vector<int>>> vec(quest.size(), vector<vector<int>>(quest.size(), vector<int>(allSymb.size(), 0)));

    for (int i = 0; i < quest.size(); i++) {
        for (int j = 0; j < quest.size() - i; j++) {
            if (0 == i) {
                for (auto el : trans) {
                    if (el.second.size() == 1 && el.second[0] == quest[j]) {
                        vec[j][i][el.first - 'A'] += 1;
                    }
                }
            } else {
                for (auto el : trans) {
                    if (el.second.size() == 2) {
                        cout << el.first << " -> " << el.second << '\n';
                        for (int k = 0; k < i; k++) {
                            vec[j][i][el.first - 'A'] = (vec[j][i][el.first - 'A'] + (vec[j][k][el.second[0] - 'A'] * vec[j + k + 1][i - k - 1][el.second[1] - 'A']) % 1000000007) % 1000000007;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < quest.size() - i; j++) {
            for (int k = 0; k < 4; k++) {
                cout << vec[j][i][k];
            }
            cout << " ";
        }
        cout << '\n';
    }

    int counter = vec[0][quest.size() - 1][start[0] - 'A'];
    fout << counter;
    cout << counter;

    return 0;
}

