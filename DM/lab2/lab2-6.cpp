#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
 
using namespace std;
 
 
string decode(vector <int> vec) {
    int n, number = 26;
    map <string, int> m1;
    map <int, string> m2;
    string buffer = "", ans = "";
    for (int i = 0; i < 26; i++) {
        m1[string(1, i + 'a')] = i;
        m2[i] = string(1, i + 'a');
    }
    int num;
    for (int i = 0; i < vec.size(); i++) {
        num = vec[i];
        if (m2.find(num) == m2.end()) {
            buffer = buffer + buffer[0];
            m2[number] = buffer;
            m1[buffer] = number;
            number++;
            ans.append(m2[num]);
             
            continue;
        }
        string s = m2[num];
        ans += m2[num];
        for (int j = 0; j < s.size(); j++) {
            if (buffer != "") {
                buffer += s[j];
                if (m1.find(buffer) == m1.end()) {
                    m2[number] = buffer;
                    m1[buffer] = number;
                    number++;
                    break;
                }
            }
        }
        buffer = m2[num];
    }
    return ans;
}
 
int main()
{
    int n;
    cin >> n;
    vector <int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    cout << decode(vec);
}