class Solution 
{
private:
    unordered_map<int,int> umap;
    vector<int> dp;
    
    int maximizeProfitUtil(vector<vector<int>>& offers,int index)
    {
        if(index>=offers.size())
        {
            return 0;
        }
        
        // if(umap.count(index))
        // {
        //     return umap[index];
        // }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        int notSell=maximizeProfitUtil(offers,index+1);
        int sell=offers[index][2];
        
        // int i=index+1;
        // while(i<offers.size() && offers[i][0]<=offers[index][1]) 
        // {
        //     i++; //can be reduced to logn time complexity using binary search
        // }
        
        vector<int> vec={offers[index][1]+1,0,0};
        
        int i=lower_bound(offers.begin(),offers.end(),vec)-begin(offers);
        
        sell=sell+maximizeProfitUtil(offers,i);
        
        // return max(notSell,sell); //Recursive Solution
        //TC: O(2^n) //as for every ith offer 2(notSell,sell) Recursion calls
        //SC: O(n)+O(n)auxiliary stack space
        
        // return umap[index]=max(notSell,sell); //Top-Down DP approach -> Recursion + Memoization
        return dp[index]=max(notSell,sell); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*n) //as for every ith offer Recursion call Memoized
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) 
    {
        sort(begin(offers),offers.end());
        
        dp.assign(offers.size(),-1);
        
        return maximizeProfitUtil(offers,0);
        
//         int N=offers.size();
        
//         dp.assign(N+1,0);
        
//         for(int i=N-1; i>=0; i--)
//         {
//             int notSell=dp[i+1];
//             int sell=offers[i][2];
            
//             int k=i+1;
//             while(k<N && offers[k][0]<=offers[i][1])
//             {
//                 k++;
//             }
            
//             sell=sell+dp[k];
            
//             dp[i]=max(notSell,sell);
//         }
        
//         return dp[0];
    }
};