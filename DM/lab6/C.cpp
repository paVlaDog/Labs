#include <iostream>
#include <vector>

using namespace std;

string ans;

vector <int> merge(vector<int> vec1, vector<int> vec2) {
    int a = 0, b = 0;
    vector<int> vec = vector<int>(vec1.size() + vec2.size());
    while (a + b < vec1.size() + vec2.size()) {
        if (a == vec1.size()) {
            vec[a + b] = vec2[b];
            b++;
        } else if (b == vec2.size()) {
            vec[a + b] = vec1[a];
            a++;
        } else {
            cout << "1 " << vec1[a] << " " << vec2[b] << endl;
            cout.flush();
            cin >> ans;
            if (ans == "YES") {
                vec[a + b] = vec1[a];
                a++;
            } else {
                vec[a + b] = vec2[b];
                b++;
            }
        }
    }
    return vec;
}

vector<int> mergeSort(vector<int> vec) {
    if (vec.size() > 2) {
        vector<int> vec1(vec.begin(), vec.begin() + (int)vec.size()/2);
        vector<int> vec2(vec.begin() + (int)vec.size()/2, vec.begin() + (int)vec.size());
        vec1 = mergeSort(vec1);
        vec2 = mergeSort(vec2);
        return merge(vec1, vec2);
    } else {
        if (vec.size() == 1) {
            return vec;
        }
        cout << "1 " << vec[0] << " " << vec[1] << endl;
        cout.flush();
        cin >> ans;
        if (ans == "NO") {
            swap(vec[0], vec[1]);
        }
        return vec;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vec = vector <int>(n);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = i+1;
    }
//    merge()
    vec = mergeSort(vec);
    cout << "0 ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return 0;
}
