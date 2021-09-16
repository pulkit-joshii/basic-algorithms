/*
Kadane's Algorithm is used to find the maximum subarray sum.
*/

#include<bits/stdc++.h>

using namespace std;

// this function return the maximum subarray sum and the start and end indices respectively.
tuple <int, int, int> maxSubarraySum(vector <int> a, int size) {
    int max = 0, t = 0, start = 0, end = 0, s = 0;
    for(int i = 0; i < size; i++) {
        t += a[i];
        if(max < t) {
            max = t;
            end = i;
            start = s;
        }
        if(t < 0) {
            t = 0;
            s = i + 1;
        }
    }
    return make_tuple(max, start, end);
}

int main() {
    int size;
    cin >> size;
    vector <int> a(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    tuple <int, int, int> mss = maxSubarraySum(a, size);
    cout << get<0>(mss) << " " << get<1>(mss) << " " << get<2>(mss);
}
