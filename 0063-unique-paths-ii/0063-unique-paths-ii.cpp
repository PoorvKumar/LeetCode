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
        
        // dp.assign(m+1,vector<int>(n+1,-1));
        
        // return uniquePathsUtil(obstacleGrid,0,0);
        
        if(obstacleGrid[m-1][n-1]!=0)
        {
            return 0;
        }
        
//         vector<vector<long long>> dp;
//         dp.assign(m+1,vector<long long>(n+1,0));
//         dp[m-1][n-1]=1;
        
//         for(int i=m-1; i>=0; i--)
//         {
//             for(int j=n-1; j>=0; j--)
//             {
//                 if(obstacleGrid[i][j]==1)
//                 {
//                     continue;
//                 }
                
//                 long long right=dp[i][j+1];
//                 long long down=dp[i+1][j];
                
//                 long long ans=right+down;
//                 dp[i][j]+=ans;
//             }
//         }
        
//         return dp[0][0]; //Bottom-Up DP approach -> Tabulation
//         //TC: O(m*n)
//         //SC: O(m*n)+O(m*n)
        
        vector<long long> curr(n+1,0);
        vector<long long> prev(n+1,0);
        
        curr[n-1]=1;
        
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(obstacleGrid[i][j]==1)
                {
                    continue;
                }
                
                long long right=curr[j+1];
                long long down=prev[j];
                
                long long ans=right+down;
                curr[j]+=ans;
            }
            prev=curr;
            curr.assign(n+1,0);
        }
        
        return prev[0]; //Space Optimization
        //TC: O(m*n)
        //SC: O(m*n)+O(n)
    }
};