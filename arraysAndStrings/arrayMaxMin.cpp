// Maximum and minimum of an array using minimum number of comparisons
// Time Complexoty - O(N)
// Space Complexoty - O(1)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t; // testcases
    cin >> t;
    while (t--) {
        int n;
        cin >> n; //size of array
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<ll, ll> minmax;
    
    // set minimum and maximum as a[0]
    ll mini = a[0], maxi = a[0];
    // compare each element of array to get maximum and minimum
    for(int i=1; i<n; i++){
        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
    }
    
    minmax.first = mini;
    minmax.second = maxi;
    
    return minmax;
}