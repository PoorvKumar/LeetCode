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
            
            return umap[index][buy]=max(notBuy,Buy);
        }
        
        int notSell=0+maxProfitUtil(prices,index+1,buy);
        int Sell=prices[index]+maxProfitUtil(prices,index+1,!buy);
        
        // return max(notSell,Sell); //Recursive Solution
        //TC: O(2^n) // as 2 (notBuy|Buy || notSell|Sell) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index][buy]=max(notSell,Sell);
    }
public:
    int maxProfit(vector<int>& prices)
    {
        return maxProfitUtil(prices,0,true);
    }
};