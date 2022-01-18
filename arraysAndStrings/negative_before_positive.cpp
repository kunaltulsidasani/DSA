// Move all negative numbers to beginning and positive to end with constant extra space
// Time Complexity - O(n)
// Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

void negBeforePos(int arr[], int n){
    int l = 0, r = n-1;
    while (l<r){
        //condition if left is positive and right is negative
        //we swap left and right and move both pointers ahead
        if(arr[l]>=0 && arr[r]<0){
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        // condition if left is negative and right is positive
        // They are at correct pos and need not be changed
        // We move two pointers ahead
        else if(arr[l]<0 && arr[r]>0){
            l++;
            r--;
        }
        // left and right are positive
        // right is at correct therefore move right pointer ahead
        else if(arr[l]>=0 && arr[r]>=0){
            r--;
        }
        // left and right are negative
        // left is at correct therefore move left pointer ahead
        else{
            l++;
        }
    }
}

int main(){
    int t; //testcases
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;
        
        int arr[n];
        // Take Input
        for(int i=0; i<n; i++) cin>>arr[i];

        negBeforePos(arr, n);

        for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
    
}