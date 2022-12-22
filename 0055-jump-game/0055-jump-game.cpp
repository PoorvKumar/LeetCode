class Solution 
{
private:
    bool canJumpUtil(vector<int>& nums,int target)
    {
        if(target==0)
        {
            return true;
        }
        
        int i=target-1;
        
        while(i>=0)
        {
            if(nums[i]+i>=target)
            {
                return canJumpUtil(nums,i);
            }
            i--;
        }
        
        return false;
    }
public:
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        
        return canJumpUtil(nums,n-1);
    }
};