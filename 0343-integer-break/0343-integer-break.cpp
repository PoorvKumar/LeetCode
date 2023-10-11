class Solution 
{
private:
    vector<int> dp;
    
    int integerBreakUtil(int n)
    {
        if(n==1)
        {
            return n;
        }
        
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
        int ans=n;
        for(int i=1; i<n; i++)
        {
            int val=i*integerBreakUtil(n-i);
            ans=max(ans,val);
        }
        
        // return ans; //Recursive Solution
        //TC: O(n*n) //as for every n , n Recursion calls
        //SC: O(n)
        
        return dp[n]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n) //as for every n Recursion calls Memoized
        //SC: O(n)
    }
public:
    int integerBreak(int n) 
    {
        dp.assign(n+1,-1);
        
        int ans=1;
        
        for(int i=1; i<n; i++)
        {
            int val=i*integerBreakUtil(n-i);
            ans=max(ans,val);
        }
        
        return ans;
    }
};