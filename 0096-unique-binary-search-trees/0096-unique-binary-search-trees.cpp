class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int numTreesUtil(int n)
    {
        if(n==0 || n==1 || n==2)
        {
            return n;
        }
        
        if(umap.count(n))
        {
            return umap[n];
        }
        
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            int LST=numTreesUtil(i-1);
            int RST=numTreesUtil(n-i);
            
            if(LST==0 || RST==0)
            {
                if(LST==0)
                {
                    ans=ans+RST;
                }
                else
                {
                    ans=ans+LST;
                }
                continue;
            }
            
            ans=ans+LST*RST;
        }
        
        // return ans; //Recursive Solution
        //TC: O(2^n) //as 2 (LST,RST) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[n]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n) //as for every index Recursion calls Memoized
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int numTrees(int n) 
    {
        return numTreesUtil(n);
        
        if(n<3) //base case
        {
            return n;
        }
        
        vector<int> dp(n+1,0);
        dp[0]=0; //base case
        dp[1]=1; //base case
        dp[2]=3; //base case
        
        for(int i=1; i<=n; i++)
        {
            int LST=dp[i-1];
            int RST=dp[n-i];
            
            if(LST==0 || RST==0)
            {
                if(LST==0)
                {
                    dp[i]=dp[i]+RST;
                }
                else
                {
                    dp[i]=dp[i]+LST;
                }
                continue;
            }
            
            dp[i]=dp[i]+LST*RST;
        }
        
        return dp[n];
    }
};