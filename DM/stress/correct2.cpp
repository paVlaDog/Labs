#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int toDec(std::string bin) {
	int result = 0;
	int p = 1;
	for (int i = bin.length() - 1; i >= 0; i--) {
		if (bin[i] == '1') {
			result += p;
		}
		p = p * 2;
	}
	return result;
}
std::string toBin(int x, int count) {
	std::string arg = "";
	int num = 1;
	while (num <= x) {
		if ((x & num) != 0)
			arg = '1' + arg;
		else
			arg = '0' + arg;
		num *= 2;
	}
	if (count > 0) {
		while (arg.length() < count) {
			arg = '0' + arg;
		}
	}
	else {
		if (arg == "") arg = "0";
	}
	return arg;
}

int depth(std::vector<std::vector<int>>& a, int pos, int count) {
	if (a[pos][0] == 0)
		return count;
	int result = depth(a, a[pos][0] - 1, count + 1);
	for (int i = 1; i < a[pos].size(); i++) {
		result = std::max(result, depth(a, a[pos][i] - 1, count + 1));
	}
	return result;
}

int main() {

	std::iostream::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::vector<int>>a;
	std::vector<std::string>f;
	int count_args = 0;
	for (int i = 0; i < n; i++) {
		int count_var;
		std::cin >> count_var;
		if (count_var == 0) {
			a.push_back({ 0 });
			count_args++;
			f.push_back("01");
		}
		else {
			a.push_back({});
			for (int j = 0; j < count_var; j++) {
				int var;
				std::cin >> var;
				a[a.size() - 1].push_back(var);
			}
			std::string v;
			for (int j = 0; j < (2 << count_var - 1); j++) {
				char c;
				std::cin >> c;
				v += c;
			}
			f.push_back(v);
			//a[a.size() - 1].push_back(f.size() - 1);
		}
	}
	std::cout << depth(a, a.size() - 1, 0) << "\n";
	for (int argDec = 0; argDec < (2 << count_args - 1); argDec++) { //��� ��������� ������ ����������
		std::vector<int>results;
		results.resize(a.size());
		int c_args = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i][0] == 0) {
				results[i] = ((argDec >> (count_args - c_args++ - 1)) % 2);
			}
			else {
				std::string v = f[i];
				std::string args;
				for (int j = 0; j < a[i].size(); j++) {
					if (results[a[i][j] - 1] == 0) args += '0'; else args += '1';
				}
				if (v[toDec(args)] == '0') results[i] = 0; else results[i] = 1;
			}
		}
		std::cout << results[a.size() - 1];
	}
}