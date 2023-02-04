#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
 
using namespace std;
 
vector <int> parent;
 
int find_parent(int number){
	int ans = number;
	if (number != parent[number]) {
		ans = find_parent(parent[number]);
		parent[number] = ans;
	}
	return ans;
}
 
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	parent.resize(n + 1);
	for (int i = 0; i <= n + 1; i++) {
		parent[i] = i;
	}
 
	vector <pair<int, int>> graph(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[i] = {a, b};
	}
 
	vector <pair<string, pair<int, int>>> vec(k);
	for (int i = 0; i < k; i++) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		vec[i].first = s;
		vec[i].second.first = a;
		vec[i].second.second = b;
	}
 
	vector <string> ans(0);
	for (int i = k - 1; i >= 0; i--) {
		if (vec[i].first == "ask") {
			int a = vec[i].second.first;
			int b = vec[i].second.second;
			a = find_parent(a);
			b = find_parent(b);
			if (a == b) {
				ans.push_back("YES");
			} else {
				ans.push_back("NO");
			}
		} 
		else {
			if (vec[i].first == "cut") {
				int a = vec[i].second.first;
				int b = vec[i].second.second;
				a = find_parent(a);
				b = find_parent(b);
				parent[a] = b;
			}
		}
	}
 
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
 
	return 0;
}