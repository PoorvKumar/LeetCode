class Solution 
{
private:
    unordered_map<int,int> umap;
public:
    Solution()
    {
        umap.clear();
    }
    
//     int climbStairs(int n) // Top-Down DP -> Recursion + Memoization
//     {                      // could be done with better space complexity
//         if(n<3)
//         {
//             return n; 
//         }
//                                 //Time Complexity -> O(n)        
//         if(umap.count(n)==1)    // Space Complexity -> O(n) + O(n)
//         {
//             return umap[n];
//         }
        
//         umap[n]=climbStairs(n-1)+climbStairs(n-2);    
//         return umap[n];
//     }
    
    int climbStairs(int n) //Bottom-Up DP -> Tabulation
    {
        if(n<3)
        {
            return n;
        }
        
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;                   // Time Complexity -> O(n)
                                   // Space Complexity -> O(n)        
        for(int i=3; i<=n; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};