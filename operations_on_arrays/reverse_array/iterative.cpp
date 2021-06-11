//Reversing an array, iteratively.

#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int size;
    cin >> size;
    vector <int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    int start = 0, end = size - 1, temp;
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