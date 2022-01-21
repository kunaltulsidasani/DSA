// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int c = 0;
        for(int i=0; i<n; i++){
            if(arr[i]<=k){
                c++;
            }
        }
        
        if(c==1){
            return 0;
        }
        
        int nEl=0;
        for(int i=0; i<c; i++){
            if(arr[i]<=k){
                nEl++;
            }
        }
        int ans = nEl;
        
        for(int i=1; i<=n-c; i++){
            if(arr[i-1]<=k){
                nEl--;
            }
            
            if(arr[i+c-1]<=k){
                nEl++;
            }
            
            ans = max(nEl, ans);
        }
        ans = c - ans;
        return ans;
    }
};

int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}