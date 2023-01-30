class Solution 
{
private:
    unordered_map<int,int> umap;
public:
    int tribonacci(int n) 
    {
        if(n<=0)
        {
            return 0;
        }
        if(n<3)
        {
            return 1;
        }
        
//         if(!umap.count(n-1))
//         {
//             umap[n-1]=tribonacci(n-1);
//         }
//         if(!umap.count(n-2))
//         {
//             umap[n-2]=tribonacci(n-2);
//         }
//         if(!umap.count(n-3))
//         {
//             umap[n-3]=tribonacci(n-3);
//         }
        
//         // return tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1); //Recursive Solution
//         umap[n]=umap[n-3]+umap[n-2]+umap[n-1]; //Top-Down DP approach -> Recursion + Memoization
//         return umap[n];
        
//         vector<int> dp(n+1);
//         dp[0]=0;
//         dp[1]=1;
//         dp[2]=1;
        
//         for(int i=3; i<=n; i++) //Bottom-Up DP approach -> Tabulation
//         {
//             dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
//         }
        
//         return dp[n];
        
        int x=0;
        int y=1;
        int z=1;
        int ans=1;
        
        for(int i=3; i<=n; i++)
        {
            ans=z+y+x;
            x=y;
            y=z;
            z=ans;
        }
        
        return ans;
    }
};