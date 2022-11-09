#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	string ans;
	
	string s1 = s;
	int len = s.size();
	bool flag1 = 0, flag2 = 0;
	for (int i = len; i > -1 && !flag2; i--) {
		if (s1[i] == '1') {
			flag1 = 1;
		} 
		if (flag1 == 1) {
			if (s1[i] == '1') {
				s1[i] = '0';
			} 
			else {
				s1[i] = '1';
				flag2 = 1;
			}
		}
		else if (s1[i] == '0') {
			s1[i] = '1';
			flag1 = 1;
			flag2 = 1;
			break;
		}
	}

	if (flag1 && !flag2) {
		//ans += "1";
		//for (int i = 0; i < len; i++) {
		//	ans += "0";
		//};
		ans = "-";
	} else if (!flag2) {
		ans = "1";
	}

	if (flag2) {
		ans = s1;
	}

	string s2 = s;
	flag1 = 0;
	flag2 = 0;
	int i;
	for (i = len - 1; i > -1 && !flag1; i--) {
		if (s2[i] == '1') {
			flag1 = 1;
			break;
		} 
	}
	if (!flag1){
	    cout << "-";
	}
	else if (len == 1) {
	    if (s2[0] == '0'){
	        cout << "-";   
	    }
	    else {
	        cout << "0"; 
	    }
	}
	else{
		for (; i < len; i++) {
		    if (s2[i] == '1') {
				s2[i] = '0';
			}
            else if (s2[i] == '0') {
				s2[i] = '1';
			}
		}
		if (flag1) {
		//    if (s2[0] == '0') {
		//    	for (int j = 1; j < len; j++) {
		//    		cout << s2[j];
		//    	}
		//    }
		//    else {
		        cout << s2;
		//    }
		} else {
		    cout << s2[-1];
		}
	}
	
	cout << endl;
	cout << ans;
}