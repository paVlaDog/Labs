#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int sum;
    int add;
    int len = 1;
    int num;
    int lbo;
    int rbo;
};

vector <Node> vec;
int mySize;
int realSize;

void propagate(int pos) {
    
    
    vec[2*pos + 1].num = vec[pos].num;
    vec[2*pos + 2].num = vec[pos].num;
    vec[2*pos + 1].lbo = vec[pos].lbo;
    vec[2*pos + 2].lbo = vec[pos].lbo;
    vec[2*pos + 1].rbo = vec[pos].rbo;
    vec[2*pos + 2].rbo = vec[pos].rbo;
    vec[pos].add = 0;
}

void set(int l, int r, int pos, int xl, int xr, int val) {
    if (l >= xr || xl >= r) {
        return;
    }
    if (xl >= l && xr <= r) {
        if (val == -1) {
            vec[pos].add = -1;
            vec[pos].sum = 0;
            vec[pos].num = 0;
        } else if (val == 1) {
            vec[pos].add = 1;
            vec[pos].sum = vec[pos].len;
            vec[pos].num = 1;
        }
        vec[pos].lbo = val;
        vec[pos].rbo = val;
        return;
    }
    if (vec[pos].add != 0) {
        propagate(pos);
        vec[pos].add = 0;
    }
    int xm = (xl + xr) / 2;
    set(l, r, 2*pos+1, xl, xm, val);
    set(l, r, 2*pos+2, xm, xr, val);
    vec[pos].sum = vec[2*pos + 1].sum + vec[2*pos + 2].sum;
    vec[pos].lbo = vec[2*pos + 1].lbo;
    vec[pos].rbo = vec[2*pos + 2].rbo;
    vec[pos].num = vec[2*pos + 1].num + vec[2*pos + 2].num;
    if (vec[2*pos + 1].rbo == vec[2*pos + 2].lbo && vec[2*pos + 1].rbo == 1) {
        vec[pos].num--;
    }
}

void preSet(int l, int len, int val) {
    set (mySize - 2 + l, mySize - 2 + l + len, 0, mySize - 1, 2*mySize - 1, val);
}

void print() {
    int power = 2;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].sum << "|" << vec[i].add << "|" << vec[i].len << "|" << vec[i].num << "|" << vec[i].lbo << "|" << vec[i].rbo << "  ";
        if (i + 2 == power) {
            power *= 2;
            cout << '\n';
        }
    }
}

int main() {
    realSize = 1000000;
    mySize = 1;
    while (mySize < realSize) {
        mySize *= 2;
    }
    vec = vector <Node>(mySize * 2 - 1);
    for (int i = mySize - 2; i >= 0; i--) {
        vec[i].len = vec[2 * i + 1].len + vec[2 * i + 2].len;
    }
    string str;
    int pos, num, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        cin >> pos >> num;
        pos += (mySize / 2);
        if (str == "W") {
            preSet(pos, num, -1);
        } else if (str == "B") {
            preSet(pos, num, 1);
        }
        cout << vec[0].num << " " << vec[0].sum << '\n';
    }
    return 0;
}