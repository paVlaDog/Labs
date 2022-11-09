#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

const long long NEUTRAL = 2147483647;

struct Node {
    long long mini = NEUTRAL;
    long long add = 0;
    long long set = NEUTRAL;
};

vector <Node> vec;
vector<pair<int, pair<int, int>>> vect;
long long sz;
long long realSize;

void propagate(long long pos) {
    if (2*pos + 1 >= vec.size()) {
        return;
    }
    for (long long i = 1; i <= 2; i++) {
        if (vec[pos].add != 0) {
            if (vec[2*pos + i].set != NEUTRAL) {
                vec[2*pos + i].set += vec[pos].add;
                vec[2*pos + i].mini = vec[2*pos + i].set;
            } else {
                vec[2*pos + i].add += vec[pos].add;
                vec[2*pos + i].mini += vec[pos].add;
            }
        }
        if (vec[pos].set != NEUTRAL) {
            vec[2*pos + i].set = vec[pos].set;
            vec[2*pos + i].mini = vec[pos].set;
            vec[2*pos + i].add = 0;
        }
    }
    vec[pos].add = 0;
    vec[pos].set = NEUTRAL;
}

void set(long long l, long long r, long long pos, long long xl, long long xr, long long val) {
    propagate(pos);
    if (l >= xr || xl >= r) {
        return;
    }
    if (xl >= l && xr <= r) {
        if (vec[pos].add != 0) {
            vec[pos].add = 0;
        }
        vec[pos].set = val;
        vec[pos].mini = val;
        return;
    }
    long long xm = (xl + xr) / 2;
    set(l, r, 2*pos+1, xl, xm, val);
    set(l, r, 2*pos+2, xm, xr, val);
    vec[pos].mini = min(vec[2*pos + 1].mini, vec[2*pos + 2].mini);
}

void preSet(long long l, long long r, long long val) {
    set(sz - 2 + l, sz - 2 + r + 1, 0, sz - 1, 2*sz - 1, val);
}

void add(long long l, long long r, long long pos, long long xl, long long xr, long long val) {
    propagate(pos);
    if (l >= xr || xl >= r) {
        return;
    }
    if (xl >= l && xr <= r) {
        if (vec[pos].set != NEUTRAL) {
            vec[pos].set += val;
        } else {
            vec[pos].add += val;
        }
        vec[pos].mini += val;
        if (2*pos + 2 >= vec.size()) {
            vec[pos].add = 0;
        }
        return;
    }
    long long xm = (xl + xr) / 2;
    add(l, r, 2*pos+1, xl, xm, val);
    add(l, r, 2*pos+2, xm, xr, val);
    vec[pos].mini = min(vec[2*pos + 1].mini, vec[2*pos + 2].mini);
}

void preAdd(long long l, long long r, long long val) {
    add(sz - 2 + l, sz - 2 + r + 1, 0, sz - 1, 2*sz - 1, val);
}

long long mi(long long l, long long r, long long pos, long long xl, long long xr) {
    propagate(pos);
    if (l >= xr || xl >= r) {
        return NEUTRAL;
    }
    if (xl >= l && xr <= r) {
        return vec[pos].mini;
    }
    long long xm = (xl + xr) / 2;
    long long ans = min(mi(l, r, 2*pos+1, xl, xm), mi(l, r, 2*pos+2, xm, xr));
    return ans;
}

long long preMi(long long l, long long r) {
    return mi(sz - 2 + l, sz - 2 + r + 1, 0, sz - 1, 2*sz - 1);
}

void print() {
    long long power = 2;
    for (long long i = 0; i < vec.size(); i++) {
        cout << vec[i].mini << "|" << vec[i].add << "|" << (vec[i].set != NEUTRAL ? vec[i].set : 0) << "  ";
        if (i + 2 == power) {
            power *= 2;
            cout << '\n';
        }
    }
}

int main() {
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");
    fin >> realSize;
    sz = 1;
    while (sz < realSize) {
        sz *= 2;
    }
    vec = vector <Node>(sz * 2 - 1);
    for (long long i = sz - 2; i >= 0; i--) {
        vec[i].mini = min(vec[2 * i + 1].mini, vec[2 * i + 2].mini);
    }

    int m;
    fin >> m;
    vect = vector<pair<int, pair<int, int>>>(m);
    for (int i = 0; i < m; i++) {
        fin >> vect[i].second.first >> vect[i].second.second >> vect[i].first;
    }
    sort(vect.begin(), vect.end());
    for (int i = 0; i < m; i++) {
        preSet(vect[i].second.first, vect[i].second.second, vect[i].first);
    }
    print();
    bool flag = 0;
    for (int i = 0; i < m; i++) {
        if (preMi(vect[i].second.first, vect[i].second.second) != vect[i].first) {
            flag = 1;
        }
    }
    if (flag == 0) {
        fout << "consistent\n";
        cout << "consistent\n";
        for (int i = 1; i <= realSize; i++) {
            long long ans = preMi(i, i);
                fout << ans << " ";
                cout << ans << " ";
        }
    } else {
        fout << "inconsistent\n";
        cout << "inconsistent\n";
    }
    return 0;
}