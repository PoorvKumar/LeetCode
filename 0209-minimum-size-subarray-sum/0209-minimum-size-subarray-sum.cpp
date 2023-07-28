class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int ans=INT_MAX;
        int sum=0;
        
        int left=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum=sum+nums[i];
            while(sum>=target)
            {
                ans=min(ans,i-left+1);
                sum=sum-nums[left++];
            }
        }
        
        return ans<INT_MAX?ans:0; //Two Pointer Approach Solution
        //TC: O(n)
        //SC: O(1)
    }
};