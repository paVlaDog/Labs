#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
vector<pair<int, int>> vec;
int find_parent(int a ) {
    if(a == vec[a].second) return a;
    return vec[a].second = find_parent(vec[a].second);
}
 
int main()
{
	int n, m;
	string s;
	cin >> n >> m;
	vec.resize(n + 1);
	for(int i = 0; i <= n; i++){
	    vec[i] = {0, i};
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s == "join") {
			int a, b;
			cin >> a >> b;
			a = find_parent(a);
			b = find_parent(b);
			if (a != b) {
				vec[a].first -= vec[b].first;
				vec[a].second = b;
			}
		}
		else if (s == "add") {
			int a, b;
			cin >> a >> b;
			a = find_parent(a);
			vec[a].first += b;
		}
		else if (s == "get") {
			int a;
			cin >> a;
			int sum = vec[a].first;
			int trash = find_parent(a);
			while (vec[a].second != a) {
				a = vec[a].second;
				sum += vec[a].first;
			}
			cout << sum << '\n';
		}
	}
}