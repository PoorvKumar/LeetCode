class Solution 
{
private:
    int helper(vector<int>& nums,int val)
    {
        int i=0;
        
        while(i<nums.size())
        {
            if(nums[i]==val)
            {
                break;
            }
            i++;
        }
        
        for( ; i<nums.size(); i++)
        {
            if(nums[i]>val)
            {
                return nums[i];
            }
        }
        
        return -1;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        for(auto &x:nums1) //Brute Force Solution withoutt using Monotonic Stack
        {
            x=helper(nums2,x); //TC: O(n*m) //SC:O(n*m)
        }
        
        return nums1;
    }
};