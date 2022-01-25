#include<bits/stdc++.h>
using namespace std;

int partitioning(int A[], int low, int high){
    int pivot = A[low];
    int i=low+1, j=high;
    while(i<j){
        while(A[i]<pivot && i<=high) i++;
        while(A[j]>pivot && j>=low) j--;

        if(i<j)
            swap(A[i], A[j]);
    }
    swap(A[j], A[low]);
    return j;
}

void quickSort(int A[], int low, int high){
    if(low>=high)
        return;
    
    int pivot_index = partitioning(A, low, high);
    quickSort(A, low, pivot_index-1);
    quickSort(A, pivot_index+1, high);
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    quickSort(A, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}