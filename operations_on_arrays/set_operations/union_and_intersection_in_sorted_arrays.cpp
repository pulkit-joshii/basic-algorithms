#include<bits/stdc++.h>

using namespace std;

vector <int> unions(vector <int> a, vector <int> b, int n, int m) {
    vector <int> c;
    int i = 0, l = 0, r = 0;
    while(l < n && r < m) {
        if(a[l] < b[r]) {
            c.push_back(a[l++]);
        }
        else if(a[l] > b[r]) {
            c.push_back(b[r++]);
        }
        else {
            c.push_back(a[l]);
            l++; r++;
        }
    }
    while(l < n) {
        c.push_back(a[l++]);
    }
    while(r < m) {
        c.push_back(b[r++]);
    }
    return c;
}

vector <int> intersection(vector <int> a, vector <int> b, int n, int m) {
    vector <int> c;
    int l = 0, r = 0;
    while(l < n && r < m) {
        if(a[l] < b[r]) {
            l++;
        }
        else if(a[l] > b[r]) {
            r++;
        }
        else {
            c.push_back(a[l]);
            l++; r++;
        }
    }
    return c;
}

int main() {
    int size1, size2;
    cin >> size1 >> size2;
    vector <int> a(size1), b(size2);
    for (int i = 0; i < size1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < size2; i++) {
        cin >> b[i];
    }
    vector <int> c = unions(a, b, size1, size2);
    vector <int> d = intersection(a, b, size1, size2);
    for (auto e: c) {
        cout << e << " ";
    }
    cout << "\n";
    for(auto e: d) {
        cout << e << " ";
    }
}
