//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
private:
    unordered_map<int,unordered_set<int>> rows;
    unordered_map<int,unordered_set<int>> col;
    unordered_map<int,unordered_set<int>> grids;
    
    vector<vector<int>> vec;
    
    bool solveSudokuUtil(int grid[N][N],int i,int j)
    {
        if(i==N)
        {
            return true;
        }
        
        if(grid[i][j]!=0)
        {
            if(j==N-1)
            {
                return solveSudokuUtil(grid,i+1,0);
            }
            
            return solveSudokuUtil(grid,i,j+1);
        }
        
        for(int k=1; k<=9; k++)
        {
            if(!rows[i].count(k) && !col[j].count(k) && !grids[vec[i][j]].count(k))
            {
                rows[i].insert(k);
                col[j].insert(k);
                grids[vec[i][j]].insert(k);
                
                grid[i][j]=k;
                
                bool ans=false;
                if(j==N-1)
                {
                    ans=solveSudokuUtil(grid,i+1,0);
                }
                else
                {
                    ans=solveSudokuUtil(grid,i,j+1);
                }
                
                if(ans)
                {
                    return true;
                }
                
                grid[i][j]=0;
                rows[i].erase(k);
                col[j].erase(k);
                grids[vec[i][j]].erase(k);
            }
        }
        
        return false;
    }
public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    {
        vec={{0,0,0,1,1,1,2,2,2},
            {0,0,0,1,1,1,2,2,2},
            {0,0,0,1,1,1,2,2,2},
            {3,3,3,4,4,4,5,5,5},
            {3,3,3,4,4,4,5,5,5},
            {3,3,3,4,4,4,5,5,5},
            {6,6,6,7,7,7,8,8,8},
            {6,6,6,7,7,7,8,8,8},
            {6,6,6,7,7,7,8,8,8},
        };
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                rows[i].insert(grid[i][j]);
                col[j].insert(grid[i][j]);
                grids[vec[i][j]].insert(grid[i][j]);
            }
        }
        
        return solveSudokuUtil(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
        
        return ;
    }
};

//{ Driver Code Starts.

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
// } Driver Code Ends