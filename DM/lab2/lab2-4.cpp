#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main()
{
    string s; 
    cin >> s;
    vector <char> code(26);
    for (int i = 0; i < 26; i++) {
        code[i] = 'a' + (char)i;
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (code[j] == s[i]) {
                cout << j + 1 << " ";
                char temp = code[j];
                for (int k = j; k > 0; k--) {
                    code[k] = code[k - 1];
                }
                code[0] = temp;
                break;
            }
        }
    }
    return 0;
}