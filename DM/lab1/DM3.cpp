//#include "pch.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
	int n, m, temp, maxDeep = 0;
	string temp2;
	cin >> n;
	vector <vector <int>> adjMatrix (n, vector <int>(n, 0));
	vector <vector <bool>> vecVertex(n);
	vector <int> deep(n, -1);
	vector <int> leaf;
	vector <vector <int>> inputEl(n);
	queue <int> q;
	for (int i = 0; i < n; i++) {
		cin >> m;
		inputEl[i].push_back(m);
		for (int j = 0; j < m; j++) {
			cin >> temp;
			adjMatrix[i][temp - 1] = 1;
			inputEl[i].push_back(temp - 1);
		}
		if (m != 0) {
			for (int j = 0; j < pow(2, m); j++) {
				cin >> temp;
				vecVertex[i].push_back(temp);
			}
		} else {
			leaf.push_back(i);
			deep[i] = 0;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (adjMatrix[i][now] == 1) {
				//if (deep[i] == -1) {
				q.push(i);
				//}
				//deep[i] = max(deep[now] + 1, deep[i]);
				deep[i] = max(deep[now] + 1, deep[i]);
				maxDeep = max(maxDeep, deep[i]);
			}
		}
	}
	//cout << '\n';
	//cout << deep[1] << " " << deep[5] << " " << deep[8] << " " << deep[13];
	//cout << '\n';

	vector <int> value(n);
	for (int i = 0; i < leaf.size(); i++) {
		value[leaf[i]] = 0;
	}
	value[leaf[leaf.size() - 1]] = -1;
	string ans = "";

	for (int k = 0; k < pow(2, leaf.size()); k++) {
		value[leaf[leaf.size() - 1]]++;
		for (int i = leaf.size() - 1; i >= 0; i--) {
			if (value[leaf[i]] == 2) {
				value[leaf[i - 1]]++;
				value[leaf[i]] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			if (inputEl[i][0] != 0) {
				m = inputEl[i][0];
				int weight = pow(2, m);
				int inputNum = 0;
				for (int j = 1; j <= m; j++) {
					weight /= 2;
					inputNum = inputNum + value[inputEl[i][j]] * weight;
				}
				value[i] = vecVertex[i][inputNum];
			}
		}
		ans += to_string(value[n - 1]);
	}
	cout << maxDeep << '\n';
	cout << ans;

	return 0;
}
