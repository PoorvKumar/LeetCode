class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int minim=prices[0];
        int maxim=prices[0];
        
        int profit=0;
        
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i-1]<minim)
            {
                minim=prices[i-1];
                maxim=prices[i-1];
            }
            
            maxim=prices[i]>maxim?prices[i]:maxim;
            profit=max(profit,maxim-minim);
        }
        
        return profit;
    }
};