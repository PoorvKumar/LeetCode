class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int coinChangeUtil(vector<int>& coins,int amount)
    {
        if(amount<0)
        {
            return INT_MAX;
        }
        
        if(amount==0)
        {
            // umap[amount]=0;
            return 0;
        }
        
        int res=INT_MAX;
        int x;
        
        for(int i=0; i<coins.size(); i++)
        {
            if(umap.count(amount-coins[i])==1)
            {
                x=umap[amount-coins[i]];
            }
            else
            {
                x=coinChangeUtil(coins,amount-coins[i]);
            }
            // x=coinChangeUtil(coins,amount-coins[i]);
            // res=min(res,x);
            if(x<res)
            {
                res=1+x;
            }
        }
        
        umap[amount]=res;
        return res;
    }
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int res=coinChangeUtil(coins,amount); //Top-Down DP approach -> Recursion + Memoization
        return res!=INT_MAX?res:-1;
    }
};