#include <iostream>
#include <unordered_map>
#include <set>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("epsilon.in");
    ofstream fout("epsilon.out");
    int n;
    fin >> n;
    string start;
    fin >> start;

    unordered_multimap <char, string> trans;
    string s1, trash, s2, s;
    getline(fin, s);
    for (int i = 0; i < n; i++) {
        getline(fin, s);
        if (s.size() >= 5) {
            trans.insert(pair<char, string>(s[0], s.substr(5, s.size() - 5)));
        } else {
            trans.insert(pair<char, string>(s[0], ""));
        }
    }

//    for (auto el : trans) {
//        fout << el.first << " " << el.second << '\n';
//    }

    bool change = 1;
    set<char> mySet;
    while (change){
        change = 0;
        for (auto el : trans) {
            //cout << "TEST: " << el.first << " | " << el.second << '\n';
            if (!mySet.count(el.first)){
                //cout << "TESTIN: " << el.first << " | " << el.second << '\n';
                if (el.second == "") {
                    change = 1;
                    mySet.emplace(el.first);
                } else {
                    bool flag = 1;
                    for (auto elEl : el.second) {
                        //cout << "TESTININ: " << el.first << " | " << elEl << '\n';
                        if (!mySet.count(elEl)) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag) {
                        change = 1;
                        mySet.emplace(el.first);
                    }
                }
            }
        }
    }
    for (auto el : mySet) {
        fout << el << " ";
    }

    return 0;
}

