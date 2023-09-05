class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // sort(nums.begin(),end(nums));
        
        int left=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            int j=i;
            while(j<nums.size() && nums[j]==nums[i])
            {
                j++;
            }
            
            nums[left++]=nums[i];
            i=j-1;
        }
        
        return left;
    }
};