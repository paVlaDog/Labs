#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
long long l, r, mid, ma = 0, c = 0, n, k;
cin >> n;
cin >> k;
vector <long long> vec(n);
for (int i = 0; i < n; i++){
    cin >> vec[i];
    if (vec[i] > ma)ma = vec[i];
}
l = 0;
r = ma + 1;
while (l + 1 != r){
    mid = (l + r)/2;
    c = 0;
    for (int i = 0; i < n; i++){
        c+=vec[i]/mid;
    }
    if (c < k)r = mid;
    else l = mid;
}
cout << l;
return 0;
}