class Solution 
{
private:
    vector<vector<int>> dp;
    
    int uniquePathsUtil(int m,int n,int i,int j)
    {
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        
        if(i<0 || i>=m || j<0 || j>=n)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int down=uniquePathsUtil(m,n,i+1,j);
        int right=uniquePathsUtil(m,n,i,j+1);
        
        // return down+right; //Recursive Solution
        //TC: O(2^(m+n)) //as for every m for very n 2(down,right) Recursion calls
        //SC: O(m*n)auxiliary stack space
        
        return dp[i][j]=down+right; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(m*n) //as for evry m for every n Recursion calls Memoized
        //SC: O(m*n)+O(m*n)auxiliary stack space
    }
public:
    int uniquePaths(int m, int n) 
    {
//         dp.assign(m,vector<int>(n,-1));
        
//         return uniquePathsUtil(m,n,0,0);
        
//         dp.assign(m+1,vector<int>(n+1,0));
//         dp[m-1][n-1]=1;
        
//         for(int i=m-1; i>=0; i--)
//         {
//             for(int j=n-1; j>=0; j--)
//             {
//                 if(i==m-1 && j==n-1)
//                 {
//                     continue;
//                 }
                
//                 int down=dp[i+1][j];
//                 int right=dp[i][j+1];
                
//                 dp[i][j]=down+right;
//             }
//         }
        
//         return dp[0][0]; //Bottom-Up DP approach -> Tabulation
//         //TC: O(m*n)
//         //SC: O(m*n)
        
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        curr[n-1]=1;
        
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(i==m-1 && j==n-1)
                {
                    continue;
                }
                
                int down=next[j];
                int right=curr[j+1];
                
                curr[j]=down+right;
            }
            next=curr;
        }
        
        return curr[0]; //Space Optimzation
        //TC: O(m*n)
        //SC: O(n)
    }
};