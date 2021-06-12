#include<bits/stdc++.h>

using namespace std;

int search(vector <int> array, int start, int end, int target)
{
    int mid = start + (end - start) / 2;
    if(start > end)
    {
        return -1;
    }
    if(array[mid] == target)
    {
        return mid + 1;
    }
    if(array[mid] < target)
    {
        return search(array, mid + 1, end, target);
    }
    else
        return search(array, start, mid - 1, target);
}

int main() 
{
    int size, target;
    cin >> size;
    vector <int> a(size);
    for(int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cin >> target;
    int location = search(a, 0, size - 1, target);
    cout << location;
}