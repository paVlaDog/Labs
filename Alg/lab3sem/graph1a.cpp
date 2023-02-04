#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector <vector <bool>> use;
vector <vector <char>> vec;

void dfs (int i, int j) {
    use[i][j] = true;
    if (i > 0 && vec[i - 1][j] == 'O' && !use[i - 1][j]) dfs(i - 1, j);
    if (j > 0 && vec[i][j - 1] == 'O' && !use[i][j - 1]) dfs(i, j - 1);
    if (i < n - 1 && vec[i + 1][j] == 'O' && !use[i + 1][j]) dfs(i + 1, j);
    if (j < m - 1 && vec[i][j + 1] == 'O' && !use[i][j + 1]) dfs(i, j + 1);
}

int main() {
    int count = 0;
    string s;
    cin >> n >> m;
    vec = vector <vector <char>>(n, vector <char>(m));
    use = vector <vector <bool>>(n, vector <bool>(m, false));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            vec[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] == 'O' && !use[i][j]) {
                count++;
                dfs(i, j);
            }
        }
    }


    cout << count;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << use[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
