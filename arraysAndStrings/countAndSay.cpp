//Count and Say
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        
        string S = countAndSay(n-1);
        string ans="";
        int i=0;
        while(i<S.size()){
            int c=0;
            while(S[i]==S[i+1]){
                c++;
                i++;
            }
            c++;
            ans = ans+to_string(c);
            ans.push_back(S[i]);
            i++;
        }
        
        return ans;
    }
};

int main(){
    int n;
    cin>>n;

    Solution s;
    cout<<s.countAndSay(n);

    return 0;
}