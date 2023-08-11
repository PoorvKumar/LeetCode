class Solution 
{
private:
    vector<vector<int>> dp;
    
    int changeUtil(vector<int>& coins,int index,int amount)
    {
        if(amount<=0)
        {
            return amount==0;
        }
        
        if(index>=coins.size())
        {
            return amount==0;
        }
        
        if(dp[index][amount]!=-1)
        {
            return dp[index][amount];
        }
        
        //exclude
        int exclude=changeUtil(coins,index+1,amount);
        
        //include
        // int include=0;
        // if(amount-coins[index]>=0)
        // {
        //     include=changeUtil(coins,index,amount-coins[index]);
        // }
        int include=changeUtil(coins,index,amount-coins[index]);
        
        int ans=exclude+include;
        // return ans; //Recursive Solution
        //TC: O(2^n*amount)
        //SC: O(n)+O(n*amount)auxiliary stack space
        
        return dp[index][amount]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*amount) //as for every index for every amount Recursion calls Memoized
        //SC: O(n*amount)+O(n*amount)auxiliary stack space
    }
public:
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        
        return changeUtil(coins,0,amount);
    }
};