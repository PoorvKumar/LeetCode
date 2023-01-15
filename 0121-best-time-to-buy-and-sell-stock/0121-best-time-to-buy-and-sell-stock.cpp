class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int start=prices[0];
        int end=prices[0];
        
        int maxProfit=0;
        
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i]>end)
            {
                end=prices[i];
            }
            if(prices[i]<start)
            {
                start=prices[i];
                end=prices[i];
            }
            
            maxProfit=max(maxProfit,end-start);
        }
        
        return maxProfit;
    }
};