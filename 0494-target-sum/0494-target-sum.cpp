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
        
        return targetSumUtil(nums,0,0,target);
        
        int n=nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
        for(int i=0; i<=sum; i++) //base case
        {
            if(2*i-sum==target)
            {
                dp[n][i]=1;
            }
            else
            {
                dp[n][i]=0;
            }
        }
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<=sum; j++)
            {
                int exclude=dp[i+1][j];
                int include=dp[i+1][j+nums[i]];
                
                dp[i][j]=exclude+include;
            }
        }
        
        return dp[0][0]; //dp[index][plus]
    }
};