class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int climbStairsUtil(int n)
    {      
        if(n<=2)
        {
            return n;
        }
        
        if(umap.count(n))
        {
            return umap[n];
        }
        
        int oneStep=climbStairsUtil(n-1);
        int twoStep=climbStairsUtil(n-2);
        
        // return oneStep+twoStep;
        
        return umap[n]=oneStep+twoStep;
    }
public:
    int climbStairs(int n) 
    {
        // return climbStairsUtil(n);
        
        if(n<=2)
        {
            return n;
        }
        
        vector<int> dp(n+1,0);
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3; i<=n; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};