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
    vector <string> vec(s.size(), "");
    for (int j = 0; j < s.size(); j++) {
        for (int i = 0; i < s.size(); i++) {
            vec[i] = s[i] + vec[i];
        }
        sort(vec.begin(), vec.end());
    }
    cout << vec[0];
}