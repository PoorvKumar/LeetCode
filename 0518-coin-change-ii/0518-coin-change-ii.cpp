class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][amount]
    
    int changeUtil(vector<int>& coins,int index,int amount)
    {
        if(amount==0) //base case
        {
            return 1;
        }
        
        if(index==coins.size()-1) //base case
        {
            return amount%coins[index]==0;
        }
        
        if(umap.count(index) && umap[index].count(amount))
        {
            return umap[index][amount];
        }
        
        int exclude=changeUtil(coins,index+1,amount);
        int include=0;
        if(amount>=coins[index])
        {
            include=changeUtil(coins,index,amount-coins[index]);
        }
        
        int ans=exclude+include;
        // return ans; //Recursive Solution
        //TC: O(2^n) //as 2 (exclude,include) calls for evry index
        //SC: O(n)+O(n)auxiliary stack space
        
        // umap[index][amount]=ans;
        return umap[index][amount]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*amount) //as for every index for every amount Recursion calls Memoized
        //SC: O(n*amount)+O(n)auxiliary stack space
    }
public:
    int change(int amount, vector<int>& coins) 
    {
        sort(coins.begin(),coins.end());
        
        return changeUtil(coins,0,amount);
    }
};