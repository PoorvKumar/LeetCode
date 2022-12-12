class Solution 
{
private:
    unordered_map<int,int> umap;
public:
    int tribonacci(int n) 
    {
        //Recursion && Top-Down DP approach -> Recursion + Memoization
        // if(n<3)
        // {
        //     return n==0?0:1;
        // }
        
//         if(umap.count(n))
//         {
//             return umap[n];
//         }
        
//         // return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3); //Recursive Solution
        
//         return umap[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3); //Top-Down DP approach -> Recursion + Memoization
        
        //Bottom-Up DP approach -> Tabulation
        if(n<3)
        {
            return n==0?0:1;
        }
        
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        
        for(int i=3; i<=n; i++)
        {
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        
        return dp[n];
    }
};