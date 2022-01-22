// Rat in a Maze Problem - I
// Time Complexity: O((3N^2)).
// Space: O(L * X), L = length of the path, X = number of paths

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string sol = "";
        vector<string> solArr;
        vector<int> visited;
        
        findPathHelper(m, n, 0, 0, sol, solArr, visited);
        return solArr;
    }
    
    void findPathHelper(vector<vector<int>> &m, int n, int row, int col, string &sol, vector<string> &solArr, vector<int> &visited){
        //Check boundaries
        if(row>=n || col>=n || row<0 || col<0){
            return;
        }
        
        //Return if blocked
        if(m[row][col] == 0){
            return;
        }
        
        //If already visited return
        if(find(visited.begin(), visited.end(), row*n+col)!=visited.end()){
            return;
        }
        
        //If reached end add to solution
        if(row==n-1 && col==n-1){
            solArr.push_back(sol);
            return;
        }
        
        //Add visited to array
        visited.push_back(row*n+col);
        
        //Go down
        sol.push_back('D');
        //Recursion Call
        findPathHelper(m, n, row+1, col, sol, solArr, visited);
        //Backtrack
        sol.pop_back();
        
        //Go Right
        sol.push_back('R');
        findPathHelper(m, n, row, col+1, sol, solArr, visited);
        sol.pop_back();
        
        //Go Up
        sol.push_back('U');
        findPathHelper(m, n, row-1, col, sol, solArr, visited);
        sol.pop_back();
        
        //Go Left
        sol.push_back('L');
        findPathHelper(m, n, row, col-1, sol, solArr, visited);
        sol.pop_back();
        
        //Remove visited
        visited.pop_back();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} 