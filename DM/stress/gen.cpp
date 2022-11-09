#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int len = rand() % 16 + 1;
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        int r = rand() % 50000 - 25000;
        cout << r << " ";
    }
    int lenQuest = rand() % 30;
    cout << '\n' << lenQuest << '\n';
    for (int i = 0; i < lenQuest; i++) {
        int type = rand() % 3;
        int num1 = rand() % len + 1;
        int num2 = rand() % (len - num1 + 1) + num1 + 1;
        if (type == 0) {
            cout << "min " << num1 << " " << num2 << '\n';
        }
        if (type == 1) {
            cout << "set " << num1 << " " << num2 << " " << (rand() % 50000 - 25000) << '\n';
        }
        if (type == 2) {
            cout << "add " << num1 << " " << num2 << " " << (rand() % 50000 - 25000) << '\n';
        }
    }
    return 0;
}