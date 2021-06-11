/* Tournament method is the best approach to find the minimum and the maximum in an array.
(n - 1) comparisons are done to find the maximum element, and then (n / 2 - 1) comparisons are done in 
the n / 2 small elements in the array. Therefore, at most (3*n / 2 - 2) comparisons are done.
*/

#include<bits/stdc++.h>

using namespace std;

pair <int,int> maxmin(vector <int> array, int start, int end) 
{
    pair <int,int> minmax;      // minmax is a pair representing (min, max)
    if(start == end) 
    {
        minmax = make_pair(array[start], array[start]);
        return minmax;
    }
    else if(start == end - 1) 
    {
        if(array[start] < array[end])
        {
            minmax = make_pair(array[start], array[end]);
        }
        else
        {
            minmax = make_pair(array[end], array[start]);
        }
        return minmax;
    }
    else
    {
        int mid = (start + end) / 2;
        pair <int,int> left_min_max = maxmin(array, start, mid);
        pair <int,int> right_min_max = maxmin(array, mid + 1, end);
        if(left_min_max.first < right_min_max.first)    //comparing minimums of left and right array
        {
            minmax.first = left_min_max.first;
        }
        else
        {
            minmax.first = right_min_max.first;
        }
        if(left_min_max.second < right_min_max.second)    //comparing maximums of left and right array
        {
            minmax.second = right_min_max.second;
        }
        else
        {
            minmax.second = left_min_max.second;
        }
        return minmax;
    }
}

int main()
{
    int size;
    cin >> size;
    vector <int> a(size);
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    int start = 0, end = size - 1;
    pair <int,int> minmax = maxmin(a, start, end);
    cout << minmax.first << " " << minmax.second << endl;

}
