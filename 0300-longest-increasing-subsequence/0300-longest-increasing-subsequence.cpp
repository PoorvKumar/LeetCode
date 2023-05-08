class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),1);
        
        for(int i=0; i<nums.size(); i++)
        {
            int maxim=0;
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i])
                {
                    maxim=max(maxim,dp[j]);
                }
            }
            
            dp[i]=dp[i]+maxim;
        }
        
        return *max_element(dp.begin(),dp.end());
        //TC: O(n*n)
        //SC: O(n)
    }
};