class Solution 
{
private:
    unordered_map<int,double> umap; //umap[score]
    
    double new21GameUtil(int score,int k,int n,int maxPts)
    {
        if(score>=k)
        {
            return score<=n;
        }
        
        if(umap.count(score))
        {
            return umap[score];
        }
        
        double prob=0;
        for(int i=1; i<=maxPts; i++)
        {
            prob=prob+new21GameUtil(score+i,k,n,maxPts);
        }
        
        // return (double)(prob/(maxPts*1.0)); //Recursive Solution
        //TC: O(maxPts^maxPts) //as for every score maxPts Recursion calls
        //SC: O(maxPts)auxiliary stack space
        
        return umap[score]=(double)(prob/(maxPts*1.0)); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(maxPts*maxPts) //as for every score Recursion calls Memoized
        //SC: O(maxPts)+O(maxPts)auxliary stack space
    }
public:
    double new21Game(int n, int k, int maxPts) 
    {
        // return new21GameUtil(0,k,n,maxPts);
        
        int maxScore=max(n,maxPts);
        
        vector<double> dp(maxPts+n+1,0);
        //dp[score]
        
        //score>=k is base case
        for(int i=k; i<=maxPts+n; i++)
        {
            dp[i]=i<=n;
        }
        
        vector<double> vec(maxPts+n+1,0); //sliding window
        vec[maxPts+n]=dp[maxPts+n];
        
        for(int i=maxPts+n-1; i>=k; i--)
        {
            vec[i]=dp[i]+vec[i+1];
        }
        
        for(int i=k-1; i>=0; i--)
        {
            // double prob=0;
            // for(int j=1; j<=maxPts; j++)
            // {
            //     prob=prob+dp[i+j]; 
            // }
            
            double val=vec[i+1]-vec[i+1+maxPts];
            
            dp[i]=(double)(val/(maxPts*1.0));
            vec[i]=dp[i]+vec[i+1];
        }
        
        return dp[0]; //Bottom-Up DP approach -> Tabulation
        //TC: O(n*maxPts)
        //SC: O(n*maxPts)
    }
};