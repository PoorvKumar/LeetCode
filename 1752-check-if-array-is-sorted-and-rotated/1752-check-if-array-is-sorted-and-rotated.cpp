class Solution 
{
public:
    bool check(vector<int>& nums) 
    {
        int index=-1;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1])
            {
                index=i+1;
                break;
            }
        }
        
        if(index==-1)
        {
            return true;
        }
        
        if(nums.back()>nums[0])
        {
            return false;
        }
        
        for(int i=index; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1])
            {
                return false;
            }
        }
        
        return true; 
        //TC: O(n)
        //SC: O(1)
    }
};