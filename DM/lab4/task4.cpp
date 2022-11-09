#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("problem4.in");
    ofstream fout("problem4.out");
    int m, n, k, l;
    int _1, _2;
    char _3;
    fin >> n >> m >> k >> l;
    //cout << n << '\n';
    unordered_set <int> winCondition;
    for (int i = 0; i < k; i++) {
        fin >> _1;
        winCondition.emplace(_1);
    }
    vector <vector <int>> transitions(n + 2, vector <int> (n + 2, 0));
    for (int i = 0; i < m; i++) {
        fin >> _1 >> _2 >> _3;
        transitions[_1][_2]++;
    }

    //cout << n << '\n';
    vector <long long> vers(n + 1);
    vers[1] = 1;
    unordered_set <long long> s;
    s.emplace(1);
    //queue <int> q;
    //q.push(1);


    for (int numberTurn = 0; numberTurn < l; numberTurn++) {
        //int sizeQueue = q.size();
        vector <long long> newVers(n + 1, 0);
        unordered_set <long long> newS;
//        for (auto el : vers) {
//            cout << el;
//        }
        cout << '\n';
        for (auto el : s) {
            //int el = q.front();
            for (int ij = 0; ij < n+2; ij++) {
                if (!transitions[el][ij])continue;
                newVers[ij] += (transitions[el][ij] * vers[el]) % 1000000007;
                newVers[ij] = newVers[ij] % 1000000007;
                newS.emplace(ij);
            }
        }
        s = newS;
        vers = newVers;
    }


    long long count = 0;
    for (int i = 0; i < vers.size(); i++) {
        //cout << vers[i];
        if (winCondition.count(i)) {
            count += vers[i];
            count %= 1000000007;
        }
    }
    fout << count;

}





