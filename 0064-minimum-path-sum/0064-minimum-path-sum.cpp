class Solution 
{
private:
    int m;
    int n;
    unordered_map<int,unordered_map<int,int>> umap;
    
    int minPathSumUtil(vector<vector<int>>& grid,int i,int j)
    {
        if(i==m-1 && j==n-1) //base case
        {
            return grid[i][j];
        }
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        if(i==m-1 || j==n-1)
        {
            if(i==m-1)
            {
                return grid[i][j]+minPathSumUtil(grid,i,j+1);
            }
            return grid[i][j]+minPathSumUtil(grid,i+1,j);
        }
        
        int down=grid[i][j]+minPathSumUtil(grid,i+1,j);
        int right=grid[i][j]+minPathSumUtil(grid,i,j+1);
        
        // return min(down,right); //Recursive Solution
        //TC: O(2^n) //as 2 (down,right) calls for every cell
        //SC: O(m*n) + O(m*n)auxiliary space
        
        return umap[i][j]=min(down,right); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(m*n) //as for every cell Recursion calls Memoized
        //SC: O(m*n) + O(m*n)auxiliary stack space
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        
        return minPathSumUtil(grid,0,0);
    }
};