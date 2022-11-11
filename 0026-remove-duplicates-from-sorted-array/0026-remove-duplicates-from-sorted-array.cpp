class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int k=1;
        int i=0;
        
        int j=i;
        
        while(j<nums.size())
        {
            if(nums[i]==nums[j])
            {
                j++;
            }
            else
            {
                nums[++i]=nums[j];
                k++;
            }
        }
        
        return k;
    }
};