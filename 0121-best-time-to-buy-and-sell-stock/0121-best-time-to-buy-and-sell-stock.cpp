class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int start=0;
        int end=0;
        int maxProfit=0;
        
        start=end=prices[0];
        
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]<=end)
            {
                // start=prices[i];
                start=min(start,prices[i]);
                end=prices[i];
            }
            else
            {
                // end=prices[i];
                end=max(end,prices[i]);
            }
            
            maxProfit=max(maxProfit,end-start);
        }
        
        return maxProfit;
    }
};