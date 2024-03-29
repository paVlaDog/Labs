#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	long long n, sum = 0;
	cin >> n;
	map <int, pair<long long, long long>> m;
	vector <pair<long long, vector <int>>> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first;
		vec[i].second = vector <int>(1, i);
		m[i] = make_pair(vec[i].first, 0);
	}
	if (n == 1) {
		m[0].second++;
	}
	for (long long i = 0; i < n - 1; i++) {
		sort(vec.begin() + i, vec.end());
		for (int j = 0; j < vec[i + 1].second.size(); j++) {
			m[vec[i + 1].second[j]].second++;
		}
		for (int j = 0; j < vec[i].second.size(); j++) {
			m[vec[i].second[j]].second++;
			vec[i + 1].second.push_back(vec[i].second[j]);
		}
		vec[i + 1].first += vec[i].first;
	}
	for (int i = 0; i < n; i++) {
		sum += m[i].first * m[i].second;
	}
	cout << sum;
}