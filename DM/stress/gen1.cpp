#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int len = rand() % 10;
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        int r = rand() % 2;
        if (r) {
            cout << "B ";
        } else {
            cout << "W ";
        }
        int pos = (rand() * RAND_MAX + rand()) % 1000000 - 500000;
        cout << pos << " ";
        int len = (rand() * RAND_MAX + rand()) % (500000 - pos);
        cout << len << '\n';
    }
    return 0;
}