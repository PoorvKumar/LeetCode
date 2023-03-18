class Solution 
{
private:
    int sum=0;
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][plus]
    
    int targetSumUtil(vector<int>& nums,int index,int plus,int target)
    {
        if(index==nums.size())
        {
            return 2*plus-sum==target; //plus+minus==sum && plus-minus==target must be true plus is a subset of nums
        }
        
        if(umap.count(index) && umap[index].count(plus))
        {
            return umap[index][plus];
        }
        
        int exclude=targetSumUtil(nums,index+1,plus,target);
        int include=targetSumUtil(nums,index+1,plus+nums[index],target);
        
        // return exclude+include; //Recursive Solution
        //TC: O(2^n) //as 2 (include,exclude) calls at each index
        //SC: O(n) + O(n)auxiliary space
        
        return umap[index][plus]=exclude+include; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*sum) //as for every index for every subset sum plus Recursion calls result Memoized
        //SC: O(n*sum)
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        sum=accumulate(nums.begin(),nums.end(),0);
        
        // return targetSumUtil(nums,0,0,target);
        
        int n=nums.size();
        
//         vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
//         for(int i=0; i<=sum; i++) //base case
//         {
//             // if(2*i-sum==target)
//             // {
//             //     dp[n][i]=1;
//             // }
//             // else
//             // {
//             //     dp[n][i]=0;
//             // }
//             dp[n][i]=2*i-sum==target;
//         }
        
//         for(int i=n-1; i>=0; i--) //index
//         {
//             for(int j=sum; j>=0; j--) //plus
//             {
//                 int exclude=dp[i+1][j];
//                 int include=0;
//                 if(j+nums[i]<=sum)
//                 {
//                     include=dp[i+1][j+nums[i]]; //differnet from subset sum as target not reducing plus increasing
//                 }
                
//                 dp[i][j]=exclude+include;
//             }
//         }
        
//         return dp[0][0]; //dp[index][plus] //Bottom-Up DP approach -> Tabulation
//         //TC: O(n*sum)
//         //SC: O(n*sum)
        
        vector<int> curr(sum+1,0);
        vector<int> prev(sum+1,0);
        
        for(int i=0; i<=sum; i++)
        {
            prev[i]=2*i-sum==target;
        }
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=sum; j>=0; j--)
            {
                int exclude=prev[j];
                int include=0;
                if(j+nums[i]<=sum)
                {
                    include=prev[j+nums[i]];
                }
                
                curr[j]=exclude+include;
            }
            prev=curr;
        }
        
        return prev[0]; //Space Optimisation
        //TC: O(n*sum)
        //SC: O(sum)
        
//         vector<int> dp(sum+1,0);
        
//         for(int i=0; i<=sum; i++)
//         {
//             dp[i]=2*i-sum==target;
//         }
        
//         for(int i=n-1; i>=0; i--)
//         {
//             for(int j=sum; j>=0; j--)
//             {
//                 int exclude=dp[j];
//                 int include=0;
//                 if(j+nums[i]<=sum)
//                 {
//                     include=dp[j+nums[i]];
//                 }
                
//                 dp[j]=exclude+include;
//             }
//         }
        
//         return dp[0]; //Space Optimisation -> 1 array space optimisation
//         //TC: O(n*sum)
//         //SC: O(sum)
    }
};