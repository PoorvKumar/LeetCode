class Solution 
{
private:
    int m;
    int n;
    
    unordered_map<int,unordered_map<int,int>> umap;
    
    int uniquePathsUtil(vector<vector<int>>& grid,int i,int j)
    {
        if(grid[i][j]==1) //base case
        {
            return 0; //obstacle
        }
        
        if(i==m-1 || j==n-1)
        {
            if(i==m-1)
            {
                for(int k=j; k<n; k++)
                {
                    if(grid[i][k]==1)
                    {
                        return 0;
                    }
                }
            }
            
            for(int k=i; k<m; k++)
            {
                if(grid[k][j]==1)
                {
                    return 0;
                }
            }
            
            return 1;
        }
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        int down=uniquePathsUtil(grid,i+1,j);
        int right=uniquePathsUtil(grid,i,j+1);
        
        // return down+right; //Recursive Solution
        //TC: O(2^(m*n)) //as 2 calls (down , right) afor each cell , m*n cells
        //SC: O(m*n) + O(m*n)auxiliary space
        
        return umap[i][j]=down+right; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(m*n) //as 2 calls (down , right) for each cell and answer for each cell stored , m*n cells
        //SC: O(m*n)
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        
        // return uniquePathsUtil(obstacleGrid,0,0);
        
        vector<vector<long long int>> dp(m,vector<long long int>(n,0));
        
        bool flag=true;
        
        for(int i=n-1; i>=0; i--) //base case
        {
            if(obstacleGrid[m-1][i]==1)
            {
                flag=false;
            }
            
            dp[m-1][i]=flag; //1 0
        }
        
        flag=true;
        
        for(int i=m-1; i>=0; i--) //base case
        {
            if(obstacleGrid[i][n-1]==1)
            {
                flag=false;
            }
            
            dp[i][n-1]=flag; //1 0
        }
        
        // for(auto x:dp)
        // {
        //     for(auto y:x)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=m-2; i>=0; i--)
        {
            for(int j=n-2; j>=0; j--)
            {
                // if(obstacleGrid[i][j]==1)
                // {
                //     dp[i][j]=0;
                // }
                // else
                // {
                //     dp[i][j]=dp[i+1][j] + dp[i][j+1]; //dp[i][j]=down+right;
                // }
                
                dp[i][j]=obstacleGrid[i][j]==1?0:dp[i+1][j]+dp[i][j+1]; //dp[i][j]=down+right;
            }
        }
        
        return dp[0][0]; //Bottom-Up DP approach -> Tabulation
        //TC: O(m*n)
        //SC: O(m*n) + O(m*n)auxiliary space
    }
};