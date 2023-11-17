class Solution 
{
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),end(nums));
        
        int l=0;
        int r=nums.size()-1;
        
        int maxim=0;
        while(l<r)
        {
            maxim=max(maxim,nums[l]+nums[r]);
            l++;
            r--;
        }
        
        return maxim;
    }
};