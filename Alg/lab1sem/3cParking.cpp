#include <iostream>
#include <set>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	
	set <int> s;
	for (int i = 1; i <= n; i++){
		s.insert(i);
	}
 
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (s.find(a) != s.end()) {
			cout << a << " ";
			s.erase(s.find(a));
		}
		else {
			set <int> :: iterator it;
			it = s.lower_bound(a);
			if (*it > a) {
			    cout << *it << " ";
				s.erase(it);
				
			}
			else {
			    it = s.begin();
			    cout << *it << " ";
			    s.erase(it);
				
			}
		}
	}
 
	return 0;
}