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
	vector <string> vec(s.size());
	for (int i = 0; i < s.size(); i++) {
		vec[i] = s.substr(i, s.size());
		vec[i] += s.substr(0, i);
	}
	sort(vec.begin(), vec.end());
	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		ans += vec[i][s.size() - 1];
	}
	cout << ans;
	return 0;
}

