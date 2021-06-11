//Reversing an array, iteratively.

#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int start = 0, end = n - 1, temp;
    while(start < end) 
    {
        temp = v[start];
        v[start++] = v[end];
        v[end--] = temp;
    }
    for(auto x: v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}