//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

const long long neutral = 9223372036854775807;
int n, l, r;
int sz = 1;

struct Info {
    long long answer = neutral;
    long long prop_st = neutral;
    long long prop_add = 0;
};

vector<Info> tree;

void build() {
    for (int i = sz / 2 - 1; i >= 1; i--) {
        tree[i].answer = min(tree[i * 2].answer, tree[i * 2 + 1].answer);
    }
}

void propagate(int v) {
    if (v * 2 >= sz) {
        return;
    }

    if (tree[v].prop_st != neutral) {
        tree[v * 2].prop_st = tree[v].prop_st;
        tree[v * 2].answer = tree[v].prop_st;
        tree[v * 2].prop_add = 0;
        tree[v * 2 + 1] = tree[v * 2];
        tree[v].prop_st = neutral;
    }

    tree[v * 2].answer += tree[v].prop_add;
    tree[v * 2].prop_add += tree[v].prop_add;
    tree[v * 2 + 1].answer += tree[v].prop_add;
    tree[v * 2 + 1].prop_add += tree[v].prop_add;
    tree[v].prop_add = 0;
}

void st(int v, long long c_l, long long c_r, long long val) {

    propagate(v);

    if (c_r < l || c_l > r) {
        return;
    }
    if (c_l >= l && c_r <= r) {
        tree[v].answer = val;
        tree[v].prop_st = val;
        tree[v].prop_add = 0;
        return;
    }

    long long c_m = (c_l + c_r) / 2;
    st(v * 2, c_l, c_m, val);
    st(v * 2 + 1, c_m + 1, c_r, val);

    tree[v].answer = min(tree[v * 2].answer, tree[v * 2 + 1].answer);
}

void add(int v, long long c_l, long long c_r, long long val) {
    propagate(v);

    if (c_r < l || c_l > r) {
        return;
    }
    if (c_l >= l && c_r <= r) {
        tree[v].answer += val;
        tree[v].prop_add += val;
        return;
    }

    long long c_m = (c_l + c_r) / 2;
    add(v * 2, c_l, c_m, val);
    add(v * 2 + 1, c_m + 1, c_r, val);

    tree[v].answer = min(tree[v * 2].answer, tree[v * 2 + 1].answer);
}

long long mn(int v = 1, int cl = 1, int cr = sz / 2) {
    propagate(v);

    if (cr < l || cl > r) {
        return neutral;
    }
    if (cl >= l && cr <= r) {
        return tree[v].answer;
    }

    int cm = (cl + cr) / 2;

    return min(mn(v * 2, cl, cm), mn(v * 2 + 1, cm + 1, cr));
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    cin >> n;
    while (sz < n * 2) {
        sz *= 2;
    }
    tree.resize(sz);
    for (int i = sz / 2; i < sz / 2 + n; i++) {
        cin >> tree[i].answer;
    }
    build();

    string str;
    while (cin >> str) {

        if (str == "s") {
            break;
        }

        if (str == "set") {
            cin >> l >> r;
            long long x;
            cin >> x;
            st(1, 1, sz / 2, x);

        } else if (str == "min") {
            cin >> l >> r;
            cout << mn() << '\n';
        }
        else {
            cin >> l >> r;
            long long x;
            cin >> x;
            add(1, 1, sz / 2, x);
        }
    }
}