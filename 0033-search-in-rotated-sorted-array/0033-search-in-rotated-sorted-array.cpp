class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==1)
        {
            return nums[0]==target?0:-1;
        }
        
        // if(nums.size()==2)
        // {
        //     if(nums[0]==target)
        //     {
        //         return 0;
        //     }
        //     return nums[1]==target?1:-1;
        // }
        
        int low=0;
        int high=nums.size()-1;
        
        int mid=(low+high)/2;
        
        while(low<high)
        {
            if(nums[mid]>=nums[0])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
            mid=(low+high)/2;
        }
        
        // cout<<nums[mid]<<" "<<mid<<endl;
        
        if(nums[mid]>=nums[0])
        {
            mid=0;
        }
        
        int index=mid;
        
        if(target>=nums[0])
        {
            if(index==0)
            {
                index=nums.size();
            }
            vector<int>::iterator it=upper_bound(begin(nums),begin(nums)+index,target);
            if(it==nums.begin() || *prev(it)!=target)
            {
                // cout<<*prev(it)<<endl;
                return -1;
            }
            
            return it-nums.begin()-1;
        }
        else
        {
            vector<int>::iterator it=upper_bound(begin(nums)+index,end(nums),target);
            if(it==nums.begin() || *prev(it)!=target)
            {
                return -1;
            }
            
            return it-nums.begin()-1;
        }
        
        return 0;
    }
};