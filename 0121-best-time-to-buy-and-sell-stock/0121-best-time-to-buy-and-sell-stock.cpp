class Solution 
{
public:
    //Those who cannot Remember the Past are Condemned to Repeat it
    //                                                         ~ DP
    
    int maxProfit(vector<int>& prices)
    {
        int minim=prices[0];
        int maxProfit=0;
        
        for(int i=1; i<prices.size(); i++)
        {
            int cost=prices[i]-minim;
            maxProfit=max(maxProfit,cost);
            minim=min(minim,prices[i]);
        }
        
        return maxProfit;
        //TC: O(n)
        //SC: O(1)
    }
    
    //this is a DP Problem as remebering the Past minimum price
    
//     int maxProfit(vector<int>& prices) 
//     {
//         int start=0;
//         int end=0;
//         int maxProfit=0;
        
//         start=end=prices[0];
        
//         for(int i=1; i<prices.size(); i++)
//         {
//             if(prices[i]<=end)
//             {
//                 // start=prices[i];
//                 start=min(start,prices[i]);
//                 end=prices[i];
//             }
//             else
//             {
//                 // end=prices[i];
//                 end=max(end,prices[i]);
//             }
            
//             maxProfit=max(maxProfit,end-start);
//         }
        
//         return maxProfit;
//     }
};