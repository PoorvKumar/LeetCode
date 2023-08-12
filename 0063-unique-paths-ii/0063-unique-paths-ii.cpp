class Solution 
{
private:
    int m;
    int n;
    
    vector<vector<int>> dp;
    
    int uniquePathsUtil(vector<vector<int>>& grid,int i,int j)
    {
        if(i==m-1 && j==n-1)
        {
            return grid[i][j]!=1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(i>=m || j>=n)
        {
            return 0;
        }
        
        if(grid[i][j]==1)
        {
            return 0;
        }
        
        int right=uniquePathsUtil(grid,i,j+1);
        int down=uniquePathsUtil(grid,i+1,j);
        
        int ans=right+down;
        // return ans; //Recursion Solution
        //TC: O(2^(m*n)) //as 2(right,down) Recursion calls for evry i for every j
        //SC: O(m*n)+O(m*n)auxiliary stack space
        
        return dp[i][j]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(m*n) //as for every i for every j Recursion calls Memoized
        //SC: O(m*n)+O(m*n)auxiliary stack space
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        
        dp.assign(m+1,vector<int>(n+1,-1));
        
        return uniquePathsUtil(obstacleGrid,0,0);
    }
};