//Check if a number is palindrome or not

#include<bits/stdc++.h>
using namespace std;

void revNumHelper(int n, int *rev){
    //Base Condition
    if(n/10==0){
        *rev = *rev*10 + n;
        return;
    }

    //reverse(n) = n%10 followed by reverse(n/10)
    //reverse(123) = 3 followed by reverse(12) 
    *rev = *rev*10 + n%10;
    revNumHelper(n/10, rev);
}

int revNum(int n){
    //Sometimes you might need additional variables in that case create another function
    //Helper function
    int rev = 0;
    revNumHelper(n, &rev);

    return rev;
}

bool palindrome(int n){
    return (n==revNum(n));
}

int main(){
    int n;
    cin>>n;
    if(palindrome(n)){
        cout<<"Palindrome\n";
    }
    else{
        cout<<"Not Palindrome\n";
    }
    return 0;
}