// Write a program to reverse an array or string
// Time Complexity - O(n)
// Space Complexity - o(1)

#include<bits/stdc++.h>
using namespace std;

// Function to reverse a string
string reverseWord(string str);


int main() {
	
	int t; // testcases
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

string reverseWord(string str){

  int left=0, right=str.size()-1;
  string revStr = str;
  char temp;
  
//   Two pointer
  while(left<right){
      temp = revStr[left];
      revStr[left] = revStr[right];
      revStr[right] = temp;
      left++;
      right--;
  }
  return revStr;
}