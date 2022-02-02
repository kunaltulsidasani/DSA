// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


int binarySearch(int arr[], int l, int r, int num){
    int mid;
    
    while(l<=r){
        mid=(l+r)/2;
        
        if(arr[mid]==num){
            return mid;
        }
        else if(arr[mid]<num){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}

bool findPair(int arr[], int size, int n){
    sort(arr, arr+size);
    for(int i=0; i<size; i++){
        if(binarySearch(arr, i+1, size-1, arr[i]+n)!=-1){
            return true;
        }
    }
    return false;
}