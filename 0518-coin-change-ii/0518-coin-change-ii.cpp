class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][amount]
    
    int changeUtil(vector<int>& coins,int index,int amount)
    {
        if(amount==0)
        {
            return 1;
        }
        
        if(index>=coins.size())
        {
            return 0;
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
        
        // return exclude+include; //Recursive Solution
        //TC: O(2^n) //as 2 (include,exclude) calls for every index
        //SC: O(n) + O(n)auxiliary space
        
        return umap[index][amount]=exclude+include; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*amount) //as for every index for every amount Recursion calls Result Memoized
        //SC: O(n*amount) + O(n)auxiliary space
    }
public:
    int change(int amount, vector<int>& coins) 
    {
        return changeUtil(coins,0,amount);
    }
};