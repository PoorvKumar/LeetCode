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
        
        return umap[index][amount]=min(exclude,include); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*amount) //as for every index for every amount Recursion calls Memoized
        //SC: O(n* amount)
    }
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        sort(coins.begin(),coins.end());
        
        // int ans=coinChangeUtil(coins,0,amount);
        // return ans<INT_MAX?ans:-1;
        
        int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,INT_MAX)); //dp[index][amount]
        
//         for(int i=0; i<n; i++) //base case
//         {
//             dp[i][0]=0;
//         }
        
//         for(int i=0; i<=amount; i++) //base case
//         {
//             if(i%coins[n-1]==0)
//             {
//                 dp[n-1][i]=i/coins[n-1];
//             }
//         }
        
//         for(int i=n-2; i>=0; i--)
//         {
//             for(int j=1; j<=amount; j++)
//             {
//                 int exclude=0+dp[i+1][j];
//                 int include=INT_MAX;
//                 if(j>=coins[i])
//                 {
//                     include=dp[i][j-coins[i]];
//                     if(include<INT_MAX)
//                     {
//                         include=include+1;
//                     }
//                 }
                
//                 dp[i][j]=min(exclude,include);
//             }
//         }
        
//         int ans=dp[0][amount];
//         return ans<INT_MAX?ans:-1; //Bottom-UP DP approach -> Tabulation
//         //TC: O(n*amount)
//         //SC: O(n*amount)
        
        vector<int> prev(amount+1,INT_MAX);
        vector<int> curr(amount+1,INT_MAX);
        
        curr[0]=0; //base case
        prev[0]=0; //base case
        
        for(int i=1; i<amount+1; i++) //base case
        {
            if(i%coins[n-1]==0)
            {
                prev[i]=i/coins[n-1];
            }
        }
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=1; j<=amount; j++)
            {
                int exclude=0+prev[j];
                int include=INT_MAX;
                if(j>=coins[i])
                {
                    include=curr[j-coins[i]];
                    if(include<INT_MAX)
                    {
                        include=include+1;
                    }
                }
                curr[j]=min(exclude,include);
            }
            prev=curr;
        }
        
        int ans=prev[amount];
        return ans<INT_MAX?ans:-1; //Space Optimisation
    }
};