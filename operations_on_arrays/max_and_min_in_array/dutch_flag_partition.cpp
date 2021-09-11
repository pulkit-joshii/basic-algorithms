/*
DNFP can be used in the problem given.
Problem: Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the array, without using any sorting algorithms.
Solution: By DNFP, O(n) time and O(1) space used.
*/

#include<bits/stdc++.h>

using namespace std;

vector <int> dnfp_sort(vector <int> a, int n) {
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high) {
        switch(a[mid]) {
            case 0:
                swap(a[low++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid], a[high--]);
                break;
        }
    }
    return a;
}

int main() {
    int size;
    cin >> size;
    vector <int> a(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    a = dnfp_sort(a, size);
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}
