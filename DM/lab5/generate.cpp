#include <iostream>
#include <ctime>

using namespace std;

char randSymba() {
    return ((rand() % 26) + 'a');
}

char randSymbA() {
    return ((rand() % 26) + 'A');
}

string randStroke() {
    int len = rand() % 51;
    string str = "";
    for (int i = 0; i < len; i++) {
        if (rand() % 2) {
            str += randSymba();
        } else {
            str += randSymbA();
        }
    }
    return str;
}

int main() {
    srand( time( 0 ));
    int s = rand() % 100 + 1;
    cout << s << " " << randSymbA() << '\n';
    for (int i = 0; i < s; i++) {
        cout << randSymbA() << " -> " << randStroke() << '\n';
    }
}

