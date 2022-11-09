#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main()
{
    string s, buffer = ""; 
    cin >> s;
    map <string, int> m;
    for (int i = 0; i < 26; i++) {
        m[string(1, i + 'a')] = i;
    }
    int number = 26;
    for (int i = 0; i < s.size(); i++) {
        buffer = buffer + s[i];
        if (m.find(buffer) != m.end()) {
            continue;
        }
        cout << m[buffer.substr(0, buffer.size() - 1)] << " ";
        m[buffer] = number;
        number++;
        buffer = buffer[buffer.size() - 1];
    }
    cout << m[buffer];
}