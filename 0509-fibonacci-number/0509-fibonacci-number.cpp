class Solution 
{
private:
    // unordered_map<int,int> umap;
public:
    int fib(int n) 
    {
        if(n<2)
        {
            return n;
        }
        
        // return fib(n-1)+fib(n-2);
        
//         if(!umap.count(n-1))
//         {
//             umap[n-1]=fib(n-1);
//         }
//         if(!umap.count(n-2))
//         {
//             umap[n-2]=fib(n-2);
//         }
        
//         return umap[n]=umap[n-1]+umap[n-2];
        
        vector<int> dp(n+1);
        
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2; i<=n; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};