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
        
        // return changeUtil(coins,0,amount);
        
        int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,0)); //dp[index][amount]
        
//         for(int i=0; i<n; i++) //base case
//         {
//             dp[i][0]=1;
//         }
        
//         for(int i=1; i<=amount; i++) //base case
//         {
//             dp[n-1][i]=i%coins[n-1]==0;
//         }
        
//         for(int i=n-2; i>=0; i--)
//         {
//             for(int j=0; j<=amount; j++)
//             {
//                 int exclude=dp[i+1][j];
//                 int include=0;
//                 if(j>=coins[i])
//                 {
//                     include=dp[i][j-coins[i]];
//                 }
                
//                 dp[i][j]=exclude+include;
//             }
//         }
        
//         return dp[0][amount]; //Bottom-Up DP approach -> Tabulation
//         //TC: O(n*amount)
//         //SC: O(n*amount)
        
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        
        prev[0]=1; //base case
        curr[0]=1; //base case
        
        for(int i=1; i<=amount; i++) //base case
        {
            prev[i]=i%coins[n-1]==0;
        }
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=1; j<=amount; j++)
            {
                int exclude=prev[j];
                int include=0;
                if(j>=coins[i])
                {
                    include=curr[j-coins[i]];
                }
                
                curr[j]=exclude+include;
            }
            prev=curr;
        }
        
        return prev[amount]; //Space Optimisation
        //TC: O(n*amount)
        //SC: O(n)
    }
};