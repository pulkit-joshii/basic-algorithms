/* Quickselect algorithm is used to find the kth maximum/minimum element in an array.
Partition approach used in quick sort can be applied for the above.
*/

#include<bits/stdc++.h>

using namespace std;

int partition(vector <int> array, int start, int end)
{
    int pivot = array[end];
    int i = start - 1;
    for(int j = start; j < end; j++) 
    {
        if(pivot >= array[j]) 
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[end]);
    return i + 1;
}

int quick_select(vector <int> array, int start, int end, int k)
{
    int pivot_index = partition(array, start, end);
    if(pivot_index - start == k - 1)
    {
        return array[pivot_index];
    }
    if(pivot_index - start > k - 1) 
    {
        return quick_select(array, start, pivot_index - start, k);
    }
    else 
        return quick_select(array, pivot_index + 1, end, k - 1 - (pivot_index - start)); 
}

int main()
{
    int size, k;
    cin >> size >> k;
    vector <int> a(size);
    for(int i = 0; i < size; i++) 
    {
        cin >> a[i];
    }
    int start = 0, end = size - 1;
    int location = quick_select(a, start, end, k);
    cout << location << endl;
}