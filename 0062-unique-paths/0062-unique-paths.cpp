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
        dp.assign(m,vector<int>(n,-1));
        
        return uniquePathsUtil(m,n,0,0);
    }
};