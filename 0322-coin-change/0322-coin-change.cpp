class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; ///umap[index][amount]
    
    int coinChangeUtil(vector<int>& coins,int index,int amount)
    {
        if(amount==0)
        {
            return 0;
        }
        
        if(index==coins.size()-1)
        {
            if(amount%coins[index]==0)
            {
                return amount/coins[index];
            }
            
            return INT_MAX;
        }
        
        if(umap.count(index) && umap[index].count(amount))
        {
            return umap[index][amount];
        }
        
        int exclude=0+coinChangeUtil(coins,index+1,amount);
        int include=INT_MAX;
        if(amount>=coins[index])
        {
            include=coinChangeUtil(coins,index,amount-coins[index]);
            if(include<INT_MAX)
            {
                include=include+1;
            }
        }
        
        // return min(exclude,include); //Recursive Solution
        //TC: O(2^n) //as 2 (exclude,include) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index][amount]=min(exclude,include); //Top-Down DP approach -> recursion + Memoization
        //TC: O(n*amount) //as for every index for every amount Recursion calls Memoized
        //SC: O(n* amount)
    }
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        sort(coins.begin(),coins.end());
        
        int ans=coinChangeUtil(coins,0,amount);
        return ans<INT_MAX?ans:-1;
    }
};