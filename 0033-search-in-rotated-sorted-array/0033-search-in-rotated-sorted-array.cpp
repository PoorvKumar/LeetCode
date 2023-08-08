class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==1)
        {
            return nums[0]==target?0:-1;
        }
        
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        
        while(low<high)
        {
            if(nums[mid]>=nums[low])
            {
                if(mid+1<nums.size() && nums[mid]>nums[mid+1])
                {
                    break;
                }
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            mid=(low+high)/2;
        }
        
        int k=mid;
        // cout<<k<<endl;
        
        if(target>=nums[0])
        {
            auto it=upper_bound(nums.begin(),nums.begin()+k+1,target);
            it=prev(it);
            
            return *it==target?it-nums.begin():-1;
        }
        
        // cout<<*(nums.begin()+k+1)<<endl;
        
        if(nums.begin()+k==nums.end())
        {
            return -1;
        }
        
        auto it=upper_bound(nums.begin()+k+1,end(nums),target);
        it=prev(it);
        
        return *it==target?it-begin(nums):-1;
    }
};