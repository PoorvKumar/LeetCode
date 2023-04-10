class Solution
{
private:
    unordered_map<int,unordered_map<bool,int>> umap; //umap[index][buy]
    
    int maxProfitUtil(vector<int>& prices,int index,bool buy)
    {
        if(index==prices.size()-1) //base case
        {
            if(!buy)
            {
                return prices[index];
            }
            return 0;
        }
        
        if(umap.count(index) && umap[index].count(buy))
        {
            return umap[index][buy];
        }
        
        if(buy)
        {
            int notBuy=0+maxProfitUtil(prices,index+1,buy);
            int Buy=-prices[index]+maxProfitUtil(prices,index+1,!buy);
            
            // return max(notBuy,Buy); //Recursive Solution
            //TC: O(2^n) //as 2 (notBuy|Buy || notSell|Sell) calls for evry index
            //SC: O(n)+O(n)auxiliary stack
            
            return umap[index][buy]=max(notBuy,Buy); //Top-Down DP apporach -> Recursion + Memoization
            //TC: O(n*2) // as for evry index for every buy Recursion calls Memoized
            //SC: O(n*2)+O(n)auxiliary stack space
        }
        
        int notSell=0+maxProfitUtil(prices,index+1,buy);
        int Sell=prices[index]+maxProfitUtil(prices,index+1,!buy);
        
        // return max(notSell,Sell); //Recursive Solution
        //TC: O(2^n) // as 2 (notBuy|Buy || notSell|Sell) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index][buy]=max(notSell,Sell); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*2) //as for every index for every buy Recursion calls Memoized
        //SC: O(n*2)+O(n)auxiliary stack space
    }
public:
    int maxProfit(vector<int>& prices)
    {
        // return maxProfitUtil(prices,0,true);
        
        int n=prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,0));
        //dp[index][buy]
        
        dp[n-1][0]=prices[n-1]; //base case
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=1; j>=0; j--)
            {
                if(j)
                {
                    int notBuy=dp[i+1][j];
                    int Buy=-prices[i]+dp[i+1][j-1];
                    
                    dp[i][j]=max(notBuy,Buy);
                    continue;
                }
                int notSell=dp[i+1][j];
                int Sell=prices[i]+dp[i+1][j+1];
                
                dp[i][j]=max(notSell,Sell);
            }
        }
        
        return dp[0][1]; //Bottom-Up DP approach -> Tabulation
        //TC: O(n*2)
        //SC: O(n*2)
    }
};