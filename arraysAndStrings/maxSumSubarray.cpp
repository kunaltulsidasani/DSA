// Find the largest sum of contiguous subArray
// Time Complexity - O(N)
// Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        // Current Sum of subarray
        long long currSum = arr[0];
        //Max sum of subarrays
        long long maxSum = arr[0];
        for(int i=1; i<n; i++){
            // if arr[i] is greater than previous subarray including arr[i] than start a new subarray from arr[i]
            currSum = max(currSum+arr[i], (long long)arr[i]);
            // max currSum
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}