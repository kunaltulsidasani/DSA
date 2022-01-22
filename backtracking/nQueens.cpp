// N queens Problems
// Time Complexity - O(N!)
// Space Complexity - O(N^2)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        vector<int> sol;
        // Arr with all solutions
        vector<vector<int>> solArr;
        
        nQueenHelper(n, sol, solArr);
        return solArr;
    }
    
    void nQueenHelper(int n, vector<int> &sol, vector<vector<int>> &solArr){
        //if sol is of size n
        if(sol.size() == n){
            //Add into solution arr
            solArr.push_back(sol);
            return;
        }
        
        for(int i=1; i<=n; i++){
            //check if number should be inserted or not
            if(check(sol, i)==false){
                continue;
            }
            //Insert i in solution
            sol.push_back(i);
            //Recusrion Call
            nQueenHelper(n, sol, solArr);
            //Backtrack
            sol.pop_back();
        }
    }
    
    // Check function to see if a the row is correct for insertion or not
    bool check(vector<int> sol, int num){
        //If sol is empty any queen position is correct
        if(sol.size()==0){
            return true;
        }
        
        //If a queen is already in same row then return false
        if(find(sol.begin(), sol.end(), num)!=sol.end()){
            return false;
        }
        
        //for diagonal check if any present in diagonal return false
        for(int i=0; i<sol.size(); i++){
            if(abs(sol[i]-num)==(sol.size()-i)){
                return false;
            }
        }
        
        //else return true
        return true;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}