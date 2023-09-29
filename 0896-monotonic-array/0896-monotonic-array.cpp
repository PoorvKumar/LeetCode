class Solution 
{
public:
    bool isMonotonic(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return true;
        }
        
        bool flag=true;
        int j=1;
        while(j<nums.size() && nums[0]==nums[j])
        {
            j++;
        }
        
        if(j>=nums.size())
        {
            return true;
        }
        
        flag=nums[0]<nums[j];
        
        for(int i=1; i<nums.size(); i++)
        {
            if(flag)
            {
                if(nums[i]<nums[i-1])
                {
                    return false;
                }
            }
            else
            {
                if(nums[i]>nums[i-1])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};