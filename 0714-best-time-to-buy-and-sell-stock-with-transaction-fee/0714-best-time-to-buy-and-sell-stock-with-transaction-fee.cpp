class Solution 
{
private:
    // unordered_map<int,unordered_map<bool,int>> umap; //umap[index][buy]
    vector<vector<int>> dp; //dp[index][buy]
    
    int maxProfitUtil(vector<int>& prices,int index,bool buy,int fee)
    {
        if(index>=prices.size())
        {
            return buy?0:-1e4;
        }
        
        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }
        
        // if(umap.count(index) && umap[index].count(buy))
        // {
        //     return umap[index][buy];
        // }
        
        if(buy)
        {
            int notBuy=maxProfitUtil(prices,index+1,buy,fee);
            int Buy=-prices[index]+maxProfitUtil(prices,index+1,!buy,fee);
            
            // return max(notBuy,Buy); //Recursive Solution
            //TC: O(2^n) //as 2(notBuy,buy || notSell,sell) Recursion calls for every index
            //SC: O(n)+O(n)auxiliary stack space
            
            return dp[index][buy]=max(notBuy,Buy);
            // return umap[index][buy]=max(notBuy,Buy); //Top-Down DP approach -> Recursion + Memoization
            //TC: O(n*2) //as for every index for every buy Recursion calls Memoized
            //SC: O(n*2)+O(n)auxiliary stack space
        }
        
        int notSell=maxProfitUtil(prices,index+1,buy,fee);
        int sell=prices[index]-fee+maxProfitUtil(prices,index+1,!buy,fee);
        
        // return max(notSell,sell); //Recursive Solution
        //TC: O(2^n) //as 2(notBuy,buy || notSell,sell) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return dp[index][buy]=max(notSell,sell);
        // return umap[index][buy]=max(notSell,sell); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*2) //as for every index for every buy Recursion calls Memoized
        //SC: O(n*2)+O(n)auxiliary stack space
    }
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        dp.assign(prices.size()+1,vector<int>(2,-1));
        // return maxProfitUtil(prices,0,true,fee);
        
        int n=prices.size();
        dp[n][1]=0;
        dp[n][0]=-1e4;
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=1; j>=0; j--)
            {
                if(j==1)
                {
                    int notBuy=dp[i+1][1];
                    int Buy=-prices[i]+dp[i+1][0];
                    
                    dp[i][j]=max(notBuy,Buy);
                }
                else
                {
                    int notSell=dp[i+1][j];
                    int sell=prices[i]-fee+dp[i+1][1];
                    
                    dp[i][j]=max(notSell,sell);
                }
            }
        }
        
        return dp[0][1]; //Bottom-Up DP approach -> Tabulation
        //TC: O(n*2)
        //SC: O(n*2)
    }
};