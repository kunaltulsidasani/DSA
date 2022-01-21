// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
// Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    int p1=n-1, p2=0;
	    while(p1>=0 && p2<m){
	        if(arr1[p1]>arr2[p2]){
	            swap(arr1[p1], arr2[p2]);
	        }
	        p1--;
	        p2++;
	    }
	    
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+m);
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} 