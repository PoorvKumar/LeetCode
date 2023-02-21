class Solution 
{
private:
    int helper(vector<int>& nums,int l,int h,int mid)
    {
        if(l>h)
        {
            return -1;
        }
        
        if(l==h)
        {
            return nums[l];
        }
        
        int left;
        int right;
        
        if(mid>0 && nums[mid-1]==nums[mid])
        {
            left=helper(nums,l,mid-2,(l+mid-2)/2);
            if(left!=-1)
            {
                return left;
            }
            
            right=helper(nums,mid+1,h,(mid+1+h)/2);
            if(right!=-1)
            {
                return right;
            }
        }
        else if(mid<nums.size()-1 && nums[mid+1]==nums[mid])
        {
            left=helper(nums,l,mid-1,(l+mid-1)/2);
            if(left!=-1)
            {
                return left;
            }
            
            right=helper(nums,mid+2,h,(mid+2+h)/2);
            if(right!=-1)
            {
                return right;
            }
        }
        else if(mid>0 || mid<nums.size()-1)
        {
            return nums[mid];
        }
        
        // return nums[mid];
        return -1;
    }
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        return helper(nums,0,nums.size()-1,(nums.size()-1)/2);
    }
};