class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i=0;
        int val=nums[i];
        
        int j=i+1;
        
        while(j<nums.size())
        {
            if(nums[j]==val)
            {
                j++;
            }
            else 
            {
                nums[++i]=nums[j];
                val=nums[j];
                j++;
            }
        }
        
        return i+1;
    }
};