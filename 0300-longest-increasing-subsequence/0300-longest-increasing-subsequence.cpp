class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),1);
        
        int ans=1;
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i])
                {
                    // maxim=max(maxim,dp[j]);
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        
        // return *max_element(dp.begin(),dp.end());
        //TC: O(n*n)
        //SC: O(n)
        
        return ans;
        //TC: O(n*n)
        //SC: O(n)
    }
};