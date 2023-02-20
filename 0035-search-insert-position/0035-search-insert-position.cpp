class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        // if(nums[nums.size()-1]<target)
        // {
        //     return nums.size();
        // }
        
        // if(nums[0]>target)
        // {
        //     return 0;
        // }
        
        int low=0;
        int high=nums.size()-1;
        
        int mid;
        
        while(low<high)
        {
            mid=(low+high)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        
        mid=(low+high)/2;
        
        return nums[mid]<target?mid+1:mid;
    }
};