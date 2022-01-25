#include<bits/stdc++.h>
using namespace std;

//Function to merge two sorted arrays
void merge(int A[], int low, int mid, int high){
    //Create new array
    int B[high-low+1];
    //i->ptr for low to mid
    //j->ptr for mid+1 to high
    //k-> ptr for new array
    int i=low, j=mid+1, k=0;

    while (i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
        }
        else{
            B[k]=A[j];
            j++;
        }
        k++;
    }

    while (i<=mid){
        B[k]=A[i];
        i++;
        k++;
    }

    while (j<=high){
        B[k]=A[j];
        j++;
        k++;
    }
    
    //Copy B in A
    for(int i=low; i<=high; i++){
        A[i] = B[i-low];
    }
}

void mergeSort(int A[], int low, int high){
    if(low>=high)
        return;
    
    int mid = (low+high)/2;
    //Perform merge sort on low to mid
    mergeSort(A, low, mid);
    //Perform merge sort on mid+1 to high
    mergeSort(A, mid+1, high);
    //Merge the two parts
    merge(A, low, mid, high);
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    mergeSort(A, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}