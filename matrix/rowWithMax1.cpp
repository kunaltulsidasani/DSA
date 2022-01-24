//Row with max 1s
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    //Check coloumn wise to obtain the first 1 and return that row
        for(int col=0; col<m; col++){
	        for(int row=0; row<n; row++){
	            if(arr[row][col]==1){
	                return row;
	            }
	        }
	    }
	    return -1;
	}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}