//Reversing an array, recursively.

#include <bits/stdc++.h>

using namespace std;

vector <int> reverse(vector <int> array, int start, int end) 
{
    if(start >= end) 
    {
        return array;
    }
    int temp = array[start];
    array[start] = array[end];
    array[end] = temp;
    return reverse(array, start + 1, end - 1);
}


int main() 
{
    int size;
    cin >> size;
    vector <int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }
    int start = 0, end = size - 1;
    vector <int> reversedArray = reverse(v, start, end);
    for(auto element: reversedArray)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}