class Solution {
public:
    int maxSubArray(vector<int>& nums) //kadane's algorithm
    {
        int sum=0;
        int maxim=nums[0];
        // maxim=INT_MIN;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum=sum+nums[i];
            maxim=max(maxim,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        
        return maxim;
    }
};