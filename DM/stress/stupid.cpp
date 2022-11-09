#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long NEUTRAL = 9223372036854775807;

struct Node {
    long long mini = NEUTRAL;
    long long add = 0;
    long long set = NEUTRAL;
};

vector <Node> vec;
long long sz;
long long realSize;

void setMin (long long pos) {
    if (2*pos + 2 < vec.size()) {
        vec[pos].mini = min(vec[2*pos + 1].mini, vec[2*pos + 2].mini);
    }
    if (vec[pos].set != NEUTRAL) {
        vec[pos].mini = vec[pos].set;
    }
    if (vec[pos].add != 0) {
        vec[pos].mini += vec[pos].add;
    }
}

void propagate(long long pos) {
    if (2*pos + 1 >= vec.size()) {
        setMin(pos);
        return;
    }
    for (long long i = 1; i <= 2; i++) {
        if (vec[pos].add != 0) {
            if (vec[2*pos + i].set != NEUTRAL) {
                vec[2*pos + i].set += vec[pos].add;
            } else {
                vec[2*pos + i].add += vec[pos].add;
            }
        }
        if (vec[pos].set != NEUTRAL) {
            vec[2*pos + i].set = vec[pos].set;
            vec[2*pos + i].add = 0;
        }
        setMin(2*pos + i);
    }
    vec[pos].add = 0;
    vec[pos].set = NEUTRAL;
    setMin(pos);
}

void set(long long l, long long r, long long pos, long long xl, long long xr, long long val) {
    if (l >= xr || xl >= r) {
        setMin(pos);
        return;
    }
    if (xl >= l && xr <= r) {
        if (vec[pos].add != 0) {
            vec[pos].add = 0;
        }
        vec[pos].set = val;
        setMin(pos);
        return;
    }
    propagate(pos);
    long long xm = (xl + xr) / 2;
    set(l, r, 2*pos+1, xl, xm, val);
    set(l, r, 2*pos+2, xm, xr, val);
    setMin(pos);
}

void preSet(long long l, long long r, long long val) {
    set(sz - 2 + l, sz - 2 + r + 1, 0, sz - 1, 2*sz - 1, val);
}

void add(long long l, long long r, long long pos, long long xl, long long xr, long long val) {
    if (l >= xr || xl >= r) {
        setMin(pos);
        return;
    }
    if (xl >= l && xr <= r) {
        if (vec[pos].set != NEUTRAL) {
            vec[pos].set += val;
        } else {
            vec[pos].add += val;
        }
        setMin(pos);
        return;
    }
    propagate(pos);
    long long xm = (xl + xr) / 2;
    add(l, r, 2*pos+1, xl, xm, val);
    add(l, r, 2*pos+2, xm, xr, val);
    setMin(pos);
}

void preAdd(long long l, long long r, long long val) {
    add(sz - 2 + l, sz - 2 + r + 1, 0, sz - 1, 2*sz - 1, val);
}

long long mi(long long l, long long r, long long pos, long long xl, long long xr) {
    if (l >= xr || xl >= r) {
        setMin(pos);
        return NEUTRAL;
    }
    if (xl >= l && xr <= r) {
        setMin(pos);
        return vec[pos].mini;
    }
    propagate(pos);
    long long xm = (xl + xr) / 2;
    long long ans = min(mi(l, r, 2*pos+1, xl, xm), mi(l, r, 2*pos+2, xm, xr));
    setMin(pos);
    return ans;
}

long long preMi(long long l, long long r) {
    return mi(sz - 2 + l, sz - 2 + r + 1, 0, sz - 1, 2*sz - 1);
}

void print() {
    long long power = 2;
    for (long long i = 0; i < vec.size(); i++) {
        cout << vec[i].mini << "|" << vec[i].add << "|" << vec[i].set << "  ";
        if (i + 2 == power) {
            power *= 2;
            cout << '\n';
        }
    }
}

int main() {
    cin >> realSize;
    sz = 1;
    while (sz < realSize) {
        sz *= 2;
    }
    vec = vector <Node>(sz * 2 - 1);
    for (long long i = sz - 1; i < sz + realSize - 1; i++) {
        cin >> vec[i].mini;
    }
    for (long long i = sz - 2; i >= 0; i--) {
        vec[i].mini = min(vec[2 * i + 1].mini, vec[2 * i + 2].mini);
    }
    string str;
    long long num1, num2, val;
    //print();
    while (cin >> str) {
        if (str == "min") {
            cin >> num1 >> num2;
            //print();
            cout << preMi(num1, num2) << '\n';
        }
        if (str == "set") {
            cin >> num1 >> num2 >> val;
            preSet(num1, num2, val);
            //print();
        }
        if (str == "add") {
            cin >> num1 >> num2 >> val;
            preAdd(num1, num2, val);
            //print();
        }
    }
    return 0;
}