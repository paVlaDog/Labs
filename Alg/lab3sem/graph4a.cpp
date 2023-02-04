#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

vector <pair <int, int>> vert;
vector <bool> use;
vector <double> dist;
//priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> k;

double evclid(int a1, int b1, int a2, int b2) {
    return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
}

int main() {
    int n;
    cin >> n;
    vert = vector <pair <int, int>>(n);
    use = vector<bool>(n, false);
    dist = vector<double>(n, 10000000);
    for (int i = 0; i < vert.size(); i++) {
        cin >> vert[i].first >> vert[i].second;
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }
    double minDeg = evclid(vert[0].first, vert[0].second, vert[1].first, vert[1].second);
    int start = 0, finish = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double curDeg = sqrt((vert[i].first - vert[j].first) * (vert[i].first - vert[j].first) +
                              (vert[i].second - vert[j].second) * (vert[i].second - vert[j].second));
            if (curDeg < minDeg) {
                minDeg = curDeg;
                start = i;
                finish = j;
            }
        }
    }

    double sum = 0;
    int cur = start;
    dist[cur] = 0;
    for (int cou = 0; cou < n; cou++) {
        use[cur] = true;
        sum += dist[cur];
        for (int i = 0; i < n; i++) {
            if (!use[i]) {
                dist[i] = min(evclid(vert[cur].first, vert[cur].second, vert[i].first, vert[i].second), dist[i]);
            }
        }

        double minDist = 10000000;
        for (int i = 0; i < n; i++) {
            if (!use[i] && dist[i] < minDist) {
                cur = i;
                minDist = dist[i];
            }
        }
    }

    cout << setprecision(10) << fixed;
    cout << sum;
    return 0;
}