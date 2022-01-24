#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // If there are no empty places in sudoku return true
        int flag = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j]==0){
                    flag = 1;
                }
            }
        }
        if(flag == 0){
            return true;
        }
        
        
        for(int r=0; r<N; r++){
            for(int c=0; c<N; c++){
                //If position is empty
                if(grid[r][c]==0){
                    for(int i=1; i<=N; i++){
                        if(check(grid, r, c, i)==true){
                            grid[r][c] = i;
                            //Recursion call
                            if(SolveSudoku(grid)==true){
                                return true;
                            }
                            //backtrack
                            grid[r][c]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool check(int grid[N][N], int r, int c, int num){
        //Check row
        for(int i=0; i<N; i++){
            if(grid[r][i]==num){
                return false;
            }
        }
        
        //check col
        for(int i=0; i<N; i++){
            if(grid[i][c]==num){
                return false;
            }
        }
        
        //check box
        for(int i=(r/3)*3; i<(r/3)*3+3; i++){
            for(int j=(c/3)*3; j<(c/3)*3+3; j++){
                if(grid[i][j]==num){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
} 