#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
    {
        vector<int> ans;
        int dir=0;
        //x-> row, y-> coloumn
        int x=0, y=0;
        //rows -> ending index of rows
        //cols -> ending index of cols
        int rows=r-1, cols=c-1;
        //rows_b -> begining index of rows
        //cols_b -> begining index of cols
        int rows_b=0, cols_b=0;
    
        //dir is direction
        //dir=0 -> right moving
        //dir=1 -> down moving
        //dir=2 -> left moving
        //dir=3 -> up moving
        
        for(int i=0; i<r*c; i++){
            ans.push_back(matrix[x][y]);
            if(dir==0){
                if(y==cols){
                    dir++;
                    rows_b++;
                    x++;
                }
                else{
                    y++;
                }
            }
            else if(dir==1){
                if(x==rows){
                    dir++;
                    cols--;
                    y--;
                }
                else{
                    x++;
                }
            }
            else if(dir==2){
                if(y==cols_b){
                    dir++;
                    rows--;
                    x--;
                }
                else{
                    y--;
                }
            }
            else if(dir==3){
                if(x==rows_b){
                    dir=0;
                    cols_b++;
                    y++;
                }
                else{
                    x--;
                }
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}